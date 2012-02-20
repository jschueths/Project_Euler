//      Author: jschueths
// Description: Problem 142 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <cmath>
#include <string>

#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  string input;
  unsigned int old_limit = 3;
  unsigned int limit = 1000;
  unsigned int m_x, m_y, m_z;
  bool found = false;
  cout << boolalpha << is_perfect_square(4) << endl;
  cout << boolalpha << is_perfect_square(7) << endl;
  cout << boolalpha << is_perfect_square(16) << endl;
  do
  {
    for(unsigned int x = old_limit; x < limit; x++)
    {
      for(unsigned int y = 2; y < x; y++)
      {
        bool is_squared = true;
        if(!is_perfect_square(x + y))
          is_squared = false;
        if(!is_perfect_square(x - y))
          is_squared = false;
        if(is_squared)
        {
          for(unsigned int z = 1; z < y; z++)
          {
            if(!is_perfect_square(x + z))
              is_squared = false;
            if(!is_perfect_square(x - z))
              is_squared = false;
            if(!is_perfect_square(y + z))
              is_squared = false;
            if(!is_perfect_square(y - z))
              is_squared = false;
            if(is_squared)
            {
              cout << "Smallest: " << x + y + z << endl;
              found = true;
            }
          }
        }
      }
    }
    cout << limit << endl;
    old_limit = limit;
    limit += 10000;
  }while(!found);
  return 0;
}
