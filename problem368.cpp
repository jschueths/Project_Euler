//      Author: jschueths
// Description: Problem 368 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

bool is_triple_dig(unsigned long long int n);
bool test(string match, string repo);

int main()
{
  unsigned long long int n = 2;
  long double result = 1;
  long double old_result = 0;
  unsigned long long int stop = 100000000;
  string answer;
 
  while(n < stop)
  {
    old_result = result;
    if(!is_triple_dig(n))
    {
      result += (1 / (long double) n);
    }
    n++;
    if(n == stop)
    {
      cout << setprecision(10) << result << endl;
      cout << "Continue? y/n: ";
      cin >> answer;
      if(answer == "Y" || answer == "y")
        stop = stop + 1000000;
    }
  }
  cout << setprecision(10) << result << endl;
}

bool is_triple_dig(unsigned long long int n)
{
  stringstream temp;
  string my_string;
  temp << n;
  my_string = temp.str();
  
  size_t found;
  found = my_string.find("111");
  
  
  if(test("111", my_string))
    return true;
  if(test("222", my_string))
    return true;
  if(test("333", my_string))
    return true;
  if(test("444", my_string))
    return true;
  if(test("555", my_string))
    return true;
  if(test("666", my_string))
    return true;
  if(test("777", my_string))
    return true;
  if(test("888", my_string))
    return true;
  if(test("999", my_string))
    return true;
  if(test("1000", my_string))
    return true;
  if(test("2000", my_string))
    return true;
  if(test("3000", my_string))
    return true;
  if(test("4000", my_string))
    return true;
  if(test("5000", my_string))
    return true;
  if(test("6000", my_string))
    return true;
  if(test("7000", my_string))
    return true;
  if(test("8000", my_string))
    return true;
  if(test("9000", my_string))
    return true;
  return false;
}

bool test(string match, string repo)
{
  size_t found;
  found = repo.find(match);
  if(found != string::npos)
    return true;
  return false;
}
