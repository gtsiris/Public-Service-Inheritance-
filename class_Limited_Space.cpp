#include "class_Limited_Space.h"

Limited_Space::Limited_Space(const unsigned int& capacity) :
N(capacity)                                                                        /* Default initialization of its nature as unlimited space */
{}

const bool Limited_Space::Is_Full() const {
  return (this->Get_n() == N);                   /* If the current number of visitors in this space is equal to its capacity, then it is full */
}

const bool Limited_Space::Enter() {
  if (!this->Is_Full()) {                                                                                        /* If this space is not full */
    this->Unlimited_Space::Enter();                                             /* Increase by 1 the current number of visitors in this space */
    return 1;                                                                                                 /* Visitor can enter this space */
  }
  return 0;                                                                                                /* Visitor cannot enter this space */
}
