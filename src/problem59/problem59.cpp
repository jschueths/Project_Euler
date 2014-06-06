//      Author: jschueths
// Description: Problem 32 of the Euler Project (projecteuler.net/problems)


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "../Project_Euler/libraries/algorithms.h"

using namespace std;

vector<int> XOR(vector<char> code, vector<char> k);

int main(int argc, char *argv[])
{
  ifstream in;
  if(argc != 2)
  {
    std::cerr << "Incorrect Usage" << std::endl;
    return 1;
  }
  stringstream oss;
  string line;
  string temp;
  vector<char> ascii_code;
  in.open(argv[1]);
  while(getline(in, line))
  {
    oss << line;
    while(getline(oss, temp, ','))
    {
      ascii_code.push_back(convert_to_int(temp));
    }
  }
  in.close();
  vector<char> key;
  key.push_back(0);
  key.push_back(0);
  key.push_back(0);
  unsigned int sum;
  for(char i = 97; i < 123; i++)
  {
    for(char j = 97; j < 123; j++)
    {
      for(char k = 97; k < 123; k++)
      {
        key[0] = i;
        key[1] = j;
        key[2] = k;
        
        sum = 0;
        vector<int> output;
        output = XOR(ascii_code, key);
        if(output.size() == ascii_code.size())
        {
          cout << endl << endl;
          for(unsigned int l = 0; l < ascii_code.size(); l++)
          {
            cout << (char) output[l];
            sum += output[l];
          }
          cout << endl << "Sum: " << sum << "\t" << (char) i << (char) j << (char) k << endl;
        }
      }
    }
  }
  return 0;
}

vector<int> XOR(vector<char> code, vector<char> k)
{
  vector<int> result;
  unsigned int limit = code.size();
  char temp;
  for(unsigned int i = 0; i < limit; i++)
  {
    temp = code[i] ^ k[i % 3];
    if(temp == '+' || temp == '*' || temp == '#' || temp == '&' || temp == '~' || temp == '{' || temp == '}')
      break;
    result.push_back(code[i] ^ k[i % 3]);
  }
  return result;
}
