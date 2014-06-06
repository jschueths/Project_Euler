//      Author: jschueths
// Description: Problem 13 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <fstream>


using namespace std;

int main(int argc, char *argv[])
{
  unsigned int cell[20][20];
  unsigned int product;
  unsigned int max_product = 0;
  
  if(argc != 2)
  {
    std::cerr << "Incorrect Usage" << std::endl;
    return 1;
  }
  ifstream in;
  in.open(argv[1]);
  for(int i = 0; i < 20; i++)
  {
    for(int j = 0; j < 20; j++)
      in >> cell[i][j];
  }
  in.close();
  
  // Check horizontals and verticals:
  for(int i = 0; i < 20; i++)
  {
    for(int j = 0; j < 16; j++)
    {
      product = cell[i][j] * cell[i][j + 1] * cell[i][j + 2] * cell[i][j + 3];
      if(product > max_product)
        max_product = product;
      product = cell[j][i] * cell[j][i + 1] * cell[j][i + 2] * cell[j][i + 3];
      if(product > max_product)
        max_product = product;
    }
  }
  
  // Check diagonals:
  for(int i = 0; i < 16; i++)
  {
    for(int j = 0; j < 16; j++)
    {
      product = 1;
      for(int k = 0; k < 4; k++)
        product *= cell[i + k][j + k] ;
      if(product > max_product)
        max_product = product;
    }
    for(int j = 0; j < 16; j++)
    {
      product = 1;
      for(int k = 0; k < 4; k++)
        product *= cell[i + 4 - k][j + k];
      if(product > max_product)
        max_product = product;
    }
  }
  std::cout << "Max product: " << max_product << std::endl;
  return 0;

}

  