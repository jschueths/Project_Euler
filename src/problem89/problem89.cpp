//      Author: jschueths
// Description: Problem 89 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "./libraries/timer.h"
#include "./libraries/algorithms.h"

using namespace std;

string find_and_replace(string x, string y, string numeral);


int main(int argc, char * argv[])
{
  Timer my_time;
  ifstream inFile;
  unsigned long long int sum = 0;
  string before, after;
  if(argc != 2)
  {
    cerr << "Incorrect Usage: " << argv[0] << " <file_name>" << endl;
    return 0;
  }
  
  inFile.open(argv[1]);
  my_time.start();
  while(!inFile.eof())
  {
    getline(inFile, before);
    after = find_and_replace("DCCCC", "CM", before);
    after = find_and_replace("LXXXX", "XC", after);
    after = find_and_replace("VIIII", "IX", after);
    after = find_and_replace("IIII", "VI", after);
    after = find_and_replace("XXXX", "Xl", after);
    after = find_and_replace("CCCC", "CD", after);
    sum += (before.length() - after.length());
  }
  my_time.end();
  
  cout << "Result: " << sum << endl;
  cout << "Time Elapsed: " << my_time << " seconds" << endl;
  return 0;
}

string find_and_replace(string x, string y, string numeral)
{
  long int OOR = 0xFFFFFFFF;
  string::iterator location = numeral.begin();
  unsigned int offset = numeral.find(x);

  if(offset != OOR)
    numeral.replace(location + offset, location + offset + x.length(), y);
  return numeral;
}
