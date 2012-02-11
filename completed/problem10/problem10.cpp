//      Author: jschueths
// Description: Problem 10 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  unsigned int i = 1;
  unsigned long long int sum = 0;
  for(i; i <= 2000000; i++)
  {
    if(is_prime(i))
    {
      sum += i;
    }
  }
  
  cout << "Sum of Primes: " << sum << endl;
  return 0;
}
