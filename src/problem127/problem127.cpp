//      Author: jschueths
// Description: Problem 127 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

unsigned int rad(unsigned int x);
bool is_hit(unsigned int x, unsigned int target, vector<bool> &seive);
bool found_in(unsigned int x, vector<unsigned int> &table);

int main()
{
  unsigned int sum = 0;
  Timer my_time;
  //unsigned int limit = 1000;
  unsigned int limit = 120000;
  unsigned int count = 0;
  vector<unsigned int> rad_table;
  unsigned int temp_rad;
  unsigned int j;
  unsigned int a;
  unsigned int b;
  unsigned int c_2;
  unsigned int rad_c;
  unsigned int ratio;
  map<unsigned int, vector<unsigned int> > reverse_rad;
  
  // Generate a rad lookup table and a reverse rad lookup table:
  cout << "Generating rad table" << endl;
  for(unsigned int i = 0; i < limit; i++)
  {
    if((!(i % (limit / 10))) && i > 0)
      cout << i / (limit / 10) << "0%" << endl;
    temp_rad = rad(i);
    rad_table.push_back(temp_rad);
    reverse_rad[temp_rad].push_back(i);
  }
  cout << "Finished building rad table" << endl;
  
  // Generate a prime sieve for use later on:
  // unsigned int prime_size = sqrt(limit) + 2;
  // vector<bool> prime(prime_size, true);
  // prime_size = prime.size();
  // prime[0] = false;
  // prime[1] = false;
  // for(unsigned int i = 2; i < prime_size; i++)
  // {
    // if(prime[i])
    // {
      // for(unsigned int k = 2; (i * k) < prime_size; k++)
      // {
        // prime[i * k] = false;
      // }
    // }
  // }

  my_time.start();  
  for(unsigned int c = 2; c < limit; c++)
  {
    c_2 = c >> 1; // Fastest way to divide by 2
    rad_c = rad_table[c];
    ratio = c / rad_c;
    
    // Conditions:
    // rad(abc) >= 2 * rad(b
    // b = c - a > rad(abc) - a > 2 * rad(b) - a
    // b + a > 2 * rad(b)
    // 2 * b > a + b > 2 * rad(b)
    if(rad_c >= c_2)
      continue;
    for(unsigned int rad_a = 1; rad_a < ratio; rad_a++)
    {
      vector<unsigned int> a_list = reverse_rad[rad_a];
      unsigned int iterations = a_list.size();
      for(unsigned int j = 0; j < iterations; j++)
      {
        a = a_list[j];
        if(a >= c_2)
          break;
        b = c - a;
        if(gcd(a, b) == 1)
        {
          if((rad_a * rad_table[b]) < ratio)
          {
            //cout << a << "\t" << b << "\t" << c << endl;
            sum += c;
            count++;
          }
        }
      }
    } 
  }
  my_time.end();
  
  cout << "Result: " << sum << endl;
  cout << "Count : " << count << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  
  return 0;
}

bool found_in(unsigned int x, vector<unsigned int> &table)
{
  unsigned int size = table.size();
  for(unsigned int i = 0; i < size; i++)
  {
    if(table[i] == x)
      return true;
  }
  return false;
}


unsigned int rad(unsigned int x)
{
  unsigned int x_orig = x;
  unsigned int result = 1;
  
  if(x == 0)
    return 0;
  if(!(x % 2))
    result *= 2;
  while(!(x % 2))
  {
    x /= 2;
  }
  
  for(unsigned int i = 3; i < ((x / 2) + 1); i += 2)
  {
    if(is_prime(i))
    {
      if(!(x_orig % i))
        result *= i;
      while(!(x % i))
      {
        x /= i;
      }
    }
  }
  result *= x;
  return result;
}

bool is_hit(unsigned int x, unsigned int target, vector<bool> &seive)
{
  unsigned int x_orig = x;
  unsigned int result = 1;
  unsigned int size = seive.size();
  
  for(unsigned int i = 2; i < size; i++)
  {
    if(seive[i])
    {
      if(!(x_orig % i))
        result *= i;
      while(!(x % i))
      {
        x /= i;
      }
    }
  }
  result *= x;
  if(result >= target)
    return false;
  return true;
}

