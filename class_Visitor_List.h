#ifndef class_Visitor_List_h
#define class_Visitor_List_h

#include "class_Visitor.h"

class Visitor_List {
  struct Visitor_List_Node {
    Visitor& v;                                                                  /* Reference to the visitor */
    Visitor_List_Node* next_visitor;                       /* Points the next node in the list, if it exists */
    
    Visitor_List_Node(Visitor& visitor);
  };
  
  Visitor_List_Node* head;                             /* Points the node of the first visitor, if it exists */
  
  public:
    Visitor_List();
    
    ~Visitor_List();                           /* List is not necessary anymore, so free its node one by one */
    
    const bool Is_Empty() const;                                    /* Determine if the list is empty or not */
    
    const unsigned int Size() const;                            /* Count the number of visitors in this list */
    
    void Add_Visitor(Visitor& visitor);                 /* Add the visitor to the list according to priority */
    
    void Add_Visitor_To_The_End(Visitor& visitor);                 /* Add the visitor at the end of the list */
    
    void Exclude_This_Visitor(const Visitor& visitor);                   /* Erase this visitor from the list */
    
    Visitor& Exclude_ith_Visitor(const unsigned int& i);              /* Erase the ith visitor from the list */
    
    Visitor& Get_ith_Visitor(const unsigned int& i) const;               /* Find the ith visitor of the list */
    
    const bool More_Visitors_With_This_Destination_Office(const unsigned int& office_number) const;
                        /* Determine if there are visitors in this list that would like to go to this office */
    Visitor& Exclude_Visitor_With_This_Destination_Office(const unsigned int& office_number);
                                 /* Find the first visitor of this list that would like to go to this office */
    const bool More_Visitors_Ready_To_Leave() const;  /* Determine if there are served visitors in this list */
    
    Visitor& Get_Visitor_Ready_To_Leave() const;               /* Find the first served visitor of this list */
};

#endif