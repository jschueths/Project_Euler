//      Author: jschueths
// Description: Problem 45 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/timer.h"

using namespace std;

long long int triangle(long long int n);
long long int pentagonal(long long int n);
long long int hexagonal(long long int n);

int main()
{
  long long int n = 285;
  long long int t;
  long long int p;
  long long int h;
  bool found = false;
  Timer my_time;
  
  my_time.start();
  while(!found)
  {
    n++;
    t = triangle(n);
    for(long long int i = 166; i < n; i++)
    {
      p = pentagonal(i);
      if(t == p)
      {
        for(long long int j = 144; j < i; j++)
        {
          h = hexagonal(j);
          if(h == t)
          {
            found = true;
            my_time.end();
          }
        }
      }
    }
  }
  
  cout << "Result: " << t << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}

long long int triangle(long long int n)
{
  return ((n * (n + 1)) / 2);
}

long long int pentagonal(long long int n)
{
  return ((n * ((3 * n) - 1)) / 2);
}

long long int hexagonal(long long int n)
{
  return (n * ((2 * n) - 1));
}
