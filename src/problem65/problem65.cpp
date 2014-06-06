//      Author: jschueths
// Description: Problem 65 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include <string>
#include <gmpxx.h>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

vector<unsigned int> e_CF();
vector<mpz_class> get_convergents(vector<unsigned int> CF);

int main()
{
  Timer my_time;
  vector<unsigned int> eCF;
  vector<mpz_class> cf_num;
  string num;
  unsigned long long int sum = 0;
  my_time.start();
  
  // Calculate the continued fraction:
  eCF = e_CF();
  
  // Calculate the convergents:
  cf_num = get_convergents(eCF);
  
  // Add the digits of the 100th numerator:
  num = cf_num[99].get_str();
  for(unsigned int i = 0; i < num.length(); i++)
    sum += (num[i] - '0');
  my_time.end();
  
  cout << "Result: " << sum << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}

vector<mpz_class> get_convergents(vector<unsigned int> CF)
{
  unsigned int limit = CF.size();
  vector<mpz_class> h;
  vector<mpz_class> k;
  h.push_back(CF[0]);
  h.push_back(CF[0] * CF[1] + 1);
  k.push_back(1);
  k.push_back(CF[1]);
  for(unsigned int i = 2; i < limit; i++)
  {
    h.push_back(h[i - 1] * CF[i] + h[i - 2]);
    k.push_back(k[i - 1] * CF[i] + k[i - 2]);
  }
  
  return h;
}  

vector<unsigned int> e_CF()
{
  vector<unsigned int> result;
  result.push_back(2);
  for(unsigned int i = 1; i < 100; i++)
  {
    result.push_back(1);
    result.push_back(2 * i);
    result.push_back(1);
  }
  
  return result;
}