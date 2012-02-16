//      Author: jschueths
// Description: Problem 36 of the Euler Project (eulerproject.net/problems)

#include "./libraries/algorithms.h"
#include <iostream>

using namespace std;

int main()
{
  unsigned long long int sum = 0;
  string temp;
  unsigned long long int limit = 1000000;
  for(unsigned long long int i = 0; i <= limit; i++)
  {
    temp = convBase(i, 2);
    if(isPalindrome(convert_to_string(i)) && isPalindrome(temp))
      sum += i;
  }
  cout << "Sum: " << sum << endl;
  return 0;
}
