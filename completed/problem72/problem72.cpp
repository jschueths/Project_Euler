//      Author: jschueths
// Description: Problem 72 of the Euler Project (eulerproject.net/problems)

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
  vector<unsigned int> totient;
  for(unsigned int i = 0; i <= limit; i++)
    totient.push_back(i);
  my_time.start();
  for(unsigned int d = 2; d <= limit; d++)
  {
    if(totient[d] == d)
    {
      for(unsigned int k = d; k <= limit; k += d)
        totient[k] = totient[k] / d * (d - 1);
    }
    count += totient[d];
  }
  my_time.end();
  cout << "Total Fractions: " << count << endl;
  cout << "Elapsed Time: " << my_time << endl;
  return 0;
}
