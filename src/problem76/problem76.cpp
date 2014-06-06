//      Author: jschueths
// Description: Problem 76 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include "./libraries/timer.h"

#define TARGET 100


using namespace std;

int main()
{

  Timer my_time;
  vector<unsigned int> ways(TARGET + 1, 0);  
  ways[0] = 1;
  
  
  my_time.start();
  for(unsigned int i = 1 ; i < 100; i++)
  {
    for(unsigned int j = i; j < TARGET + 1; j++)
      ways[j] += ways[j - i];
  }
  my_time.end();
  
  cout << "Result: " << ways[TARGET] << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}

  