//      Author: jschueths
// Description: Problem 14 of the Euler Project (projecteuler.net/problems)

#include <iostream>

size_t get_num_divisors(const size_t &x);

int main()
{
  size_t max_count = 0;
  size_t max_seed;
  size_t count = 0;
  size_t n;
  for(size_t i = 2 ; i < 1000000; i++)
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

