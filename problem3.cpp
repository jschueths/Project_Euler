//      Author: jschueths
// Description: Problem 3 of the Euler Project (projecteuler.net/problems)

#include <iostream>

bool is_prime(long double x);

int main()
{
  long double num = 600851475143;
  long double largest_prime;
  
  for(long double i = num - 1; i > 2; i--)
  {
    if(!(num % i))
    {
      if(is_prime(i))
      {
        largest_prime = i;
        break;
      }
    }
  }
  
  std::cout << "Largest Prime: " << largest_prime;
  return 0;
}

bool is_prime(long double x)
{
  for(long double i = x - 1; i > 1; i--)
  {
    if(!(x % i))
      return false;
  }
  return true;
}
