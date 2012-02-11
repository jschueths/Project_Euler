//      Author: jschueths
// Description: Problem 12 of the Euler Project (projecteuler.net/problems)

#include <iostream>

unsigned int get_num_divisors(const unsigned int &x);

int main()
{
  unsigned int num = 1;
  unsigned int tri_num = 0;
  unsigned int num_divisors = 1;
  unsigned int max_divisors = 0;
  
  while(num_divisors < 500)
  {
    tri_num += num;
    
    num_divisors = get_num_divisors(tri_num);
    if(num_divisors > max_divisors)
      max_divisors = num_divisors;
    num++;
  }
  
  std::cout << "Triangle Number: " << tri_num << std::endl;
  return 0;
}

unsigned int get_num_divisors(const unsigned int &x)
{
  unsigned int count = 0;
  for(int i = 1; i <= x/2; i++)
  {
    if(!(x % i))
      count++;
  }
  count++;
  return count;
}
