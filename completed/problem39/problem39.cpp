//      Author: jschueths
// Description: Problem 39 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include "./libraries/algorithms.h"
#include "./libraries/timer.h"

using namespace std;

int main()
{
  vector<unsigned int> solutions;
  for(unsigned int i = 0; i < 1001; i++)
    solutions.push_back(0);
  unsigned int max_solutions = 0;
  unsigned int max_index;
  Timer my_time;
  unsigned int a2, b2, c2;
  my_time.start();
  for(unsigned int a = 3; a < 1000; a++)
  {
    a2 = a * a;
    for(unsigned int b = 2; b < a; b++)
    {
      b2 = b * b;
      if(a + b > 1000)
        break;
      for(unsigned int c = 1; c < b; c++)
      {
        c2 = c * c;
        if(a + b + c > 1000)
          break;
        if(a2 == b2 + c2)
          solutions[a + b + c]++;
      }
    }
  }
  my_time.end();
  for(unsigned int i = 0; i < 1001; i++)
  {
    
    if(solutions[i] > max_solutions)
    {
      max_solutions = solutions[i];
      max_index = i;
    }
  }
  cout << "Best P: " << max_index << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  
  return 0;
}
