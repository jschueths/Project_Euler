//      Author: jschueths
// Description: Problem 8 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <fstream>
#include <string>
#include "./libraries/nn_digit.h"

using namespace std;

int main(int argc, char *argv[])
{
  ifstream in;
  unsigned int product;
  unsigned int max_product = 0;
  string input, temp;
  if(argc != 2)
  {
    std::cerr << "Incorrect Usage" << std::endl;
    return 1;
  }
  
  in.open(argv[1]);
  in >> input;
  while(!in.eof())
  {
    in >> temp;
    input += temp;
  }
  in.close();
  NN_DIGIT data(input);
  
  for(int i = 0; i < data.size() - 5; i++)
  {
    product = data[i] * data[i + 1] * data[i + 2] * data[i + 3] * data[i +4];
    if(product > max_product)
      max_product = product;
  }
  
  std::cout << "Max product: " << max_product << std::endl;
  return 0;
}
