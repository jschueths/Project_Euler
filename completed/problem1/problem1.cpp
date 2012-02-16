//      Author: jschueths
// Description: Problem 1 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/timer.h"

int main()
{
  int sum = 0;
  Timer my_timer;
  my_timer.start();
  for(int i = 0; i < 1000; i++)
  {
    // If the number is a multiple of 3, 5, or both, add it to the sum.
    if((!(i % 3) || !(i % 5)))
      sum += i;
  }
  my_timer.end();
  std::cout << "The sum of all the natural numbers below one thousand that are multiples of 3 or 5" << std::endl;
  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Time Elapsed: " << my_timer << " seconds" << std::endl;
  return 0;
}
