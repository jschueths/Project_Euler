//      Author: jschueths
// Description: Problem 2 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/timer.h"
int main()
{
  // Init the variables
  long int sum;
  long int last_val;
  long int cur_val = 1;
  long int next_val = 2;
  Timer my_timer;
  my_timer.start();
  sum = next_val;
  
  while(next_val < 4000000)
  {
    last_val = cur_val;
    
    // Generate the next term in the Fibonacci sequence
    cur_val = next_val;
    next_val = cur_val + last_val;
    
    // If the term is even, add it to the sum;
    if(!(next_val % 2))
      sum += next_val;
  }
  my_timer.end();
  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Time Elapsed: " << my_timer << " seconds" << std::endl;
  return 0;
}
