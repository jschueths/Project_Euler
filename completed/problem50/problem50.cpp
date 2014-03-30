//      Author: jschueths
// Description: Problem 50 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  Timer my_time;
  vector<long long int> prime;
  unsigned int longest_chain = 0;
  unsigned int chain;
  long long int saved_prime;
  long long int limit = 1000000;
  long long int sum = 0;
  for(long long int i = 2; i < limit; i++)
  {
    if(is_prime(i))
      prime.push_back(i);
  }
  
  my_time.start();
  for(unsigned int i = 0; i < prime.size(); i++)
  {
    chain = 1;
    sum = prime[i];
    for(unsigned int j = i + 1; j < prime.size(); j++)
    {
      sum += prime[j];
      chain++;
      if(sum > limit)
        break;
      if(is_prime(sum))
      {
        if(chain > longest_chain)
        {
          saved_prime = sum;
          longest_chain = chain;
        }
      }
    }
  }
  my_time.end();
  
  cout << "Result: " << saved_prime << "\t" << longest_chain << endl;
  cout << "Time Elapsed: " << my_time << endl;
  return 0;
}
