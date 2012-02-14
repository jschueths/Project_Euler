//      Author: jschueths
// Description: Problem 142 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <cmath>

using namespace std;

bool is_square(unsigned int x);

int main()
{
  unsigned int limit = 10000;
  unsigned int m_x, m_y, m_z;
  bool found = false;
  for(unsigned int x = 3; x < limit, !found; x++)
  {
    for(unsigned int y = 2; y < x, !found; y++)
    {
      bool is_squared = true;
      for(unsigned int z = 1; z < y, !found; z++)
      {
        if(!is_square(x + y))
          is_squared = false;
        if(!is_square(x - y))
          is_squared = false;
        if(!is_square(x + z))
          is_squared = false;
        if(!is_square(x - z))
          is_squared = false;
        if(!is_square(y + z))
          is_squared = false;
        if(!is_square(y - z))
          is_squared = false;
        if(is_squared)
        {
          cout << "Smallest: " << x + y + z << endl;
          found = true;
        }
      }
    }
  }
  return 0;
}

bool is_square(unsigned int x)
{
  for(unsigned int i = sqrt(x) - 2; i < sqrt(x) + 2; i++)
  {
    if((i * i) == x)
      return true;
  }
  return false;
}
