#ifndef class_Building_h
#define class_Building_h

#include "class_Limited_Space.h"
#include "class_Lift.h"
#include "class_Ground.h"
#include "class_Floor.h"
#include "class_Visitor.h"

class Building :public Limited_Space {
  Lift l;                                                                                                     /* Building has a lift */
  Ground g;                                                                                                 /* Building has a ground */
  Floor f[4];  /* Building has four more floors: f[0] -> first floor, f[1] -> second floor, f[2]-> third floor, f[3] -> fourth floor */
  
  public:
    Building(const unsigned int& capacity, const unsigned int& floor_capacity, const unsigned int& ground_capacity, const unsigned int& office_capacity, const unsigned int& lift_capacity);
    
    ~Building();
    
    const bool Enter(Visitor& visitor);                                   /* A visitor enters the building, if there is enough space */
    
    void Exit(const Visitor& visitor);                                                               /* A visitor exits the building */
    
    void Serve_Visitors();                                    /* Execute a lift cycle, serve visitors and release space for new ones */
};

#endif
