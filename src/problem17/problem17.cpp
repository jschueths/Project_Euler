//      Author: jschueths
// Description: Problem 17 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <string>
#include "./libraries/algorithms.h"

using namespace std;

int main()
{
  string temp[1001];
  unsigned int count = 0;
  
  for(int i = 1; i <= 1000; i++)
    temp[i] = num_to_words(i);

  for(unsigned int i = 1; i <= 1000; i++)
  {
    for(unsigned int j = 0; j < temp[i].length(); j++)
    {
      if(temp[i][j] != ' ' && temp[i][j] != '-')
        count++;
    }
  }
  cout << "Num letters: " << count << endl;
  return 0;
}
