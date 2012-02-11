//      Author: jschueths
// Description: Problem 13 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <ifstream>
#include <string>
#include <cstdlib>

void add_number(string & x, string &y);
{
  char carry;
  carry = "0";
  for(int i = 49; i >= 0; i--)
  {
    add(x[i], y[i], carry);
  }
  return;
}

void add(char &x, char &y, char carry)
{
  int temp_x, temp_y, temp_carry;
  temp_x = atoi(x);
  temp_y = atoi(y);
  temp_carry = atoi(carry);
  
  
  return;
}

int main(int argc, char *argv[])
{
  string temp;
  int 
  if(argc != 2)
  {
    std::cerr << "Incorrect Usage" << std::endl;
    return 1;
  }
  
  ifstream in;
  in.open(argv[1]);
  for(int i = 0; i < 100; i++)
  {
    in >> temp;
    for(int j = 0; j < 50; j++)
    {
      n
  return 0;
}
