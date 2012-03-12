//      Author: jschueths
// Description: Problem 34 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <string>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  Timer my_time;
  unsigned int limit = 99999;
  string temp;
  unsigned int temp_sum;
  unsigned int sum = 0;
  
  my_time.start();
  for(unsigned int i = 3; i < limit; i++)
  {
    temp_sum = 0;
    temp = convert_to_string(i);
    for(unsigned int j = 0; j < temp.length(); j++)
      temp_sum += fact(temp[j] - '0');
    if(temp_sum == i)
      sum += i;
  }
  my_time.end();
  
  cout << "Solution: " << sum << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}
