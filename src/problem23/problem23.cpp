//      Author: jschueths
// Description: Problem 23 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  unsigned long long int sum = 0;
  unsigned int limit = 28232;
  vector<bool> num(limit, false);
  vector<long long int> abundant_sums;
  for(unsigned int i = 0; i < limit; i++)
  {
    abundant_sums.push_back(i);
  }
  for(unsigned int i = 12; i < limit; i++)
  {
    if(is_abundant(i))
    {
      num[i] = true;
      for(unsigned int j = 2; (j * i) < limit; j++)
        num[i * j] = true;
    }
  }

  for(unsigned int i = 0; i < limit / 2; i++)
  {
    if(num[i])
    {
      for(unsigned int j = i; j <= limit - i; j++)
      {
        if(num[j])
          abundant_sums[i + j] = 0;
      }
    }
  }
  
  for(unsigned int i = 0; i < limit; i++)
    sum += abundant_sums[i];
  cout << "Sum: " << sum << endl;
  return 0;
}
