//      Author: jschueths
// Description: Problem 79 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> key;

bool my_compare(char i, char j);

int main(int argc, char *argv[])
{
  vector<char> passcode;
  passcode.push_back('0');
  passcode.push_back('1');
  passcode.push_back('2');
  passcode.push_back('3');
  passcode.push_back('6');
  passcode.push_back('7');
  passcode.push_back('8');
  passcode.push_back('9');
  
  ifstream in;
  string temp;
  if(argc != 2)
  {
    std::cerr << "Incorrect Usage" << std::endl;
    return 1;
  }
  
  in.open(argv[1]);
  while(!in.eof())
  {
    in >> temp;
    key.push_back(temp);
  }
  
  sort(passcode.begin(), passcode.end(), my_compare);
  cout << "Passcode: ";
  for(unsigned int i = 0; i < passcode.size(); i++)
    cout << passcode[i];
  cout << endl;
  
  return 0;
}

bool my_compare(char i, char j)
{
  int index1, index2;
  bool found1, found2;
  unsigned int size = key.size();
  for(unsigned int m = 0; m < size; m++)
  {
    found1 = false;
    found2 = false;
    for(int k = 0; k < key[m].length(); k++)
    {
      if(i == key[m][k])
      {
        found1 = true;
        index1 = k;
      }
      if(j == key[m][k])
      {
        found2 = true;
        index2 = k;
      }
    }
    if(found1 && found2)
      return (index1 < index2);
  }
}

