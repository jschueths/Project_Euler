//      Author: jschueths
// Description: Problem 71 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <ctime>
#include <cmath>
#include "./libraries/algorithms.h"


using namespace std;

int main()
{
  clock_t start, end;
  long double lower_bound = .4;
  long double upper_bound = (3.0)/(7.0);
  unsigned int closest[2];
  closest[0] = 2;
  closest[1] = 5;
  start = clock();
  for(unsigned int d = 2; d <= 1000000; d++)
  {
    for(unsigned int n = floor(lower_bound * d); n < d; n++)
    {
      long double temp = ((long double) n / (long double) d);
      if(temp > lower_bound && temp <= upper_bound && HCF(n, d) == 1)
      {
        if(temp > ((long double) closest[0] / (long double) closest[1]))
        {
          closest[0] = n;
          closest[1] = d;
          lower_bound = temp;
        }
      }
      else if(temp > upper_bound)
      {
        break;
      }
      else
      {
        continue;
      }
    }
  }
  end = clock();
  cout << "Closest on left: " << closest[0] << " / " << closest[1] << endl;
  cout << "Elapsed time: " << ((double) end - start) / CLOCKS_PER_SEC << " seconds" << endl;
  return 0;
}
