//      Author: jschueths
// Description: Problem 44 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include <algorithm>
#include "./libraries/timer.h"

using namespace std;

long long int pentagonal(long long int n);

int main()
{
  Timer my_time;
  long long int difference;
  long long int temp;
  vector<long long int>::iterator location;
  bool found = false;
  vector<long long int> pentagonal_num(3000, 0);
  for(long long int i = 0; i < 3000; i++)
    pentagonal_num[i] = pentagonal(i);
    
  my_time.start();
  for(unsigned int i = 2; i < 3000 && !found; i++)
  {
    for(unsigned int j = i - 1; j > 0; j--)
    {
      location = find(pentagonal_num.begin() + 1, pentagonal_num.end(), (pentagonal_num[i] + pentagonal_num[j]));
      if(location == pentagonal_num.end())
        continue;
      location = find(pentagonal_num.begin() + 1, pentagonal_num.end(), (pentagonal_num[i] - pentagonal_num[j]));
      if(location == pentagonal_num.end())
        continue;
      my_time.end();
      difference = pentagonal_num[i] - pentagonal_num[j];
      found = true;
      break;
    }
  }
  
  cout << "Result: " << difference << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}
  
long long int pentagonal(long long int n)
{
  return (n * ((3 * n) - 1)) / 2;
}  