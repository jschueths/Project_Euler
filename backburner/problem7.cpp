//      Author: jschueths
// Description: Problem 7 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int main()
{
  vector<bool> num(10001, true);

  vector<unsigned int> prime;
  int count = 0;
  unsigned int size = 100;
  
  for(unsigned int i = 2; i < size; i++)
  {
    //cout << count << endl;
    if(num[i])
    {
      prime.push_back(i);
      count++;
      for(unsigned int j = 2; j * i < size; j++)
      {
        num[j*i] = false;
      }
     /*  if(i == size - 1 && count < 10001)
      {
        size++;
        num.push_back(false);
      } */
    }
  }
  //cout << "List o' Primes:" << endl;
  /* for(unsigned int i = 0; i < prime.size(); i++) */
    /* cout << prime[i] << endl; */
  
  cout << "10001st Prime: " << prime[1] << endl;
  return 0;
}
