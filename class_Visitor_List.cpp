#include <iostream>
#include "class_Visitor_List.h"

using namespace std;

Visitor_List::Visitor_List_Node::Visitor_List_Node(Visitor& visitor) : v(visitor), next_visitor(NULL)  /* Each node is initially separate */
{}

Visitor_List::Visitor_List() : head(NULL)                                                                  /* The list is initially empty */
{}

Visitor_List::~Visitor_List() {
  Visitor_List_Node* temp0 = head;                                                                        /* Starting from the first node */
  while (temp0 != NULL) {                                                                             /* Repeat until the end of the list */
    Visitor_List_Node* temp1 = temp0;                                                             /* Save the address of the current node */
    temp0 = temp1->next_visitor;                                                                                   /* Go to the next node */
    delete temp1;                                                                              /* Delete the content of the saved address */
  }
}

const bool Visitor_List::Is_Empty() const {
  return (head == NULL);                                                         /* If there is no visitor in this list, then it is empty */
}

const unsigned int Visitor_List::Size() const {
  unsigned int size = 0;
  Visitor_List_Node* temp = head;                                                                         /* Starting from the first node */
  while (temp != NULL) {                                                                              /* Repeat until the end of the list */
    size++;                                                                                                  /* Increase the counter by 1 */
    temp = temp->next_visitor;                                                                                     /* Go to the next node */
  }
  return size;                                                                                         /* Return the value of the counter */
}

void Visitor_List::Add_Visitor(Visitor& visitor) {
  if (this->Is_Empty()) {                                                                         /* If there is no visitors in this list */
    head = new Visitor_List_Node(visitor);                                                  /* Create a new node at the start of the list */
    return;
  }
                                                                                  /* Else if there are already other visitors in the list */
  Visitor_List_Node* temp = new Visitor_List_Node(visitor);                                                          /* Create a new node */
  if (visitor.Get_priority() < (head->v).Get_priority()) {                                /* If the visitor is prior to the first visitor */
    temp->next_visitor = head;                                                                /* Add the visitor at the start of the list */
    head = temp;                                                                                          /* Update the start of the list */
    return;
  }
  if (head->next_visitor == NULL && (head->v).Get_priority() < visitor.Get_priority()) {  
                                                               /* If there is only one visitor in the list and he is prior to the visitor */
    head->next_visitor = temp;                                                                               /* Add the visitor after him */
    return;
  }
  else if ((head->v).Get_priority() < visitor.Get_priority() && visitor.Get_priority() < (head->next_visitor->v).Get_priority()) {
                                                      /* If the first visitor is prior and the second visitor is posterior to the visitor */
      temp->next_visitor = head->next_visitor;                                                            /* Add the visitor between them */
      head->next_visitor = temp;                                                                          /* Update the first node's link */
      return;
  }
  Visitor_List_Node* temp1 = head->next_visitor;                                                         /* Starting from the second node */
  while (temp1->next_visitor != NULL) {                                                  /* Repeat unless it is the last node of the list */
    if ((temp1->v).Get_priority() < visitor.Get_priority() && visitor.Get_priority() < (temp1->next_visitor->v).Get_priority()) {
                                                                    /* If there is a visitor prior and a visitor posterior to the visitor */
      temp->next_visitor = temp1->next_visitor;                                                           /* Add the visitor between them */
      break;
    }
    temp1 = temp1->next_visitor;                                                                                   /* Go to the next node */
  }
  temp1->next_visitor = temp;                                                                             /* Update the prior node's link */
}

void Visitor_List::Add_Visitor_To_The_End(Visitor& visitor) {
  if (this->Is_Empty()) {                                                                          /* If there is no visitor in this list */
    head = new Visitor_List_Node(visitor);                                                  /* Create a new node at the start of the list */
  }
  else {
    Visitor_List_Node* temp = head;                                                                       /* Starting from the first node */
    while (temp->next_visitor != NULL)                                                   /* Repeat unless it is the last node of the list */
      temp = temp->next_visitor;                                                                                       /* Go to next node */
    temp->next_visitor = new Visitor_List_Node(visitor);                                         /* Create a new node after the last node */
  }
}

void Visitor_List::Exclude_This_Visitor(const Visitor& visitor) {
  Visitor_List_Node* temp0 = head, * temp1 = head->next_visitor;
  if (temp0->v == visitor) {                                                                          /* If this visitor is the first one */
    delete temp0;                                                                                                /* Delete the first node */
    head = temp1;                                              /* Update the start of the list using the saved address of the second node */
    return;
  }
  while (!(temp1->v == visitor)) {                                                                   /* Repeat until you find the visitor */
    temp0 = temp1;                                                                                        /* Save the address of the node */
    temp1 = temp1->next_visitor;                                                                                   /* Go to the next node */
  }
  temp0->next_visitor = temp1->next_visitor;                                /* Skip this node using the saved address of its previous one */
  delete temp1;                                                                                                       /* Delete this node */
}

