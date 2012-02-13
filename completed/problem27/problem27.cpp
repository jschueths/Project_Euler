//      Author: jschueths
// Description: Problem 27 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/algorithms.h"

using namespace std;

long long int equation(long long int i, long long int a, long long int b);

int main()
{
  long long int product, cur_a, cur_b;
  unsigned long int max_count = 0;
  unsigned long int count = 0;
  long long int n = 0;
  bool changed = false;
  
  for(long long int b = 0; b < 1000; b++)
  {
    if(!is_prime(b))
      continue;
    for(long long int a = 1; a < 1000; a++)
    {
      count = 0;
      n = 0;
      while(is_prime(equation(n, a, b)))
      {
        count++;
        n++;
      }
      if(count > max_count)
      {
        max_count = count;
        product = a * b;
        changed = true;
      }
      count = 0;
      n = 0;
      while(equation(n, -a, b) > 0 && is_prime(equation(n, -a, b)))
      {     
        count++;
        n++;
      }
      if(count > max_count)
      {
        max_count = count;
        product = (-a) * b;
        changed = true;
      }
    }
  }
  cout << "Product: " << product << endl;
  return 0;
}

long long int equation(long long int i, long long int a, long long int b)
{
  return ((i * i) + (a * i) + b);
}
