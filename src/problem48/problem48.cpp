//      Author: jschueths
// Description: Problem 8 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/nn_digit.h"

using namespace std;

int main()
{
  NN_DIGIT sum(1);
  
  for(unsigned int i = 1000; i > 1; i--)
  {
    NN_DIGIT temp(i);
    temp = temp.power(i);
    sum += temp;
    cout << i << endl;
  }
  
  cout << "SUM: ";
  cout << sum;
  cout << endl;
  return 0;
}
