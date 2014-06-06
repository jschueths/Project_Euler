//      Author: jschueths
// Description: Problem 31 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include "./libraries/timer.h"

#define TARGET 200


using namespace std;

int main()
{

  Timer my_time;
  unsigned int coin[]= {1, 2, 5, 10, 20, 50, 100, 200};
  vector<unsigned int> ways(TARGET + 1, 0);  
  ways[0] = 1;
  
  
  my_time.start();
  for(unsigned int i = 0 ; i < 8; i++)
  {
    for(unsigned int j = coin[i]; j < TARGET + 1; j++)
      ways[j] += ways[j - coin[i]];
  }
  my_time.end();
  
  cout << "Result: " << ways[TARGET] << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}

  