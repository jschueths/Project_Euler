//      Author: jschueths
// Description: Problem 46 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

void append_primes(long long int n, vector<long long int> &p);

int main()
{
  long long int odd = 1;
  bool found = false;
  vector<long long int> prime;
  prime.push_back(2);
  Timer my_time;
  long long int cur_prime;
  long long int test;
  long long s = 1;
  
  my_time.start();
  while(!found)
  {
    odd += 2;
    if(is_prime(odd))
      continue;
    append_primes(odd, prime);
    found = true;
    for(unsigned int i = 0; i < prime.size() && found; i++)
    {
      cur_prime = prime[i];
      s = 1;
      do
      {
        test = cur_prime + (2 * (s * s));
        s++;
        if(test == odd)
          found = false;
      }while(test < odd);
    }
  }
  my_time.end();
  
  cout << "Result: " << odd << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
}

void append_primes(long long int n, vector<long long int> &p)
{
  long long int x;
  if(p.size() == 0)
    x = 1;
  else
    x = p[p.size() - 1];
  x++;
  while(x < n)
  {
    if(is_prime(x))
      p.push_back(x);
    x++;
  }
  
  return;
}
