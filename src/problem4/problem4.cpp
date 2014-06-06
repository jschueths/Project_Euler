//      Author: jschueths
// Description: Problem 4 of the Euler Project (projecteuler.net/problems)

#include <string>
#include <iostream>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  string largest_pal;
  string temp;
  unsigned int largest_val = 0;
  unsigned int product;
  Timer my_timer;
  my_timer.start();
  for(int i = 100; i < 1000; i++)
  {
    for(int j = 100; j < 1000; j++)
    {
      product = i * j;
      temp = convert_to_string(product);
      
      // If the current product is a palindrome, save it as the largest found.
      if(isPalindrome(temp))
      {
        if((i * j) > largest_val)
        {
          largest_val = i * j;
          largest_pal = temp;
        }
      }
    }
  }
  my_timer.end();
  cout << "Largest Palindrome: " << largest_pal << endl;
  cout << "Time Elapsed: " << my_timer << " seconds" << endl;
  return 0;
}
