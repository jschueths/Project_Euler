//      Author: jschueths
// Description: Problem 75 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include "./libraries/algorithms.h"
#include "./libraries/timer.h"

using namespace std;

int main()
{
  unsigned int param = 1500000 + 1;
  unsigned int limit = (int) sqrt(param);
  vector<unsigned int> solutions;
  for(unsigned int i = 0; i <= 1500000; i++)
    solutions.push_back(0);
  unsigned int count = 0;
  bool overflowed = false;
  unsigned int k = 1;
  Timer my_time;
  unsigned int a, b, c;
  my_time.start();
  for(unsigned int m = 1; m <= limit; m += 2)
  {
    for(unsigned int n = 2; n < limit - m; n += 2)
    {
      if(HCF(m, n) != 1)
        continue;
      if(m > n)
        a = ((m * m) - (n * n));
      else
        a = ((n * n) - (m * m));
      b = 2 * m * n;
      c = (m * m) + (n * n);
      for(unsigned int i = a + b + c; i <= param; i += (a + b + c))
        solutions[i]++;
    }
  }
  my_time.end();
  for(unsigned int i = 0; i <= 1500000; i++)
  {
    if(solutions[i] == 1)
      count++;
  }
  cout << "Count: " << count << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  
  return 0;
}
