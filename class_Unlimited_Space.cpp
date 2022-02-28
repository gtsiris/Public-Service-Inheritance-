#include "class_Unlimited_Space.h"

Unlimited_Space::Unlimited_Space() :
n(0)                                          /* The space is initially empty */
{}

const bool Unlimited_Space::Is_Empty() const {
  return (n == 0);  /* If there is no visitor in this space, then it is empty */
}

const unsigned int& Unlimited_Space::Get_n() const {
  return n;            /* Return the current number of visitors in this space */
}

void Unlimited_Space::Enter() {
  n++;          /* Increase by 1 the current number of visitors in this space */
}

void Unlimited_Space::Exit() {
  n--;          /* Decrease by 1 the current number of visitors in this space */
}
