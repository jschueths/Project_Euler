//      Author: jschueths
// Description: Problem 67 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  ifstream in;
  unsigned int product;
  unsigned int max_path;
  string input, temp;
  if(argc != 2)
  {
    std::cerr << "Incorrect Usage" << std::endl;
    return 1;
  }
  