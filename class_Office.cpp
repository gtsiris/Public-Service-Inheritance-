#include <iostream>
#include <cstdlib>
#include "class_Office.h"

using namespace std;

Office::Office(const unsigned int& office_number, const unsigned int& floor_capacity, const unsigned int& office_capacity) :
o_num(office_number), Limited_Space(office_capacity < floor_capacity ? office_capacity : 0)     /* Initialize its nature as limited space */
{
  cout << "Office number" << office_number << " has been created" << endl;
}

Office::~Office() {
  cout << "End of the work!" << endl;
}

const bool Office::Enter(Visitor& visitor) {
  if (this->Limited_Space::Enter()) {                                                     /* Check if there is enough space in the office */
    cout << "Entering office number" << visitor.Get_dest_office() << " " << visitor.Get_priority() << endl;
    list.Add_Visitor(visitor);                                                                            /* Add visitor to office's list */
    return 1;                                                                                  /* Visitor entered the office successfully */
  }
  cout << "Please, wait outside for entrance in office number" << visitor.Get_dest_office() << " " << visitor.Get_priority() << endl;
  return 0;                                                                                          /* Visitor couldn't enter the office */
}

Visitor& Office::Exit() {
  Visitor& visitor_ready_to_leave(list.Exclude_ith_Visitor(rand() % this->Get_n() + 1));
                                                                              /* Erase a randomly selected visitor from the office's list */
  visitor_ready_to_leave.Set_ready_to_leave();                                                                      /* Mark him as served */
  this->Limited_Space::Exit();                                                      /* Decrease by 1 the number of visitors in the office */
  return visitor_ready_to_leave;                                                                             /* Return the served visitor */
}
