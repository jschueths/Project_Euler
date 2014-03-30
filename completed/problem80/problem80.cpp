//      Author: jschueths
// Description: Problem 243 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include "/../../../../../mingw64/include/gmp.h"
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using std::cout;
using std::endl;
using std::stringstream;
using std::string;

#include <iostream>
#include <gmpxx.h>
#include <iomanip>

using namespace std;

unsigned long long int convert_and_add(mpf_class &x);

int main()
{
  // GMP init
  mpf_class index, sqrt_index(0, 10000);
  
  // Other variable init
  unsigned long long int sum = 0;
  Timer my_time;
  
  my_time.start();
  for(unsigned long int i = 2; i < 100; i++)
  {
    if(is_perfect_square(i))
      continue;
    index = i;
    sqrt_index = sqrt(index);
    
   //Convert to a string and then add the first 100 digits.
    sum += convert_and_add(sqrt_index);
  }
  my_time.end();
  
  cout << "Result: " << sum << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}

unsigned long long int convert_and_add(mpf_class &x)
{
  unsigned long long int result = 0;
  stringstream out;
  string temp;
  unsigned int limit = 100;
  
  out << setprecision(500) << x;
  out >> temp;
  for(unsigned int i = 0; i < limit; i++)
  {
    if(temp[i] == '.')
    {
      limit++;
      continue;
    }
    
    result += temp[i] - '0';
  }
  return result;
}
  