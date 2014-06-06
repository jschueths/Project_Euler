//      Author: jschueths
// Description: Problem 81 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "./libraries/algorithms.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::stringstream;

int main(int argc, char *argv[])
{
  ifstream in;
  vector<vector<unsigned int> > matrix;
  vector<unsigned int> temp;
  string in_temp, line;
  unsigned int input;
  if(argc != 2)
  {
    std::cerr << "Incorrect Usage" << std::endl;
    return 1;
  }
  
  in.open(argv[1]);
  while(getline(in, line))
  {
    stringstream iss;
    iss << line;
    while(getline(iss, in_temp, ','))
    {
      input = convert_to_int(in_temp);
      temp.push_back(input);
    }
    matrix.push_back(temp);
    temp.clear();
  }
  in.close();
  
  
  for(int i = 0; i < 80; i++)
  {
    for(int j = 0; j < 80; j++)
    {
      if(!(i == 0 && j == 0))
      {
        if(j == 0)
        {
          matrix[i][j] += matrix[i - 1][j];
        }
        if(i == 0)
        {
          matrix[i][j] += matrix[i][j - 1];
        }
        else
        {
          if(matrix[i - 1][j] < matrix[i][j - 1])
            matrix[i][j] += matrix[i - 1][j];
          else
            matrix[i][j] += matrix[i][j - 1];
        }
      }
    }
  }
  
  cout << "Minimal Path: " << matrix[79][79] << endl;
  return 0;
}
