//      Author: jschueths
// Description: Problem 21 of the Euler Project (projecteuler.net/problems)


#include <iostream>
#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  unsigned long int sum = 0;
  for(unsigned long int i = 1; i < 10000; i++)
  {
    unsigned int d = d_amicable(i);
    if(d < 10000 && (d_amicable(d) == i) && d != i)
      sum += i;
  }
  cout << "Sum: " << sum << endl;
  return 0;
}
