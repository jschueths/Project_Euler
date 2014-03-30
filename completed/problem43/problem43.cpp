//      Author: jschueths
// Description: Problem 43 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <string>
#include <algorithm>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

bool check(string x);
string next_pandigital(string x);
unsigned long long int my_atoi(string x);

int main()
{
  Timer my_time;
  unsigned long long int sum = 0;
  string pandigital = "1023456789";
     
  my_time.start();
  do
  {
    if(check(pandigital))
      sum += my_atoi(pandigital);
    
  }while(next_permutation(pandigital.begin(), pandigital.end()));
  my_time.end();
  
  cout << "Result: " << sum << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}

bool check(string x)
{
  unsigned int num[7] = {0, 0, 0, 0, 0, 0, 0};  
  unsigned int prime[7] = {2, 3, 5, 7, 11, 13, 17};
  for(unsigned int i = 0; i < 7; i++)
  {
    num[i] = ((x[i+1] - '0') * 100);
    num[i] += ((x[i+2] - '0') * 10);
    num[i] += (x[i+3] - '0');
    if(num[i] % prime[i])
      return false;
  }
  return true;
}

string next_pandigital(string x)
{
  char temp;
  unsigned int k = 10;
  unsigned int l = 0;
  
  // Find the largest index 'k' such that x[k] < x[k+1]. If no
  // such index exists, the input permutation is the last
  // permutation.
  for(unsigned int i = 0; i < 9; i++)
  {
    if(x[i] < x[i + 1])
      k = i;
  }
  if(k == 10)
    return "0000000000";
    
  // Find the largest index 'l' such that x[k] < x[l]. Since
  // k + 1 is such an index, 'l' is well defined and
  // satisfies k < l.
  for(unsigned int i = 0; i < 10; i++)
  {
    if(x[k] < x[i])
      l = i;
  }
  
  // Swap a[k] with a[l].
  temp = x[k];
  x[k] = x[l];
  x[l] = temp;
  
  // Reverse the sequence from x[k+1] up to and including the
  // final element x[n].
  reverse(x.begin() + k + 1, x.end());
  
  // Return the next permutation:
  return x;
}

unsigned long long int my_atoi(string x)
{
  unsigned long long int result = 0;
  int length = x.length();
  unsigned long long int tens = 1;
  for(int i = length - 1; i >= 0; i--)
  {
    result += (tens * (x[i] - '0'));
    tens *= 10;
  }
  return result;
}