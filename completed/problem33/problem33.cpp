//      Author: jschueths
// Description: Problem 33 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/algorithms.h"
#include "./libraries/timer.h"

using namespace std;

int main()
{
  Timer my_time;
  unsigned int denom_product = 1;
  unsigned int num_product = 1;
  unsigned int num[2];
  unsigned int denom[2];
  unsigned int factor;
  
  my_time.start();
  for(unsigned int i = 11; i < 100; i++)
  {
    for(unsigned int j = 11; j < i; j++)
    {
      if(!(i % 10) && !(j % 10))
        continue;
      denom[0] = (i / 10) % 10;
      denom[1] = i % 10;
      num[0] = (j / 10) % 10;
      num[1] = j % 10;
      
      if(num[0] * i == denom[0] * j && num[1] == denom[1])
      {
        denom_product *= i;
        num_product *= j;
      }
      if(num[1] * i == denom[1] * j && num[0] == denom[0])
      {
        denom_product *= i;
        num_product *= j;
      }
      if(num[1] * i == denom[0] * j && num[0] == denom[1])
      {
        denom_product *= i;
        num_product *= j;
      }
      if(num[0] * i == denom[1] * j && num[1] == denom[0])
      {
        denom_product *= i;
        num_product *= j;
      }
    }
  }
  my_time.end();
  
  factor = gcd(num_product, denom_product);
  while(factor != 1)
  {
    num_product /= factor;
    denom_product /= factor;
    factor = gcd(num_product, denom_product);
  }
  
  cout << "Result: " << denom_product << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}
