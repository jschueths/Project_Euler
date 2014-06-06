//      Author: jschueths
// Description: Problem 16 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/nn_digit.h"

int main()
{
  int coeff = 2;
  NN_DIGIT my_pw_2("2");
  unsigned int sum = 0;
  for(int i = 1; i < 1000; i++)
  {
    my_pw_2 *= coeff;
  }
  for(unsigned int i = 0; i < my_pw_2.size(); i++)
  {
    sum += my_pw_2[i];
  }
  
  std::cout << "Sum: " << sum << std::endl;
  return 0;
}
