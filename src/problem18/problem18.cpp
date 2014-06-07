//      Author: jschueths
// Description: Problem 18 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "triangle.h"


size_t max_path(std::vector<std::vector<size_t> > &triangle);

int main() {
	size_t sum = 0;
	std::vector<std::vector<size_t> > my_triangle(TRIANGLE.begin(), TRIANGLE.end());
	sum = max_path(my_triangle);
 	std::cout << "Max Sum: " << sum << std::endl;
	return 0;
}

size_t max_path(std::vector<std::vector<size_t> > &triangle) {
  size_t max = 0;
  size_t limit = triangle.size();
  for(size_t i = 1; i < limit; i++)
  {
    for(size_t j = 0; j <= i; j++)
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
  for(size_t i = 0; i < triangle[limit - 1].size(); i++)
  {
    if(triangle[limit-1][i] > max)
      max = triangle[limit-1][i];
  }
  return max;
}
