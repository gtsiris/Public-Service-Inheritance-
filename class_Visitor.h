#ifndef class_Visitor_h
#define class_Visitor_h

class Visitor {
  
  const unsigned int dest_floor;                                  /* The floor that visitor would like to go in order to get served */
  const unsigned int dest_office;                                /* The office that visitor would like to go in order to get served */
  unsigned int priority;                                /*  The visitor has a priority number that shows his placing in every queue */
  bool ready_to_leave;                                                           /* Flag that shows if the visitor is served or not */
  
  const unsigned int Random_Destination_Floor();               /* Generate a random number between 1 and 4 as visitor's destination */
  
  const unsigned int Random_Destination_Office();             /* Generate a random number between 1 and 10 as visitor's destination */
  
  public:
    Visitor();
    
    void Set_priority(const unsigned int& priority_number);                  /* Set visitor's priority as the given priority number */
    
    void Set_ready_to_leave();                                                                            /* Mark visitor as served */
    
    const unsigned int& Get_dest_floor() const;                                     /* Find at which floor visitor would like to go */
    
    const unsigned int& Get_dest_office() const;                                   /* Find at which office visitor would like to go */
    
    const unsigned int& Get_priority() const;                                                        /* Find the visitor's priority */
    
    const bool Get_status() const;                                                          /* Find if the visitor is served or not */
    
    const bool operator==(const Visitor& visitor) const;  /* Compare two visitors and determine if they are the same visitor or not */
};

#endif
