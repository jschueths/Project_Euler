//      Author: jschueths
// Description: Problem 69 of the Euler Project (eulerproject.net/problems)

#include "./libraries/algorithms.h"
#include "./libraries/timer.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  Timer my_time;
  unsigned long long int count = 0;
  unsigned int limit = 1000000;
  vector<unsigned long int> totient;
  long double ratio = 0;
  long double temp;
  unsigned int n;
  for(unsigned int i = 0; i <= limit; i++)
    totient.push_back(i);
  phi(totient);
  my_time.start();
  for(unsigned int d = 2; d <= limit; d++)
  {
    temp = (double) d / totient[d];
    if(temp > ratio)
    {
      ratio = temp;
      n = d;
    }
  }
  my_time.end();
  cout << "Solution: " << n << endl;
  cout << "Elapsed Time: " << my_time << " seconds" << endl;
  return 0;
}
