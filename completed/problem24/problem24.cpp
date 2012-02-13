//      Author: jschueths
// Description: Problem 24 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  clock_t start, end;
  unsigned int count = 0;
  bool found = false;
  start = clock();
  for(int x0 = 0; x0 < 10 && !found; x0++)
  {
    for(int x1 = 0; x1 < 10 && !found; x1++)
    {
      if(x0 == x1)
        continue;
      for(int x2 = 0; x2 < 10 && !found; x2++)
      {
        if(x0 == x2)
          continue;
        if(x1 == x2)
          continue;
        for(int x3 = 0; x3 < 10 && !found; x3++)
        {
          if(x0 == x3)
            continue;
          if(x1 == x3)
            continue;
          if(x2 == x3)
            continue;
          for(int x4 = 0; x4 < 10 && !found; x4++)
          {
            if(x0 == x4)
              continue;
            if(x1 == x4)
              continue;
            if(x2 == x4)
              continue;
            if(x3 == x4)
              continue;
            for(int x5 = 0; x5 < 10 && !found; x5++)
            {
              if(x0 == x5)
                continue;
              if(x1 == x5)
                continue;
              if(x2 == x5)
                continue;
              if(x3 == x5)
                continue;
              if(x4 == x5)
                continue;
              for(int x6 = 0; x6 < 10 && !found; x6++)
              {
                if(x0 == x6)
                  continue;
                if(x1 == x6)
                  continue;
                if(x2 == x6)
                  continue;
                if(x3 == x6)
                  continue;
                if(x4 == x6)
                  continue;
                if(x5 == x6)
                  continue;
                for(int x7 = 0; x7 < 10 && !found; x7++)
                {
                  if(x0 == x7)
                    continue;
                  if(x1 == x7)
                    continue;
                  if(x2 == x7)
                    continue;
                  if(x3 == x7)
                    continue;
                  if(x4 == x7)
                    continue;
                  if(x5 == x7)
                    continue;
                  if(x6 == x7)
                    continue;
                  for(int x8 = 0; x8 < 10 && !found; x8++)
                  {
                    if(x0 == x8)
                      continue;
                    if(x1 == x8)
                      continue;
                    if(x2 == x8)
                      continue;
                    if(x3 == x8)
                      continue;
                    if(x4 == x8)
                      continue;
                    if(x5 == x8)
                      continue;
                    if(x6 == x8)
                      continue;
                    if(x7 == x8)
                      continue;
                    for(int x9 = 0; x9 < 10 && !found; x9++)
                    {
                      if(x0 == x9)
                        continue;
                      if(x1 == x9)
                        continue;
                      if(x2 == x9)
                        continue;
                      if(x3 == x9)
                        continue;
                      if(x4 == x9)
                        continue;
                      if(x5 == x9)
                        continue;
                      if(x6 == x9)
                        continue;
                      if(x7 == x9)
                        continue;
                      if(x8 == x9)
                        continue;
                      count++;
                      if(count == 1000000)
                      {
                        cout << x0 << x1 << x2 << x3 << x4 << x5 << x6 << x7 << x8 << x9 << endl;
                        end = clock();
                        found = true;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << "Time elapsed: " << ((double) end - start) / CLOCKS_PER_SEC << endl;
  return 0;
}
