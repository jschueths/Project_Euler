//      Author: jschueths
// Description: Problem 67 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void max_path(unsigned int i, unsigned int j, vector<vector<int> > &triangle, unsigned int &sum);

int main(int argc, char *argv[])
{
  ifstream in;
  unsigned int sum = 0;
  vector<vector<int> > my_triangle;
  vector<int> temp_v;
  unsigned int index_i = 0;
  unsigned int index_j = 0;
  int temp;
  if(argc != 2)
  {
    std::cerr << "Incorrect Usage" << std::endl;
    return 1;
  }
  in.open(argv[1]);
  int level = 1;
  while(!in.eof())
  {
    for(int i = 0; i < level; i++)
    {
      in >> temp;
      temp_v.push_back(temp);
    }
    my_triangle.push_back(temp_v);
    temp_v.clear();
    level++;
  }
  in.close();
  
  max_path(index_i, index_j, my_triangle, sum);
  cout << "Max Sum: " << sum << endl;
  
  return 0;
}

void max_path(unsigned int i, unsigned int j, vector<vector<int> > &triangle, unsigned int &sum)
{
  if(i == triangle.size() - 1)
  {
    sum += triangle[i][j];
    return;
  }
  cout << i << "\t" << j << endl;
  sum += triangle[i][j];  
  if(triangle[i+1][j] > triangle[i+1][j+1])
    max_path(++i, j, triangle, sum);
  else
    max_path(++i, ++j, triangle, sum);
  return;
}