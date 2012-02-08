//      Author: jschueths
// Description: Problem 8 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/nn_digit.h"

using namespace std;

int main()
{
  NN_DIGIT sum(1);
  
  for(unsigned int i = 2; i < 1001; i++)
  {
    NN_DIGIT temp(i);
    temp = temp.power(i);
    sum += temp;
  }
  
  cout << "Last 10 Digits: ";
  for(unsigned int i = sum.size() - 10; i < sum.size(); i++)
    cout << sum[i];
  cout << endl;
  return 0;
}
