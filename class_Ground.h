#ifndef class_Ground_h
#define class_Ground_h

#include "class_Level.h"
#include "class_Visitor.h"
#include "class_Entrance.h"

class Ground :public Level {
  unsigned int priority_counter;  /* Depending on when a visitor entered the building gets a unique priority number */
  
  public:
    Ground(const unsigned int& capacity, const unsigned int& ground_capacity);
    
    ~Ground();
    
    const bool Enter(Visitor& visitor);                    /* A visitor enters the ground, if there is enough space */
    
    void Exit(const Visitor& visitor);                                                /* A visitor exits the ground */
    
    void Wait(Visitor& visitor);                           /* A visitor waits for the lift and gets priority number */
};

#endif
