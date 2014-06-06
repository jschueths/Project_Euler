//      Author: jschueths
// Description: Problem 30 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <cmath>
#include "./libraries/nn_digit.h"

using namespace std;

int main()
{
  int count = 0;
  unsigned long long int sum = 0;
  unsigned long long int temp_sum = 0;
  for(int i = 2; i < 354294; i++)
  {
    temp_sum = 0;
    NN_DIGIT x(i);
    for(unsigned long long int j = 0; j < x.size(); j++)
    {
      temp_sum += pow(x[j], 5);
      if(temp_sum > i)
      {
        break;
      }
    }
    if(temp_sum == i)
      sum += i;
  }
  cout << "Sum: " << sum << endl;
  return 0;
}

