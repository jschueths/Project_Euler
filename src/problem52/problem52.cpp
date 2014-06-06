//      Author: jschueths
// Description: Problem 52 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  unsigned long long int n = 0;
  bool found = false;
  
  while(!found)
  {
    n++;
    for(int i = 2; i <= 6; i++)
    {
      if(!is_permutation(n, n * i))
        break;
      if(i == 6)
        found = true;
    }
  }
  cout << "Integer: " << n << endl;
  return 0;
}