Visitor& Visitor_List::Exclude_ith_Visitor(const unsigned int& i) {
  Visitor_List_Node* temp0 = head, * temp1 = head->next_visitor;
  unsigned int pos = 1;
  if (i == 1) {                                                                           /* In case we want to exclude the first visitor */
    Visitor& visitor(temp0->v);                                            /* Keep a reference to the first visitor in order to return it */
    delete temp0;                                                                                                /* Delete the first node */
    head = temp1;                                                                 /* Update the start of the list using the saved address */
    return visitor;                                                                                           /* Return the first visitor */
  }
  while (++pos < i) {                                                                           /* Repeat untill you find the ith visitor */
    temp0 = temp1;                                                                                        /* Save the address of the node */
    temp1 = temp1->next_visitor;                                                                                   /* Go to the next node */
  }
  Visitor& visitor(temp1->v);                                                /* Keep a reference to the ith visitor in order to return it */
  temp0->next_visitor = temp1->next_visitor;                             /* Skip the ith node using the saved address of its previous one */
  delete temp1;                                                                                                    /* Delete the ith node */
  return visitor;                                                                                               /* Return the ith visitor */
}

Visitor& Visitor_List::Get_ith_Visitor(const unsigned int& i) const {
  Visitor_List_Node* temp = head;                                                                         /* Starting from the first node */
  unsigned int pos = 1;
  while (pos++ < i) {                                                                           /* Repeat untill you find the ith visitor */
    temp = temp->next_visitor;                                                                                     /* Go to the next node */
  }
  return temp->v;                                                                                               /* Return the ith visitor */
}

const bool Visitor_List::More_Visitors_With_This_Destination_Office(const unsigned int& office_number) const {
  Visitor_List_Node* temp = head;                                                                         /* Starting from the first node */
  while (temp != NULL) {                                                                              /* Repeat until the end of the list */
    if (temp->v.Get_dest_office() == office_number)                                    /* If this visitor would like to go to this office */
      return 1;                                                                /* Then atleast one visitor has this office as destination */
    temp = temp->next_visitor;                                                                                         /* Go to next node */
  }
  return 0;                                                         /* No visitor found in this list that would like to go to this office */
}

Visitor& Visitor_List::Exclude_Visitor_With_This_Destination_Office(const unsigned int& office_number) {
  Visitor_List_Node* temp0 = head, * temp1 = head->next_visitor;
  if (temp0->v.Get_dest_office() == office_number) {                               /* If the first visitor has this office as destination */
    Visitor& visitor (temp0->v);                                               /* Keep a reference to first visitor in order to return it */
    delete temp0;                                                                                                /* Delete the first node */
    head = temp1;                                                                                         /* Update the start of the list */
    return visitor;                                                                                           /* Return the first visitor */
  }
  while (temp1->v.Get_dest_office() != office_number) {        /* Find the first visitor in the list that would like to go in this office */
    temp0 = temp1;                                                                                        /* Save the address of the node */
    temp1 = temp1->next_visitor;                                                                                   /* Go to the next node */
  }
  Visitor& visitor (temp1->v);                                                  /* Keep a reference to this visitor in order to return it */
  temp0->next_visitor = temp1->next_visitor;                                /* Skip this node using the saved address of its previous one */
  delete temp1;                                                                                                       /* Delete this node */
  return visitor;                                                                                                  /* Return this visitor */
}

const bool Visitor_List::More_Visitors_Ready_To_Leave() const {
  Visitor_List_Node* temp = head;                                                                         /* Starting from the first node */
  while (temp != NULL) {                                                                              /* Repeat until the end of the list */
    if (temp->v.Get_status())                                                                             /* If a served visitor is found */
      return 1;                                                               /* There is atleast one visitor in this list ready to leave */
    temp = temp->next_visitor;                                                                                     /* Go to the next node */
  }
  return 0;                                                                                    /* There is no served visitor in this list */
}

Visitor& Visitor_List::Get_Visitor_Ready_To_Leave() const {
  Visitor_List_Node* temp = head;                                                                         /* Starting from the first node */
  while (temp != NULL) {                                                                              /* Repeat until the end of the list */
    if (temp->v.Get_status())                                                                             /* If a served visitor is found */
      return temp->v;                                                                                              /* Return this visitor */
    temp = temp->next_visitor;                                                                                     /* Go to the next node */
  }
}
