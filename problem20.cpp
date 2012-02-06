//      Author: jschueths
// Description: Problem 20 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/nn_digit.h"

using std::string;

int main()
{
  unsigned int sum = 0;
  NN_DIGIT factorial("1");
  
  for(int i = 1; i <= 100; i++)
  {
    factorial *= i;
  }
  std::cout << factorial << std::endl;
  unsigned int fact = 100;
  for(unsigned int i = 99; i > 0; i--)
    fact *= i;
  std::cout << fact << std::endl;
  
  unsigned int length = factorial.size();
  for(unsigned int i = 0; i < length; i++)
  {
    sum += factorial[i];
  }
  
  std::cout << "Sum: " << sum << std::endl;
  return 0;
}
