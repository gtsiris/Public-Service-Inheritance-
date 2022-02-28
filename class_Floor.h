#ifndef class_Floor_h
#define class_Floor_h

#include "class_Level.h"
#include "class_Entrance.h"
#include "class_Office.h"
#include "class_Visitor.h"

class Floor :public Level {
  Office o[10];    /* Floor has ten offices: o[0] -> first office, o[1] -> second office, etc... */
  const unsigned int f_num;           /* The number of this floor (eg. f_num = 1 -> first floor) */
  
  public:
    Floor(const unsigned int& floor_number, const unsigned int& capacity, const unsigned int& floor_capacity, const unsigned int& ground_capacity, const unsigned int& office_capacity);
    
    ~Floor();
    
    const bool Enter(Visitor& visitor);  /* A visitor enters the floor, if there is enough space */
    
    Visitor& Exit();                       /* A randomly selected served visitor exits the floor */
};

#endif
