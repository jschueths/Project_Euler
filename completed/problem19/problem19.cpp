//      Author: jschueths
// Description: Problem 19 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <string>

using std::string;

void increment_dotw(string &dow);
int month_end(int m, int y);

int main()
{
  unsigned int count = 0;
  string dotw = "Sunday";
  int end;
  
  for(int year = 1900; year < 2001; year++)
  {
    for(int month = 0; month < 12; month++)
    {
      end = month_end(month, year);
      for(int day = 0; day < end; day++)
      {
        increment_dotw(dotw);
        if(day == 0 && dotw == "Sunday" && year > 1900)
          count++;
      }
    }
  }
  
  std::cout << "Num Sundays: " << count << std::endl;
  return 0;
}

void increment_dotw(string &dow)
{
  if(dow == "Sunday")
    dow = "Monday";
  else if(dow == "Monday")
    dow = "Tuesday";
  else if(dow == "Tuesday")
    dow = "Wednesday";
  else if(dow == "Wednesday")
    dow = "Thursday";
  else if(dow == "Thursday")
    dow = "Friday";
  else if(dow == "Friday")
    dow = "Saturday";
  else if(dow == "Saturday")
    dow = "Sunday";
  return;
}

int month_end(int m, int y)
{
  int result;
  switch(m)
  {
    case 0:
    case 2:
    case 4:
    case 6:
    case 7:
    case 9:
    case 11:
      result = 31;
      break;
    case 3:
    case 5:
    case 8:
    case 10:
      result = 30;
      break;
    case 1:
      if(!(y % 4))
      {
        result = 29;
        if(!(y % 100) && (y % 400))
          result = 28;
      }
      else
      {
        result = 28;
      }
      break;
  }
  return result;
}