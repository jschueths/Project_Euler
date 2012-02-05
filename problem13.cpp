//      Author: jschueths
// Description: Problem 13 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <ifstream>

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    std::cerr << "Incorrect Usage" << std::endl;
    return 1;
  }
  
  ifstream in;
  in.open(argv[1]);
  
  return 0;
}
