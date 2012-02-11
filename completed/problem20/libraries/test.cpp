
#include <iostream>
#include "nn_digit.h"

int main()
{
  NN_DIGIT a("54");
  int b = 234;
  
  NN_DIGIT c;
  
  c = a * b;
  std::cout << c << std::endl;
  return 0;
}
