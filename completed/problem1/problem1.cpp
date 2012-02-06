//      Author: jschueths
// Description: Problem 1 of the Euler Project (projecteuler.net/problems)

#include <iostream>

int main()
{
  int sum = 0;
  for(int i = 0; i < 1000; i++)
  {
    if((!(i % 3) || !(i % 5)))
      sum += i;
  }
  std::cout << "The sum of all the natural numbers below one thousand that are multiples of 3 or 5" << std::endl;
  std::cout << "Sum: " << sum << std::endl;
  
  return 0;
}
