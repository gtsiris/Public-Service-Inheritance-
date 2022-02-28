#include <iostream>
#include <cstdlib>
#include <climits>
#include "class_Visitor.h"

using namespace std;

Visitor::Visitor() :
/* Generate random combination of floor and office as visitor's destination */
dest_floor(Random_Destination_Floor()), dest_office(Random_Destination_Office()),
priority(UINT_MAX), ready_to_leave(0)  /* The visitor initially has the worst possible priority and he is not served */
{}

const unsigned int Visitor::Random_Destination_Floor() {
  return (rand() % 4 + 1);                                                 /* Return a random number between 1 and 4 */
}
  
const unsigned int Visitor::Random_Destination_Office() {
  return (rand() % 10 + 1);                                               /* Return a random number between 1 and 10 */
}

void Visitor::Set_priority(const unsigned int& priority_number) {
  priority = priority_number;                                 /* Set visitor's priority as the given priority number */
}
   
void Visitor::Set_ready_to_leave() {
  ready_to_leave = 1;                                                                      /* Mark visitor as served */
}

const unsigned int& Visitor::Get_dest_floor() const {
  return dest_floor;                                               /* Return at which floor visitor would like to go */
}
    
const unsigned int& Visitor::Get_dest_office() const {
  return dest_office;                                             /* Return at which office visitor would like to go */
}

const unsigned int& Visitor::Get_priority() const {
  return priority;                                                                  /* Return the visitor's priority */
}

const bool Visitor::Get_status() const {
  return ready_to_leave;                                                              /* Return the visitor's status */
}

const bool Visitor::operator==(const Visitor& visitor) const {
  return (this->dest_floor == visitor.dest_floor && this->dest_office == visitor.dest_office 
  && this->priority == visitor.priority && this->ready_to_leave == visitor.ready_to_leave);
                                                                   /* Return the comparison between the two visitors */
}
