#include <iostream>
#include "class_Building.h"

using namespace std;

Building::Building(const unsigned int& capacity, const unsigned int& floor_capacity, const unsigned int& ground_capacity, const unsigned int& office_capacity, const unsigned int& lift_capacity) :
l(office_capacity, lift_capacity), g(capacity, ground_capacity),
/* Extended initilizer list only availiable with C++11 */
f{Floor(1, capacity, floor_capacity, ground_capacity, office_capacity), Floor(2, capacity, floor_capacity, ground_capacity, office_capacity), 
  Floor(3, capacity, floor_capacity, ground_capacity, office_capacity), Floor(4, capacity, floor_capacity, ground_capacity, office_capacity)},
Limited_Space(capacity)                                                                              /* Initialize its nature as limited space */
{
  cout << "A new building is ready for serving citizens!" << endl << endl;
}

Building::~Building() {
  cout << endl << "Service not available any longer. Go elsewhere!" << endl << endl;
}

const bool Building::Enter(Visitor& visitor) {
  if (!this->Is_Full()) {                                                                    /* Check if there is enough space in the building */
    if (g.Enter(visitor)) {                                                   /* Visitor must access the ground in order to enter the building */
      this->Unlimited_Space::Enter();                                          /* Increase by 1 the current number of visitors in the building */
      g.Wait(visitor);                                                                                    /* Give a priority number to visitor */
      return 1;                                                                                   /* Visitor entered the building successfully */
    }
  }
  cout << "Please, come tomorrow" << endl;
  return 0;                                                                                             /* Visitor couldn't enter the building */
}

void Building::Exit(const Visitor& visitor) {
  cout << "I cannot believe I finished! " << visitor.Get_priority() << endl;
  g.Exit(visitor);                                                              /* Visitor must leave the ground in order to exit the building */
  this->Limited_Space::Exit();                                                         /* Decrease by 1 the number of visitors in the building */
}

void Building::Serve_Visitors() {
  l.Operate(g, f);                                                                                                     /* Execute a lift cycle */
  while(g.Get_e().Get_list().More_Visitors_Ready_To_Leave()) {    /* Served visitors exit the building in order to realease space for new ones */
    const Visitor& visitor_ready_to_leave(g.Get_e().Get_list().Get_Visitor_Ready_To_Leave());  /* Get the served visitor with highest priority */
    this->Exit(visitor_ready_to_leave);                                                                     /* this visitor exits the building */
  }
}
