//      Author: jschueths
// Description: Implementation of mathematical algorithms.

#include "algorithms.h"

bool is_prime(unsigned long long int &x)
{
  if(x == 2 || x == 3)
    return true;
  if(!(x % 2) || !(x % 3))
    return false;
  