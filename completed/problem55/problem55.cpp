//      Author: jschueths
// Description: Problem 55 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

unsigned long long int rev(unsigned long long n);

int main()
{
  Timer my_time;
  bool lychrel[10000];
  unsigned long long int sum = 1;
  unsigned int count = 0;
  
  cout << rev(56793) << endl;
  for(unsigned int i = 0; i < 10000; i++)
    lychrel[i] = true;
  lychrel[0] = false;

  my_time.start();
  for(unsigned long long int n = 1; n < 10000; n++)
  {
    sum = n;
    for(unsigned int i = 0; i < 50; i++)
    {
      sum += rev(sum);
      if(isPalindrome(convert_to_string(sum)))
      {
        lychrel[n] = false;
        break;
      }
    }
  }
  my_time.end();
  
  for(unsigned int i = 0; i < 10000; i++)
  {
    if(lychrel[i])
      count++;
  }
  
  cout << "Result: " << count << endl;
  cout << "Time Elapsed: " << my_time << endl;
  return 0;
}

unsigned long long int rev(unsigned long long n)
{
  unsigned long long int result = 0;
  while(n != 0)
  {
    result *= 10;
    result += (n % 10);
    n /= 10;
  }
  return result;
}