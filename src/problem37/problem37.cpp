//      Author: jschueths
// Description: Problem 37 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/algorithms.h"

using namespace std;

bool is_truncatable(unsigned int x, bool direction);

int main()
{
  int count = 0;
  unsigned int sum = 0;
  unsigned int i = 11;
  while(count < 11)
  {
    if(is_truncatable(i, 0) && is_truncatable(i, 1))
    {
      sum += i;
      count++;
    }
    i++;
  }
  
  cout << "Sum: " << sum << endl;
  return 0;
}

bool is_truncatable(unsigned int x, bool direction)
{
  string input = convert_to_string(x);
  unsigned int temp;
  if(x < 10)
    return false;
  while(input.length())
  {
    temp = convert_to_int(input);
    if(!is_prime(temp))
      return false;
    if(direction)
    {
      input.replace(0, 1, "");
    }
    else
    {
      input.replace(input.length() - 1, 1, "");
    }
  }
  return true;
}
    