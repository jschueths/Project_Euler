//      Author: jschueths
// Description: Problem 32 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include "./libraries/algorithms.h"

using namespace std;

bool in_vector(long long int x, vector<long long int> v);

int main()
{
  long long int product;
  unsigned long int sum = 0;
  unsigned long long int limit = 9999;
  vector<long long int> products;

  for(unsigned int i = 1; i < limit; i++)
  {
    for(unsigned int j = 1; j < limit / 10; j++)
    {
      string equation;
      product = i * j;
      equation = convert_to_string(i);
      equation += convert_to_string(j);
      equation += convert_to_string(product);
      if(is_pandigital(equation, 9))
      {
        if(!in_vector(product, products))
          products.push_back(product);
      }
    }
  }
  
  unsigned int size = products.size();
  for(unsigned int i = 0; i < size; i++)
    sum += products[i];
  cout << "Sum: " << sum << endl;
  return 0;
}

bool in_vector(long long int x, vector<long long int> v)\
{
  unsigned int size = v.size();
  for(unsigned int i = 0; i < size; i++)
  {
    if(x == v[i])
      return true;
  }
  return false;
}

