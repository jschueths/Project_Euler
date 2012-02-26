//      Author: jschueths
// Description: Problem 370 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  unsigned long int count = 0;
  long double perimeter = pow(10, 6);
  for(unsigned long long int c = (perimeter / 3); c < (perimeter - 3); c++)
  {
    for(unsigned long long int b = c; b > 1; b--)
    {
      for(unsigned long long int a = b; a > 0; a--)
      {
        if(a + b + c == perimeter)
        {
          if((b * b) == (a * c))
          {
            count++;
            cout << count << endl;
          }
        }
      }
    }
  }
  cout << "Total count: " << count << endl;
  return 0;
}
