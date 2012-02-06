//      Author: jschueths
// Description: Problem 13 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <fstream>

#include "nn_digit.h"

using namespace std;

int main(int argc, char *argv[])
{
  NN_DIGIT nums[100];
  
  if(argc != 2)
  {
    std::cerr << "Incorrect Usage" << std::endl;
    return 1;
  }
  ifstream in;
  in.open(argv[1]);
  
  for(int i = 0; i < 100; i++)
  {
    in >> nums[i];
  }
  for(int i = 1; i < 100; i++)
  {
    nums[0] += nums[i];
  }
  cout << nums[0] << endl;
  
  return 0;
}
