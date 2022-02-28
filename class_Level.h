#ifndef class_Level_h
#define class_Level_h

#include "class_Limited_Space.h"
#include "class_Visitor.h"
#include "class_Entrance.h"

class Level :public Limited_Space {
  protected:
    Entrance e;                  /* Level has an entrance */
  
  public:
    Level(const unsigned int& level_capacity);
    
    Entrance& Get_e();  /* Get the entrance of this level */
};

#endif
