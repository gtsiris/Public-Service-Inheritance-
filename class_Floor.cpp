#include <iostream>
#include <cstdlib>
#include "class_Floor.h"

using namespace std;

Floor::Floor(const unsigned int& floor_number, const unsigned int& capacity, const unsigned int& floor_capacity, const unsigned int& ground_capacity, const unsigned int& office_capacity) :
/* Extended initilizer list only availiable with C++11 */
o{Office(1, floor_capacity, office_capacity), Office(2, floor_capacity, office_capacity),
  Office(3, floor_capacity, office_capacity), Office(4, floor_capacity, office_capacity),
  Office(5, floor_capacity, office_capacity), Office(6, floor_capacity, office_capacity),
  Office(7, floor_capacity, office_capacity), Office(8, floor_capacity, office_capacity),
  Office(9, floor_capacity, office_capacity), Office(10, floor_capacity, office_capacity)},
f_num(floor_number), Level(floor_capacity < capacity / 3 ? floor_capacity : 0)                                /* Initialize its nature as level */
{
  cout << "A Floor has been created with number" << floor_number << endl << endl;
}

Floor::~Floor() {
  cout << "End of service!" << endl;
}

const bool Floor::Enter(Visitor& visitor) {
  if (this->Level::Enter()) {                                                                    /* Check if there is enough space in the floor */
    cout << "Entering floor number" << f_num << " " << visitor.Get_priority() << endl;
    if (!o[visitor.Get_dest_office() - 1].Enter(visitor))                                  /* Check if visitor can enter his destination office */
      e.Enter(visitor);                                                                         /* If not, then put him in the floor's entrance */
    return 1;                                                                                         /* Visitor entered the floor successfully */
  }
  cout << "Sorry, floor number" << f_num << " is full " << visitor.Get_priority() << endl;
  return 0;                                                                                                 /* Visitor couldn't enter the floor */
}

Visitor& Floor::Exit() {
  unsigned int office_number = rand() % 10 + 1;                                                                       /* Choose a random office */
  while (o[office_number - 1].Is_Empty()) {                                                         /* Repeat until you find a non-empty office */
    office_number = office_number %  10 + 1;                                                             /* If it is empty, choose its next one */
  }
  Visitor& visitor_ready_to_leave_the_floor(o[office_number - 1].Exit());  /* A randomly selected served visitor in this office exits the floor */
  this->Level::Exit();                                                                     /* Decrease by 1 the number of visitors in the floor */
  if (e.Get_list().More_Visitors_With_This_Destination_Office(office_number)) {
                                                                     /* If there are any visitors waiting in the entrance to get in this office */
    Visitor& visitor_ready_to_get_in_the_office(e.Get_list().Exclude_Visitor_With_This_Destination_Office(office_number));
                                                                                /* The one of them with the highest priority exits the entrance */
    o[office_number - 1].Enter(visitor_ready_to_get_in_the_office);                                                   /* And enters this office */
  }
  return visitor_ready_to_leave_the_floor;                                  /* Return the randomly selected served visitors that left the floor */
}
