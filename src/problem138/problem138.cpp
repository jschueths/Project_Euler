//      Author: jschueths
// Description: Problem 138 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <cmath>
#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  unsigned int b = 2;
  unsigned int sum = 0;
  unsigned int h;
  long double L;
  int count = 0;
  cout << "b" << "\t" << "h" << "\t" << "L" << "\t" << "Count" << "\t" << "Sum" << endl;
  while(count < 30)
  {
    h = b + 1;
    L = sqrt(((b * b)/4.0) + (h * h));
    if(floor(L + 0.5) == L)
    {
      sum += L;
      count++;
      cout << b << "\t" << h << "\t" << L << "\t" << count << "\t" << sum << endl;
    }
    
    h = b - 1;
    L = sqrt(((b * b)/4.0) + (h * h));
    if(floor(L + 0.5) == L)
    {
      sum += L;
      count++;
      cout << b << "\t" << h << "\t" << L << "\t" << count << "\t" << sum << endl;
    }
    b++;
  }
  if(count == 13)
    sum -= L;
  cout << "Sum: " << sum << endl;
  return 0;
}
