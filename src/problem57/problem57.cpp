//      Author: jschueths
// Description: Problem 57 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <string>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  Timer my_time;
  unsigned long long int num;
  unsigned long long int denom;
  unsigned long long int p_num = 7;
  unsigned long long int p_denom = 5;
  unsigned long long int p_p_num = 3;
  unsigned long long int p_p_denom = 2;
  
  unsigned long long int count = 0;
  string s_num;
  string s_denom;
  
  bool swap = false;

  my_time.start();
  
  // As we can see, the first time it happens is at the 8th expansion, and then happens at either the 5th or 8th afterwards, so just count up while switching.
  for(unsigned int i = 8; i <= 1000;)
  {
    count++;
    if(swap)
    {
      i += 8;
      swap = false;
    }
    else
    {
      i += 5;
      swap = true;
    }
  }
  my_time.end();
  
  cout << "Solution: " << count << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}
