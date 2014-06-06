//      Author: jschueths
// Description: Problem 26 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <cmath>
#include "./libraries/algorithms.h"
#include "./libraries/timer.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
  Timer my_timer;
  unsigned int max_prime;
  unsigned int max_cycle = 0;
  my_timer.start();
  for(int i = 999; i > 0; i -= 2)
  {
    if(is_prime(i))
    {
      int c = 1;
      unsigned int temp = 0;
      do
      {
        while(c < i)
          c *= 10;
        c %= i;
        if(c == 0)
          break;
        temp++;
        if(temp > max_cycle)
        {
          max_prime = i;
          max_cycle = temp;
        }
      }while(c != 1);
    }
  }
  my_timer.end();
  cout << "Longest cycle denominator: " << max_prime << endl;
  cout << "Time Elapsed: " << my_timer << " seconds" << endl;
  return 0;
}
