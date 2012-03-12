//      Author: jschueths
// Description: Problem 138 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  Timer my_time;
  
  long long int sum = 0;
  long long int base, height;
  long long length;
  long long int mult = 1;
  
  vector<long int> fib_num;
  fib_num.push_back(1);
  fib_num.push_back(1);
  for(long int i = 1; i < 37; i++)
    fib_num.push_back(fib_num[i - 1] + fib_num[i]);
  vector<long long int> n, m;
  vector<long long int> sum2;

  for(unsigned int i = 3; i < fib_num.size(); i++)
  {
    switch((i-3) % 3)
    {
      case 0:
        n.push_back(fib_num[i]);
        break;
      case 1:
        m.push_back(fib_num[i]);
        break;
    }
  }
  
  my_time.start();
  for(int i = 0; i < 12; i++)
  {
    mult = 1;
    height = m[i] * n[i];
    base = ((m[i] * m[i]) - (n[i] * n[i])) / 2;
    length = ((m[i] * m[i]) + (n[i] * n[i])) / 2;
    int result;
    result = (base * 2) - height;
    while(result != 1 && result != -1)
    {
      mult++;
      result = ((base * 2)) * mult - (height * mult);
    }
    sum = sum + (length * mult);
    sum2.push_back(length * mult);
  }
  my_time.end();
  
  cout << "Sum: " << sum << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}
