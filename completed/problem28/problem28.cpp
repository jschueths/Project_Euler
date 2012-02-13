//      Author: jschueths
// Description: Problem 28 of the Euler Project (projecteuler.net/problems)


#include <iostream>

using namespace std;

int main()
{
  unsigned int sum = 1;
  unsigned int limit = 1001;
  unsigned int next_num = 1;
  for(int i = 2; i < limit; i += 2)
  {
    for(int j = 0; j < 4; j++)
    {
      next_num += i;
      sum += next_num;
      cout << next_num << endl;
    }
  }
  cout << "Sum: " << sum << endl;
  return 0;
}
