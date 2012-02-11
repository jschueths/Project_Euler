//      Author: jschueths
// Description: Problem 42 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using std::cerr;
using std::cout;
using std::string;
using std::endl;
using std::deque;
using std::ifstream;

int get_value(string x);
int lookup(char c);

int main(int argc, char *argv[])
{
  string temp;
  int max_value = 0;
  ifstream in;
  
  unsigned int count = 0;
  int tri_num = 0;
  int it = 1;
  int score = 0;
  
  if(argc != 2)
  {
    std::cerr << "Incorrect Usage" << std::endl;
    return 1;
  }
  in.open(argv[1]);
  while(!in.eof())
  {
    getline(in, temp, ',');
    score = get_value(temp);
    tri_num = 0;
    it = 0;
    while(tri_num < score)
    {
      tri_num = (it * (it + 1)) / 2;
      it++;
      if(tri_num == score)
        count++;
    }
    
    cout << "Num triangle numbers: " << count << endl;
  }
  in.close();
  return 0;
}

int get_value(string x)
{
  int result = 0;
  int length = x.length();
  for(int i = 1; i < length - 1; i++)
    result += lookup(x[i]);
  return result;
}

int lookup(char c)
{
  return c + 1 - 'A';
}

  