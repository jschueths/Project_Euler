//      Author: jschueths
// Description: Problem 9 of the Euler Project (projecteuler.net/problems)

#include <iostream>

int main()
{

  int a, b, c;
  int product;
  bool found = false;
  
  for(int i = 1; i < 1000; i++)
  {
    for(int j = i + 1; j < 1000; j++)
    {
      for(int k = j + 1; k < 1000; k++)
      {
        int i_sq = i * i;
        int j_sq = j * j;
        int k_sq = k * k;
        if((i_sq + j_sq == k_sq) && (i + j + k == 1000))
        {
          found == true;
          a = i;
          b = j;
          c = k;
          break;
        }
      }
      if(found)
        break;
    }
    if(found)
      break;
  }
  
  product = a * b * c;
  std::cout << "Product: " << product << std::endl;
  
  return 0;
}
