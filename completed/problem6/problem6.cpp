//      Author: jschueths
// Description: Problem 6 of the Euler Project (projecteuler.net/problems)

#include <iostream>

int main()
{
  long int sum_of_squares = 0;
  long int square_of_sum = 0;
  long int difference;
  
  for(int i = 0; i <= 100; i++)
  {
    sum_of_squares += (i * i);
    square_of_sum += i;
  }
  square_of_sum = square_of_sum * square_of_sum;
  
  difference = square_of_sum - sum_of_squares;
  
  std::cout << "Difference: " << difference << std::endl;
  return 0;
}
