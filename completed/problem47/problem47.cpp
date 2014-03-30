//      Author: jschueths
// Description: Problem 47 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"
using namespace std;

vector<unsigned long long int> factor(unsigned long long int x);

int main()
{
  Timer my_time;
  vector<unsigned long long int> factors;
  unsigned int consec_count = 0;
  unsigned int num_factors = 4;
  unsigned int num_consecs = 4;
  unsigned long long int n = 2 * 3 * 5 * 7;
  

  my_time.start();
  while(consec_count < num_consecs)
  {
    n++;
    factors = factor(n);
    (factors.size() == num_factors) ? (consec_count++) : (consec_count = 0);
  }
  my_time.end();
  
  cout << "Result: " << n - num_consecs + 1 << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}

vector<unsigned long long int> factor(unsigned long long int x)
{
  vector<unsigned long long int> result;
  
  if(x == 0)
    return result;
  if(!(x % 2))
    result.push_back(2);
  while(!(x % 2))
  {
    x /= 2;
  }
  
  for(unsigned long long int i = 3; x != 1; i += 2)
  {
    if(is_prime(i))
    {
      if(!(x % i))
        result.push_back(i);
      while(!(x % i))
      {
        x /= i;
      }
    }
  }
  return result;
}
