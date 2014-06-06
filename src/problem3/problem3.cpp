//      Author: jschueths
// Description: Problem 3 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using std::cout;
using std::endl;

int main()
{
  unsigned long long int num = 600851475143; // Num provided by the problem.
  unsigned long long int largest_prime;
  unsigned long long int limit = (num / 2) + 1; // To find a factor, we only need to go to half of the number;
  unsigned long long int temp = 6;
  unsigned long long int i = 3;
  Timer my_timer;
  my_timer.start();
  while(temp < limit)
  {
    // If the current value is prime and a factor, save it as the
    // largest prime found so far.
    if(is_prime(temp) && !(num % temp))
      largest_prime = temp;
    temp++;
  }
  my_timer.end();
  cout << "Largest Prime Factor: " << largest_prime << endl;
  cout << "Time Elapsed: " << my_timer << " seconds" << endl;
  return 0;
}
