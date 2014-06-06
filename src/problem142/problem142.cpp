//      Author: jschueths
// Description: Problem 142 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <cmath>
#include "./libraries/algorithms.h"
#include "./libraries/timer.h"

using namespace std;

bool is_square(unsigned int x);

int main()
{
  Timer my_time;
  unsigned int a2, b2, c2, d2, e2, f2;
  bool found = false;
  unsigned int x = 0;
  unsigned int y = 0;
  unsigned int z = 0;
  my_time.start();
  for(unsigned int a = 10; !found; a++)
  {
    a2 = a * a;
    for(unsigned int c = 5; c < a && !found; c +=2)
    {
      c2 = c * c;
      f2 = a2 - c2;
      if(f2 < 1 || !is_perfect_square(f2))
        continue;
      for(unsigned int d = 2 + (1 & c); d < c; d += 2)
      {
        d2 = d * d;
        e2 = a2 - d2;
        if(e2 < 1 || !is_perfect_square(e2))
          continue;
        b2 = c2 - e2;
        if(b2 > 0 && is_perfect_square(b2))
        {
          x = (a2 + b2) / 2;
          y = (e2 + f2) / 2;
          z = (c2 - d2) / 2;
          found = true; 
          my_time.end();
          break;
        }
      }
      if(found)
        break;
    }
  }
  
  cout << "Smallest sum: " << x + y + z << endl;
  cout << "X: " << x << endl;
  cout << "Y: " << y << endl;
  cout << "Z: " << z << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}
