//      Author: jschueths
// Description: Problem 3 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <string>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  Timer my_timer;
  my_timer.start();
  for(unsigned int i = 9876; i >= 9123; i--)
  {
    string test;
    test = convert_to_string(i * 1) + convert_to_string(i * 2);
    if(is_pandigital(test, 1, 9))
    {
      my_timer.end();
      cout << "Largest: " << test << endl;
      cout << "Time Elapsed: " << my_timer << " seconds" << endl;
      break;
    }
  }
  return 0;
}
