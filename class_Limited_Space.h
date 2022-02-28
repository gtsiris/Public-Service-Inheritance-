#ifndef class_Limited_Space_h
#define class_Limited_Space_h

#include "class_Unlimited_Space.h"

class Limited_Space :public Unlimited_Space {
  const unsigned int N;        /* Maximum number of visitors in this space */
  
  public:
    Limited_Space(const unsigned int& capacity);
    
    const bool Is_Full() const;  /* Determine if this space is full or not */
  
  protected:
    const bool Enter();  /* A visitor enters this space, if it is not full */
};

#endif
