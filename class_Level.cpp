#include "class_Level.h"

Level::Level(const unsigned int& level_capacity) : Limited_Space(level_capacity)  /* Initialize its nature as limited space */
{}

Entrance& Level::Get_e() {
  return e;                                                                            /* Return the entrance of this level */
}
