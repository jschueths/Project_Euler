//      Author: jschueths
// Description: Problem 3 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

void save_if_new(long double x, vector<long double> &l);

int main()
{
  vector<long double> list;
  long double temp;
  for(long double i = 2; i <= 100; i++)
  {
    for(long double j = 2; j <=100; j++)
    {
      temp = pow(i, j);
      save_if_new(temp, list);
    }
  }
  
  std::cout << "Total Distint Values: " << list.size() << std::endl;
  return 0;
}

void save_if_new(long double x, vector<long double> &l)
{
  bool found = false;
  long double size = l.size();
  for(long double i = 0; i < size; i++)
  {
    if(x == l[i])
    {
      found = true;
      break;
    }
  }
  
  if(!found)
    l.push_back(x);
}
  