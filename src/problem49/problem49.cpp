//      Author: jschueths
// Description: Problem 49 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <string>
#include <algorithm>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

unsigned long long int my_atoi(string x);

int main()
{
  Timer my_time;
  unsigned long long int sequence[3];
  unsigned long long int perm;
  unsigned int n, m, p;
  bool found = false;
  string s_n;
  
  my_time.start();
  for(n = 1489; n < 3340 && !found; n += 2)
  {
    m = n + 3330;
    p = n + 6660;
    if(!(is_prime(n)))
      continue;
    if(!(is_prime(m)))
      continue;
    if(!(is_prime(p)))
      continue;
    if(is_permutation(n, m) && is_permutation(n, p))
    {
      my_time.end();
      break;
    }
  }

  cout << "Result: " << n << m << p << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}

unsigned long long int my_atoi(string x)
{
  unsigned int length = x.length();
  unsigned long long int result = 0;
  unsigned long long int tens = 1;
  for(unsigned int i = length - 1; i > 0; i--)
  {
    result += (tens * (x[i] - '0'));
    tens *= 10;
  }
  result += (tens * (x[0] - '0'));
  return result;
}
