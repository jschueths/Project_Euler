//      Author: jschueths
// Description: Problem 68 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <algorithm>
#include <string>
#include "./libraries/algorithms.h"
#include "./libraries/timer.h"

using namespace std;

bool check_candidate(int * ring, unsigned int size);
bool compare_r_c(string r, string c);
string get_string(int x);

int main()
{
  Timer my_time;
  int ring[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  string result = "0";
  int test[10] = {6, 5, 3, 10, 1, 9, 4, 8, 2, 7};
  
  my_time.start();
  do
  {
    string candidate;
    if(!check_candidate(ring, 10))
      continue;
    candidate = get_string(ring[0]);
    candidate += get_string(ring[1]);
    candidate += get_string(ring[2]);
    candidate += get_string(ring[3]);
    candidate += get_string(ring[2]);
    candidate += get_string(ring[4]);
    candidate += get_string(ring[5]);
    candidate += get_string(ring[4]);
    candidate += get_string(ring[6]);
    candidate += get_string(ring[7]);
    candidate += get_string(ring[6]);
    candidate += get_string(ring[8]);
    candidate += get_string(ring[9]);
    candidate += get_string(ring[8]);
    candidate += get_string(ring[1]);
    
    if(compare_r_c(result, candidate))
      result = candidate;
  }while(next_permutation(ring, ring+10));
  my_time.end();
  
  cout << "Result: " << result << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  
  return 0;
}

bool compare_r_c(string r, string c)
{
  if(r.length() == c.length())
  {
    for(unsigned int i = 0; i < r.length(); i++)
    {
      if(c[i] > r[i])
        return true;
      if(c[i] < r[i])
        return false;
    }
  }
  if(r.length() > c.length())
    return false;
  if(c.length() > r.length())
    return true;
}

string get_string(int x)
{
  string candidate;
  if(x == 10)
    candidate = "10";
  else
    candidate.push_back('0' + x);
  return candidate;
}

bool check_candidate(int * r, unsigned int size) 
{
    if (r[1] == 10 || r[2] == 10 || r[4] == 10 || r[6] == 10 || r[8] == 10)
      return false;
    if (r[0] > r[3] || r[0] > r[5] || r[0] > r[7] || r[0] > r[9])
      return false;
    if (r[0] + r[1] + r[2] != r[3] + r[2] + r[4])
      return false;
    if (r[0] + r[1] + r[2] != r[5] + r[4] + r[6])
      return false;
    if (r[0] + r[1] + r[2] != r[7] + r[6] + r[8])
      return false;
    if (r[0] + r[1] + r[2] != r[9] + r[8] + r[1])
      return false;
    return true;
}