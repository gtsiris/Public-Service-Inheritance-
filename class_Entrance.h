#ifndef class_Entrance_h
#define class_Entrance_h

#include "class_Unlimited_Space.h"
#include "class_Visitor.h"
#include "class_Visitor_List.h"

class Entrance :public Unlimited_Space {
  Visitor_List list;  /* Includes all the visitors that are currently in this entrace */
  
  public:
    Entrance();
    
    ~Entrance();
    
    Visitor_List& Get_list();                         /* Get the list of the entrance */
    
    void Enter(Visitor& visitor);                    /* A visitor enters the entrance */
    
    void Exit(const Visitor& visitor);                /* A visitor exits the entrance */
};

#endif
