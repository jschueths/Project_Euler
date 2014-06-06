//      Author: jschueths
// Description: Problem 53 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"


using namespace std;

int main()
{
  Timer my_time;
  unsigned long long int count = 0;
  long long int limit = 1000000;
  unsigned long long int pascal_t[101][101];
  pascal_t[0][0] = 1;
  for(unsigned int i = 1; i < 101; i++)
  {
    for(unsigned int j = 0; j <= i; j++)
    {
      if(j == 0 || j == i)
        pascal_t[i][j] = 1;
      else
        pascal_t[i][j] = pascal_t[i - 1][j - 1] + pascal_t[i - 1][j];
    }
  }

  my_time.start();
  for(unsigned int i = 1; i < 101; i++)
  {
    for(unsigned int j = 1; j <= i; j++)
    {
      if(pascal_t[i][j] >= limit)
        count++;
    }
  }
  my_time.end();
  
  cout << "Result: " << count << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}
