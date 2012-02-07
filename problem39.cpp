//      Author: jschueths
// Description: Problem 39 of the Euler Project (projecteuler.net/problems)

#include <iostream>

int main()
{
  int count = 0;
  int best_count = 0;
  int best_p;
  
  for(int p = 1000; p >= 12; p--)
  {
    for(int a = 1; a < p; a++)
    {
      for(int b = 1; b < p-a; b++)
      {
        for(int c = 1; c < p-a-b; c++)
        {
          if((a + b + c == p) && ((c * c) + (b * b) == (a*a)))
            count++;
        }
      }
    }
    if(count > best_count)
      best_p = p;
    count = 0;
  }
  
  std::cout << "Best p: " << best_p << std::endl;
  return 0;
}
