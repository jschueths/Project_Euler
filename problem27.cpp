//      Author: jschueths
// Description: Problem 27 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/algorithms.h"

using namespace std;

unsigned long long int equation(unsigned long long int i, long long int a, long long int b);

int main()
{
  long long int product, cur_a, cur_b;
  unsigned long int max_count = 0;
  unsigned long int count = 0;
  unsigned long long int n = 0;
  bool changed = false;
  
  for(long long int b = 0; b < 1000; b++)
  {
    
    for(long long int a = 1; a < 1000; a++)
    {
      if(is_prime(b))
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
          cur_a = a;
          cur_b = b;
          changed = true;
        }
        
        if(changed)
        {
          changed = false;
          cout << "Max count: " << max_count << endl;
          cout << "a = " << cur_a << ", b = " << cur_b << endl;
          cout << "Product: " << product << endl;
        }
        
        count = 0;
        n = 0;
        if(a < b)
        {
          while(is_prime(equation(n, -a, b)))
          {
            count++;
            n++;
          }
          if(count > max_count)
          {
            max_count = count;
            product = a * b;
            cur_a = a;
            cur_b = b;
            changed = true;
          }
        }
        else
        {
          while(is_prime(equation(n, a, -b)))
          {
            count++;
            n++;
          }
          if(count > max_count)
          {
            max_count = count;
            product = a * b;
            cur_a = a;
            cur_b = b;
            changed = true;
          }
        }
        
        if(changed)
        {
          changed = false;
          cout << "Max count: " << max_count << endl;
          cout << "a = " << cur_a << ", b = " << cur_b << endl;
          cout << "Product: " << product << endl;
        }
      }
    }
  }
  cout << "Product: " << product << endl;
  return 0;
}

unsigned long long int equation(unsigned long long int i, long long int a, long long int b)
{
  return ((i * i) + (a * i) + b);
}
