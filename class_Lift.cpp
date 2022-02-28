#include <iostream>
#include "class_Lift.h"

using namespace std;

Lift::Lift(const unsigned int& office_capacity, const unsigned int& lift_capacity) :
current_f(0),                                                                      /* The lift is initially empty and stopped at ground floor */
Limited_Space(lift_capacity > office_capacity ? lift_capacity : 0)                                  /* Initialize its nature as limited space */
{
  cout << "A lift has been created" << endl << endl;
}
  
Lift::~Lift() {
  cout << "No more ups and downs!" << endl << endl;
}

void Lift::Operate(Ground& g, Floor (&f)[4]) {
  unsigned int visitors_in_the_ground = g.Get_n();
  for (unsigned int visitor_counter = 1, visitor_position = 1; visitor_counter <= visitors_in_the_ground; visitor_counter++) {
      if(this->Enter(g.Get_e().Get_list().Get_ith_Visitor(visitor_position)))            /* Each visitor in ground attempts to enter the lift */
        g.Exit(g.Get_e().Get_list().Get_ith_Visitor(visitor_position));                         /* If he can enter, then he leaves the ground */
                      /* In this case don't increase the position, because the next visitor will appear at the same position of ground's list */
      else
        visitor_position++;                                /* If he can't enter, then increase the position in order to find the next visitor */
  }
  this->Stop_Up(f);                                                    /* Lift goes upwards and stops at each floor so visitors can disembark */
  this->Stop_Down(f);                                                   /* Lift goes downwards and stops at each floor so visitors can embark */
  this->Empty_All(g);                                                           /* All the served visitors exit the lift and enter the ground */
}

const bool Lift::Enter(Visitor& visitor) {
  if (this->Limited_Space::Enter()) {                                                           /* Check if there is enough space in the lift */
    list.Add_Visitor(visitor);                                                                                  /* Add visitor to lift's list */
    cout << "Visitor in the lift " << visitor.Get_priority() << endl;
    return 1;                                                                                        /* Visitor entered the lift successfully */
  }
  cout << "You are not allowed to enter! " << visitor.Get_priority() << endl;
  return 0;                                                                                                /* Visitor couldn't enter the lift */
}

void Lift::Stop_Up(Floor (&f)[4]) {
  while (++current_f) {                                                                          /* Lift goes upwards and stops at each floor */
    unsigned int visitors_in_the_lift = this->Get_n();
    for (unsigned int visitor_counter = 1, visitor_position = 1; visitor_counter <= visitors_in_the_lift; visitor_counter++) {
      if (list.Get_ith_Visitor(visitor_position).Get_dest_floor() == current_f) {     /* Each visitor in the lift with this destination floor */
        if(f[current_f - 1].Enter(list.Get_ith_Visitor(visitor_position)))                                     /* attempts to enter the floor */
          this->Exit(list.Get_ith_Visitor(visitor_position));                                     /* If he can enter, then he leaves the lift */
                        /* In this case don't increase the position, because the next visitor will appear at the same position of lift's list */
        else
          visitor_position++;                              /* If he can't enter, then increase the position in order to find the next visitor */
      }
      else
        visitor_position++;             /* If a visitor has other destination floor, then increase the position in order to find the next one */
    }
    if (current_f == 4)                                                                                  /* If lift reached the highest floor */
      break;                                                                                                   /* then it stops going upwards */
  }
}

void Lift::Exit(const Visitor& visitor_ready_to_leave_the_lift) {
  list.Exclude_This_Visitor(visitor_ready_to_leave_the_lift);                                       /* Erase the visitor from the lift's list */
  this->Limited_Space::Exit();                                                            /* Decrease by 1 the number of visitors in the lift */
}

void Lift::Stop_Down(Floor (&f)[4]) {
  while(current_f) {                                                                             /* Lift stops at each floor until the ground */
    while(!this->Is_Full() && !f[current_f - 1].Is_Empty())     /* If there is enough space in the lift and atleast one visitor in this floor */
      this->Enter(f[current_f - 1].Exit());                                                  /* A visitor exits the floor and enters the lift */
    current_f--;                                                                                                      /* Lift going downwards */
  }
}

void Lift::Empty_All(Ground& g) {
  while (list.More_Visitors_Ready_To_Leave()) {                              /* Repeat until all served visitors in the lift enter the ground */
    if (g.Enter(list.Get_Visitor_Ready_To_Leave()))  /* The served visitor in the lift with the highest priority attempts to enter the ground */
      this->Exit(list.Get_Visitor_Ready_To_Leave());                                              /* If he can enter, then he leaves the lift */
    else
      break;                                               /* If there is not enough space in the ground, the rest of them remain in the lift */
  }
}
