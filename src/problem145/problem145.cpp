//      Author: jschueths
// Description: Problem 145 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

// My revised mathematical version:

unsigned long long int power(unsigned long long int x, unsigned int y);

int main()
{
  Timer my_time, my_time1;
  unsigned long long int sum = 0;
  unsigned long long int sum2 = 0;
  
  my_time.start();
  for(int i = 1; i < 10; i++)
  {
    if(!(i % 2)) // For any 2n-digit there are this many reversible numbers.
      sum += (20 * (power(30, ((i / 2) - 1))));
    if((i % 4) == 3) // For any (4(n - 1) + 3)-digit there are this many.
      sum += (5 * 20 *(power(25 * 20, (i / 4))));
  }
  my_time.end();
  
  cout << "Result: " << sum << endl;
  cout << "Time Elapsed: " << fixed << my_time << " seconds" << endl;

}

unsigned long long int power(unsigned long long int x, unsigned int y)
{
  unsigned long long int result = 1;
  for(unsigned int i = 0; i < y; i++)
    result *= x;
  return result;
}







// My original solution:

//bool reversible(string x);


/* int main()
{
  unsigned long long int limit = 1000000000;
  unsigned int count = 0;
  unsigned long long int sum;
  
  for(unsigned long long int i = 1; i < limit; i++)
  {
    if(i * (limit / 10) == 0)
      cerr << (i / (limit / 10)) * 10 << "%" << endl;
    string s_temp, reversed;
    unsigned long long int i_temp;
    if(!(i % 10))
      continue;
    s_temp = convert_to_string(i);
    reversed = s_temp;
    for(int j = s_temp.length() - 1, k = 0; j >= 0, k < s_temp.length(); j--, k++)
    {
      reversed[j] = s_temp[k];
    }
    i_temp = convert_to_int(reversed);
    sum = i_temp + i;
    if(reversible(convert_to_string(sum)))
    {
      cout << i << " + " << i_temp << " = " << sum << endl;
      count++;
    }
  }
  
  cout << "Result: " << count << endl;
  
  return 0;
}

bool reversible(string x)
{
  unsigned int size = x.length();

  for(unsigned int i = 0; i < size; i++)
  {
    if(((x[i] - '0') % 2) == 0)
      return false;
  }
  return true;
}
 */