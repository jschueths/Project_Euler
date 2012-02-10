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
  unsigned long long int limit = (num / 2) + 1;
  unsigned long long int temp = 6;
  unsigned long long int i = 3;
  while(temp < limit)
  {
    if(is_prime(temp) && !(num % temp))
      largest_prime = temp;
    temp++;
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
