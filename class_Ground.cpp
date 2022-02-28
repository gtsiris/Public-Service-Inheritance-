#include <iostream>
#include "class_Ground.h"

using namespace std;

Ground::Ground(const unsigned int& capacity, const unsigned int& ground_capacity) :
priority_counter(1), Level(ground_capacity < capacity / 2 ? ground_capacity : 0)  /* Initialize its nature as level */
                                               /* The first visitor that enters the building gets priority number 1 */
{
  cout << "A Floor has been created with number0" << endl << endl;
}

Ground::~Ground() {
  cout << "End of service!" << endl;
}

const bool Ground::Enter(Visitor& visitor) {
  if (this->Level::Enter()) {                                       /* Check if there is enough space in the ground */
    e.Enter(visitor);                                                       /* Put visitor in the ground's entrance */
    return 1;                                                            /* Visitor entered the ground successfully */
  }
  else {
    return 0;                                                                  /* Visitor couldn't enter the ground */
  }
}

void Ground::Exit(const Visitor& visitor) {
  e.Exit(visitor);                                   /* Visitor must leave the entrance in order to exit the ground */
  this->Level::Exit();                                        /* Decrease by 1 the number of visitors in the ground */
}

void Ground::Wait(Visitor& visitor) {
  visitor.Set_priority(priority_counter++);                                /* Give a unique priority to the visitor */
  cout << "Waiting for the lift " << endl;
}
