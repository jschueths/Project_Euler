//      Author: jschueths
// Description: Implementation of mathematical algorithms.

#include "algorithms.h"

bool is_prime(unsigned long long int x)
{
  unsigned long long int i = 1;
  if(x == 2 || x == 3)
    return true;
  if(!(x % 2) || !(x % 3) || !x || x == 1)
    return false;
  while((6 * i) - 1 < sqrt(x) + 1)
  {
    if(!(x % ((6*i) + 1)))
      return false;
    if(!(x % ((6*i) - 1)))
      return false;
    i++;
  }
  return true;
}