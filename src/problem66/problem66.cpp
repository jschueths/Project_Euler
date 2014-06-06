//      Author: jschueths
// Description: Problem 66 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include <cmath>
#include <gmpxx.h>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

vector<unsigned int> CFsolution(unsigned int d);
mpz_class get_trivial_solution(vector<unsigned int> CF, unsigned int d);

int main()
{
  Timer my_time;
  unsigned int limit = 1000;
  vector<bool> D(limit, true);
  vector<unsigned int> cfrac;
  mpz_class x;
  mpz_class max_x = 0;
  unsigned int d_index = 0;
  
  // Generate a prime sieve:
  D[0] = false;
  D[1] = false;
  for(unsigned int i = 2; i < limit; i++)
  {
    if(D[i])
    {
      for(unsigned int j = 2; j * i < limit; j++)
        D[i * j] = false;
    }
  }
  my_time.start();
  for(unsigned int d = 2; d < limit; d++)
  {
    //if(!D[d])
      //continue;
    cfrac = CFsolution(d);
    x = get_trivial_solution(cfrac, d);
    if(x > max_x)
    {
      d_index = d;
      max_x = x;
    }
  }
  my_time.end();

  cout << "Result: " << d_index << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}

mpz_class get_trivial_solution(vector<unsigned int> CF, unsigned int d)
{
  mpz_class m_r;
  mpz_class m_d = d;
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
  
  for(unsigned int i = 0; i < limit; i++)
  {
    mpz_class h2 = h[i] * h[i];
    mpz_class k2 = k[i] * k[i];
    m_r = (k2 * m_d) + 1;
    if(m_r == h2)
    {
      m_r = h[i];
      break;
    }
  }
  return m_r;
}  

vector<unsigned int> CFsolution(unsigned int d)
{
  vector<unsigned int> result;
  if(is_perfect_square(d))
  {
    result.push_back(sqrt(d));
    return result;
  }
  
  unsigned int step1_num = 0;
  unsigned int step1_denom = 1;
  unsigned int nextn, step2_num, step2_denom;
  unsigned int step3_num, step3_denom;
  
  while(true)
  {
    nextn = (floor(sqrt(d)) + step1_num) / step1_denom;
    result.push_back(nextn);
    
    step2_num = step1_denom;
    step2_denom = step1_num - step1_denom * nextn;
    
    step3_denom = (d - (step2_denom * step2_denom)) / step2_num;
    step3_num = -step2_denom;
    
    if(step3_denom == 1)
    {
      result.push_back(result[0] * 2);
      break;
    }
    
    step1_num = step3_num;
    step1_denom = step3_denom;
  }
  return result;
}
  