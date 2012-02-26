//      Author: jschueths
// Description: Problem 40 of the Euler Project (projecteuler.net/problems)

#include <string>
#include <iostream>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  string decimal;
  unsigned int count = 1;
  Timer my_timer;
  unsigned long long int product;
  
  my_timer.start();
  decimal = convert_to_string(count);
  while(decimal.length() < 1000000)
  {
    count++;
    decimal += convert_to_string(count);
  }
  
  product = (decimal[0] - 48);
  product *= (decimal[9] - 48);
  product *= (decimal[99] - 48);
  product *= (decimal[999] - 48);
  product *= (decimal[9999] - 48);
  product *= (decimal[99999] - 48);
  my_timer.end();
  
  cout << "Product: " << product << endl;
  cout << "Elapsed Time: " << my_timer << " seconds" << endl;
  return 0;
}
