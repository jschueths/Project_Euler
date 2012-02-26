//      Author: jschueths
// Description: Problem 81 of the Euler Project (projecteuler.net/problems)

#include <iostream>

using std::cout;
using std::endl;

int main()
{
  unsigned long long int path[21][21];
  
  for(int i = 0; i < 21; i++)
  {
    for(int j = 0; j < 21; j++)
    path[i][j] = 0;
  }
  path[0][0] = 1;
  path[0][1] = 1;
  path[1][0] = 1;
  
  for(int i = 0; i < 21; i++)
  {
    for(int j = 0; j < 21; j++)
    {
      if(!(i == 0 && j == 0))
      {
        if(j == 0)
        {
          path[i][j] = path[i - 1][j];
        }
        else if(i == 0)
        {
          path[i][j] = path[i][j - 1];
        }
        else
        {
          path[i][j] = path[i - 1][j] + path[i][j - 1];
        }
      }
    }
  }
  cout << endl;
  cout << "Num Paths: " << path[20][20] << endl;
  return 0;
}
