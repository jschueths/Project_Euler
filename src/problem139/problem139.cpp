//      Author: jschueths
// Description: Problem 139 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include <cmath>
#include "./libraries/algorithms.h"
#include "./libraries/timer.h"

using namespace std;

int main()
{

  unsigned long long int count = 0;
  Timer my_time;
  long long int a, b, c;
  my_time.start();
  unsigned long long int m, n;
  unsigned long long int limit = 100000000;
  unsigned long long int perimeter;
  bool done = false;
  
  m = 1;
  
  while(!done)
  {
    m += 2;
    for(unsigned int n = 1; n < m; n += 2)
    {
      if(HCF(m, n) != 1)
        continue;
      a = m * n;
      b = ((m * m) - (n * n)) / 2;
      c = ((m * m) + (n * n)) / 2;
      perimeter = a + b + c;
      if(c % abs(a - b) == 0 && (a + b + c) < 100000000)
        count += limit / perimeter;
      if(a + b + c > limit && n == 1)
      {
        done = true;
        break;
      }
    }
  }
  my_time.end();
  
  cout << "Count: " << count << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  
  return 0;
}
