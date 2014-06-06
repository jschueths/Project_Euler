//      Author: jschueths
// Description: Problem 22 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
//#include "./libraries/nn_digit.h"

using namespace std;

int name_value(string i);

int main(int argc, char *argv[])
{
  unsigned int sum = 0;
  ifstream in;
  string input, temp;
  vector<string> name;
  if(argc != 2)
  {
    std::cerr << "Incorrect Usage" << std::endl;
    return 1;
  }
  
  in.open(argv[1]);
  while(!in.eof())
  {
    getline(in, temp, ',');
    temp.erase(temp.begin());
    temp.erase(temp.end()-1);
    name.push_back(temp);

  }
  sort(name.begin(), name.end());
  for(unsigned int i = 0; i < name.size(); i++)
    sum += ((i + 1) * name_value(name[i]));
  cout << "SUM: " << sum << endl;
  
  in.close();
  return 0;
}


int name_value(string i)
{
  int result = 0;
  int length = i.length();
  for(int x = 0; x < length; x++)
  {
    result += (i[x] + 1 - 'A');
  }
  return result;
}

