//      Author: jschueths
// Description: Problem 56 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <fstream>
#include <string>
#include "./libraries/nn_digit.h"
#include <ctime>

using namespace std;

int main()
{

  //NN_DIGIT test(99);
  //cout << test.size() << endl;
  //test = test.power(99);
  //cout << test<< endl;
  //cout << test.size() << endl;
  //return 0;
  double dif;
  unsigned int max_sum = 0;
  unsigned int sum = 0;
  time_t start, end;
  time(&start);
  
  for(unsigned int i = 11; i < 100; i++)
  {
    for(int j = 52; j < 100; j++)
    {
      NN_DIGIT powered(i);
      powered = powered.power(j);
      unsigned int size = powered.size();
      for(unsigned int m = 0; m < size; m++)
      {
        sum += powered[m];
      }
      if(sum > max_sum)
        max_sum = sum;
      sum = 0;
    }
  }
  time(&end);
  dif = difftime(end, start);
  cout << "Elapsed Time: " << dif << endl;
  cout << "Max Sum: " << max_sum << endl;
  return 0;
  
}