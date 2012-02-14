//      Author: jschueths
// Description: Problem 35 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/algorithms.h"

using namespace std;

bool is_circular(unsigned int x);

int main()
{
  unsigned int count = 0;
  unsigned int limit = 1000000;
  for(unsigned int i = 2; i < limit; i++)
  {
    if(is_prime(i))
    {
      if(is_circular(i))
        count++;
    }
  }
  cout << "Num circular primes: " << count << endl;
  return 0;
}

bool is_circular(unsigned int x)
{
  string prime = convert_to_string(x);
  char temp;
  int iterations = prime.length();
  unsigned int val;
  for(int i = 0; i < iterations; i++)
  {
    temp = prime[0];
    for(int j = 0; j < iterations - 1; j++)
      prime[j] = prime[j + 1];
    prime[iterations - 1] = temp;
    val = convert_to_int(prime);
    if(!is_prime(val))
      return false;
  }
  return true;
}