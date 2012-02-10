//      Author: jschueths
// Description: Problem 7 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

bool is_prime(unsigned long long int x);

int main()
{
  clock_t start, end;
  unsigned long long int num = 6;
  unsigned long long int prime;
  unsigned int count = 3;
  start = clock();
  while(count < 10001)
  {
    if(is_prime(num))
    {
      prime = num;
      count++;
    }
    num++;
  }
  end = clock();
  cout << "10001st Prime: " << prime << endl;
  cout << "Elapsed Time: " << ((double) (end - start) / CLOCKS_PER_SEC) << " sec" << endl;
  return 0;
}


bool is_prime(unsigned long long int x)
{
  unsigned long long int i = 1;
  if(!(x % 2))
    return false;
  if(!(x % 3))
    return false;
  while((6 * i - 1) < (sqrt(x) + 1))
  {
    if(!(x % ((6 * i) - 1)))
      return false;
    if(!(x % ((6 * i) + 1)))
      return false;
    i++;
  }
  return true;
}
