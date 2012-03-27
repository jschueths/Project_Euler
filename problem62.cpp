//      Author: jschueths
// Description: Problem 62 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;
unsigned long long int str_to_i(string x);
string i_to_str(unsigned long long int x);
int main()
{
  bool found = false;
  unsigned long long int num = 41063625;
  string temp;
  unsigned long long int temp_num;
  int count = 0;
  while(!found)
  {
    num++;
    if(is_perfect_cube(num))
    {
      temp = i_to_str(num);
      count++;
      while(next_permutation(temp.begin(), temp.end()))
      {
        temp_num = str_to_i(temp);
        if(is_perfect_cube(temp_num))
          count++;
        if(count > 5)
          break;
      }
      if(count == 5)
      {
        found = true;
        break;
      }
    }
  }
  return 0;
}


unsigned long long int str_to_i(string x)
{
  unsigned int limit = x.length();
  unsigned long long int result = 0;
  for(unsigned int i = 0; i < limit; i++)
  {
    result *= 10;
    result += (x[i] - '0');
  }
  return result;
}

string i_to_str(unsigned long long int x)
{
  string result;
  stringstream out;
  out << x;
  out >> result;
  return result;
}

  
  
  