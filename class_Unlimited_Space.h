#ifndef class_Unlimited_Space_h
#define class_Unlimited_Space_h

class Unlimited_Space {
  unsigned int n;                               /* Current number of visitors in this space */
  
  public:
    Unlimited_Space();
    
    const bool Is_Empty() const;                 /* Determine if this space is empty or not */
    
    const unsigned int& Get_n() const;  /* Get the current number of visitors in this space */
    
  protected:
    
    void Enter();                                            /* A visitor enters this space */
    
    void Exit();                                              /* A visitor exits this space */
};

#endif
