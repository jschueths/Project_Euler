//      Author: jschueths
// Description: Problem 5 of the Euler Project (projecteuler.net/problems)

#include <iostream>

int main()
{
  long int num = 20;
  bool evenly_divisible = true;
  bool found = false;
  
  while(!found)
  {
    evenly_divisible = true;
    for(int i = 1; i < 21; i++)
    {
      if(num % i)
      {
        evenly_divisible = false;
        break;
      }
    }
    if(evenly_divisible)
      found = true;
    else
      num++;
  }
  
  std::cout << "Smallest number: " << num << std::endl;
  return 0;
}
