#include <iostream>
#include <cstdlib>
#include <ctime>
#include "class_Building.h"
#include "class_Visitor.h"
#include "class_Visitor_List.h"

using namespace std;

int main(int argc, char** argv) {
/* Get the arguments from command line as parameters */
  const unsigned int N = atoi(argv[1]), Nf = atoi(argv[2]), Ng = atoi(argv[3]), No = atoi(argv[4]), Nl = atoi(argv[5]), K = atoi(argv[6]), L = atoi(argv[7]);
  srand(time(NULL));                                                                              /* Initialize the seed using the function time */
  Building public_service(N, Nf, Ng, No, Nl);                                                 /* Create a building according to these parameters */
  Visitor visitors[K];                                                                             /* Create K visitors with random destinations */
  Visitor_List waiting_list;                                                       /* Waiting list for visitors that couldn't enter the building */
  for (unsigned int visitor_counter = 1; visitor_counter <= K; visitor_counter++) {
    if (!public_service.Enter(visitors[visitor_counter - 1])) {                                   /* Each visitor attempts to enter the building */
      waiting_list.Add_Visitor_To_The_End(visitors[visitor_counter - 1]);       /* Add visitors that couldn't enter the building to waiting list */
    }
  }
  for (unsigned int lift_cycles = 1; lift_cycles <= L; lift_cycles++) {                             /* Execute as many lift cycles as determined */
    public_service.Serve_Visitors();                                      /* Execute a lift cycle, serve visitors and release space for new ones */
    unsigned int size_of_waiting_list = waiting_list.Size();                                      /* Count how many visitors are in waiting list */
    if (size_of_waiting_list == 0)                                   /* If waiting list is empty, then no more visitors won't enter the building */
      continue;                                                                                                     /* Go to the next lift cycle */
    for (unsigned int visitor_counter = 1, visitor_position = 1; visitor_counter <= size_of_waiting_list; visitor_counter++) {
      if(public_service.Enter(waiting_list.Get_ith_Visitor(visitor_position))) {  /* Each visitor in waiting list attempts to enter the building */
        waiting_list.Exclude_This_Visitor(waiting_list.Get_ith_Visitor(visitor_position));  /* If he can enter, then erase him from waiting list */
                          /* In this case don't increase the position, because the next visitor will appear at the same position of waiting list */
      }
      else
        visitor_position++;                                   /* If he can't enter, then increase the position in order to find the next visitor */
    }
  }
  return 0;
}
