//      Author: jschueths
// Description: Problem 35 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/algorithms.h"

int main()
{


  return 0;
}

bool is_circular(unsigned int x)
{
  string prime = convert_to_string(x);
  char temp;
  int iterations = x.length();
  for(int i = 0; i < iterations; i++)
  {
    temp = prime[iterations - 1];
    for(int j = 0; j < iterations; j++)
    {
      