//      Author: jschueths
// Description: Problem 41 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/algorithms.h"
#include "./libraries/timer.h"

using namespace std;

int main()
{
  // Since any 9 digit, 8 digit, 6 digit, and 5 digit
  // pandigitals are not prime through simple division rules,
  // try only pandigitals that can be prime. Of course since
  // a 4 digit pandigital was the example, we know that 1 digit,
  // 2 digit, and 3 digit pandigitals are out of the question, and
  // so only have to worry about 7 and 4 digit primes.
  // However most of the 4 digit pandigitals are not prime, so you
  // only have to check the six that aren't divisible by the division
  // rules for 2 to 11.
  unsigned int start = 7654321;
  unsigned int prime_pan;
  bool found = false;
  Timer my_timer;
  my_timer.start();
  for(unsigned int i = start; i >= 1234567; i -= 2) // -= 2 because we don't need to check evens
  {
    if(is_prime(i) && is_pandigital(convert_to_string(i), 1, 7))
    {
      my_timer.end();
      prime_pan = i;
      found = true;
      break;
    }
  }
  // If it didn't find a 7 digit pandigital prime
  // check the remaining 4 digit pandigitals for
  // primality.
  if(!found)
  {
    if(is_prime(1423))
    {
      my_timer.end();
      prime_pan = 1423;
    }
    if(is_prime(2143))
    {
      my_timer.end();
      prime_pan = 2143;
    }
    if(is_prime(2341))
    {
      my_timer.end();
      prime_pan = 2341;
    }
    if(is_prime(2413))
    {
      my_timer.end();
      prime_pan = 2413;
    }
    if(is_prime(4231))
    {
      my_timer.end();
      prime_pan = 2413;
    }
    if(is_prime(4321))
    {
      my_timer.end();
      prime_pan = 4321;
    }
  }
  cout << "Largest Pandigital Prime: " << prime_pan << endl;
  cout << "Time Elapsed: " << my_timer << " seconds" << endl;
  return 0;
}
  