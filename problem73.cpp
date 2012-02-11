//      Author: jschueths
// Description: Problem 73 of the Euler Project (eulerproject.net/problems)

#include "./libraries/algorithms.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int comp1, comp2;
  unsigned int count = 0;
  double temp;
  
  cout << HCF(3, 4) << endl;
  cout << HCF(2, 6) << endl;

  for(unsigned int i = 4; i <= 12000; i++)
  {
    for(unsigned int j = 1 / 3; j < (i/2); j++)
    {
      temp = (double)j / i;
      if((temp < 0.5 && temp > (1/3.0)) && HCF(j, i) == 1)
      {
        count++;
        cout << "Count: " << count << "\t" << j << "\t" << i << endl;
      }
    }
  }
  cout << "Total Fractions: " << count << endl;
  return 0;
}
