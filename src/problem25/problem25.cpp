//      Author: jschueths
// Description: Problem 25 of the Euler Project (projecteuler.net/problems)

#include <iostream>

#include "nn_digit.h"

int main()
{
  NN_DIGIT last("1");
  NN_DIGIT cur("1");
  NN_DIGIT next;
  
  unsigned int term = 2;
  
  next = cur;
  
  while(next.size() != 1000)
  {
    last = cur;
    cur = next;
    next = last + cur;
    term++;
  }
  
  std::cout << "Term: " << term << std::endl;
  return 0;
}
