#include <iostream>
#include "class_Entrance.h"

using namespace std;

Entrance::Entrance()             /* Default initialization of its nature as unlimited space */
{
  cout << "The Entrance has been created!" << endl;
}

Entrance::~Entrance() {
  cout << "End of waiting people!" << endl << endl;
}

Visitor_List& Entrance::Get_list() {
  return list;                                           /* Return the list of the entrance */
}

void Entrance::Enter(Visitor& visitor) {
  list.Add_Visitor(visitor);                 /* Add the visitor to the list of the entrance */
  this->Unlimited_Space::Enter();   /* Increase by 1 the number of visitors in the entrance */
}

void Entrance::Exit(const Visitor& visitor) {
  list.Exclude_This_Visitor(visitor);    /* Erase the visitor from the list of the entrance */
  this->Unlimited_Space::Exit();    /* Decrease by 1 the number of visitors in the entrance */
}
