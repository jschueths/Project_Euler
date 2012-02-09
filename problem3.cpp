//      Author: jschueths
// Description: Problem 3 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

bool is_prime(unsigned long long int x);

int main()
{
  unsigned long long int num = 600851475143;
  unsigned long long int largest_prime;
  unsigned long long int limit = num / 2;
  
  unsigned long long int i = 3;
  if(is_prime(num))
  {
    largest_prime = num;
  }
  else
  {
    while(i < limit)
    {
      if(!(num % i))
      {
        cout << "Divisible: " << i << endl;
        if(is_prime(i))
        {
          largest_prime = i;
          cout << i << endl;
        }
      }
      i = i+2;
    }
  }
  cout << "Largest Prime Factor: " << largest_prime << endl;
  return 0;
}

bool is_prime(unsigned long long int x)
{
  unsigned long long int i = 1;
  if(!(x % 2))
    return false;
  if(!(x % 3))
  while((6 * i) - 1 < sqrt(x) + 1)
  {
    if(!(x % (6*i + 1)))
      return false;
    if(!(x % (6*i - 1)))
      return false;
    i++;
  }
  return true;
}
