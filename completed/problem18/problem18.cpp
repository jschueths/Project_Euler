//      Author: jschueths
// Description: Problem 18 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

unsigned int max_path(vector<vector<unsigned int> > &triangle);

int main(int argc, char *argv[])
{
  ifstream in;
  unsigned int sum = 0;
  vector<vector<unsigned int> > my_triangle;
  vector<unsigned int> temp_v;
  unsigned int index_i = 0;
  unsigned int index_j = 0;
  unsigned int temp;
  if(argc != 2)
  {
    std::cerr << "Incorrect Usage" << std::endl;
    return 1;
  }
  in.open(argv[1]);
  int level = 0;
  do
  {
    for(int i = 0; i < level+1; i++)
    {
      in >> temp;
      temp_v.push_back(temp);
    }
    my_triangle.push_back(temp_v);
    temp_v.clear();
    level++;
  }while(!in.eof());
  in.close();
  
  sum = max_path(my_triangle);
  cout << "Max Sum: " << sum << endl;
  return 0;
}

unsigned int max_path(vector<vector<unsigned int> > &triangle)
{
  unsigned int max = 0;
  unsigned int limit = triangle.size();
  for(unsigned int i = 1; i < limit; i++)
  {
    for(unsigned int j = 0; j <= i; j++)
    {
      if(j == 0)
      {
        triangle[i][j] = triangle[i][j] + triangle[i-1][j];
      }
      else if(j == i)
      {
        triangle[i][j] = triangle[i][j] + triangle[i-1][j-1];
      }
      else
      {
        if(triangle[i-1][j] > triangle[i-1][j-1])
          triangle[i][j] = triangle[i][j] + triangle[i-1][j];
        else
          triangle[i][j] = triangle[i][j] + triangle[i-1][j-1];
      }
    }
  }
  // Find the max:
  for(unsigned int i = 0; i < triangle[limit - 1].size(); i++)
  {
    if(triangle[limit-1][i] > max)
      max = triangle[limit-1][i];
  }
  return max;
}