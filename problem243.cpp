//      Author: jschueths
// Description: Problem 243 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

unsigned long long int R(unsigned long long int n);

// int main()
// {
  // Timer my_time;
  // unsigned int p_num = 15499;
  // unsigned int p_denom = 94744;
  // bool found = false;
  // unsigned long long int denom = 1000000000;
  // unsigned long long int resilience;
  // unsigned long long int r1, r2;
  // unsigned long long int l1, l2;
  
  // cout << phi(9) << endl;
  // cout << phi(36) << endl;
  
  // my_time.start();
  // while(!found)
  // {
    // denom--;
    // cout << 1 << endl;
    // resilience = R(denom);
    // cout << 2 << endl;
    // r1 = p_denom * resilience;
    // r2 = p_num * denom;
    // if((denom - 892371480) % 1000)
      // cout << ".";
    // if(r1 < r2)
      // break;
  // }
  // cout << endl;
  // my_time.end();
  // cout << "Solution: " << denom << endl;
  // cout << "Time Elapsed: " << my_time << " seconds" << endl;
  // return 0;
// }

int main()
{
  unsigned int p_num = 15499;
  unsigned int p_denom = 94744;
  long double ratio = 15499.0 / 94744.0;
  unsigned long long int r1, r2, denom;
  Timer my_time;
  // vector<unsigned long int> totient;
  // for(unsigned int i = 0; i <= 25000; i++)
    // totient.push_back(i);
    
  // phi(totient);
  
  // for(unsigned int i = 2; i < 25000; i++)
  // {
    // cout << i << ":\t" << phi(i) << "\t" << totient[i] << endl;
  // }
  
  cout << phi(892371480) << endl;
  
  long double temp;
  // my_time.start();
  // for(unsigned long long int d = 892371480/*1000000000*/; d > 0; d--)
  // {
    // temp = (long double) phi(d) / (long double) d;
    // if(temp < ratio)
    // denom = d;
      // break;
  // }  
  // my_time.end();
  
  cout << "Solution: " << denom << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}

unsigned long long int R(unsigned long long int n)
{
  unsigned long long int count = 0;
  int step = 1;
  if(n % 2 == 0)
   step = 2;
  for(unsigned long long int i = 1; i < n; i += step)
  {
    if(HCF(i, n) == 1)
      count++;
  }
  
  return count;
}
