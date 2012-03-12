//      Author: jschueths
// Description: Problem 243 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  Timer my_time;
  unsigned int p_num = 15499;
  unsigned int p_denom = 94744;
  bool found = false;
  unsigned int resilience = 0;
  long double ratio = 15499.0/94744.0;
  long double temp;
  unsigned int denom = 1;
  
  unsigned long int limit = 2000000000;
  vector<unsigned long int> totient;
  for(unsigned long int i = 0; i <= limit; i++)
    totient.push_back(i);
  phi(totient);
  
  my_time.start();
  for(unsigned long int d = 2; d <= limit; d++)
  {
    temp = (long double) totient[d] / (long double) d;
    if(temp < ratio)
    {
      denom = d;
      break;
    }
  }
  my_time.end();
  cout << "Solution: " << denom << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}
