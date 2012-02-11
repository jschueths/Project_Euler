//      Author: jschueths
// Description: Problem 4 of the Euler Project (projecteuler.net/problems)

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

bool isPalindrome(string x);
string convert_to_string(int x);

int main()
{
  string largest_pal;
  string temp;
  unsigned int largest_val = 0;
  unsigned int product;
  for(int i = 100; i < 1000; i++)
  {
    for(int j = 100; j < 1000; j++)
    {
      product = i * j;
      temp = convert_to_string(product);
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
  
  cout << "Largest Palindrome: " << largest_pal << endl;
  return 0;
}

bool isPalindrome(string x)
{
  string reversed = x;
  int size = x.length();
  for(int i = size - 1, j = 0; i >= 0, j < size; j++, i--)
  {
    reversed[j] = x[i];
  }
  return (x == reversed);
}

string convert_to_string(int x)
{
  stringstream oss;
  oss << x;
  return oss.str();
}
