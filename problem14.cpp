//      Author: jschueths
// Description: Problem 14 of the Euler Project (projecteuler.net/problems)

#include <iostream>

unsigned int get_num_divisors(const unsigned int &x);

int main()
{
  unsigned int max_count = 0;
  unsigned int max_seed;
  unsigned int count = 0;
  unsigned int n;
  for(unsigned int i = 1; i < 1000000000; i++)
  {
    n = i;
    count = 0;
    while(n != 1)
    {
      if(n % 2)
        n = 3 * n + 1;
      else
        n = n / 2;
      count++;
    }
    if(count > max_count)
    {
      max_count = count;
      max_seed = i;
    }
  }
  std::cout << "Max seed: " << max_seed << std::endl;
  return 0;
}
