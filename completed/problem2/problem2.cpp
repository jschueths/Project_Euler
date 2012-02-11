//      Author: jschueths
// Description: Problem 2 of the Euler Project (projecteuler.net/problems)

#include <iostream>

int main()
{
  long int sum;
  long int last_val;
  long int cur_val = 1;
  long int next_val = 2;
  
  sum = next_val;
  
  while(next_val < 4000000)
  {
    last_val = cur_val;
    cur_val = next_val;
    next_val = cur_val + last_val;
    if(!(next_val % 2))
      sum += next_val;
  }
  
  std::cout << "Sum: " << sum << std::endl;
  return 0;
}
