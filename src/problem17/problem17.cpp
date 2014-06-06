//      Author: jschueths
// Description: Problem 17 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <string>
#include <vector>

std::string numToWords(size_t x);
std::string englishLookup(size_t n, bool tens);

int main() {
	std::vector<std::string> words;
	size_t count = 0;

	for(size_t i = 1; i <= 1000; i++) {
		words.push_back(numToWords(i));
	}

	for(auto it = words.begin(); it != words.end(); it++) {
		for(auto jt = (*it).begin(); jt != (*it).end(); jt++) {
			if(*jt != ' ' && *jt != '-') {
				count++;
			}
		}
	}
	std::cout << "Num letters: " << count << std::endl;
	return 0;
}

std::string numToWords(size_t n) {
  size_t num = n;
  std::string output = "";
  if(num >= 1000)
  {
    output += englishLookup(num / 1000, 0);
    if(n % 1000)
      output += " thousand ";
    else
      output += " thousand";
    num = num % 1000;
  }
  if(num >= 100)
  {
    output += englishLookup(num / 100, 0);
    if(num % 100)
      output += " hundred and ";
    else
      output += " hundred";
    num = num % 100;
  }
  if(num >= 20)
  {
    output += englishLookup(num / 10, 1);
    num = num % 10;
    if(num != 0)
      output += "-";
  }
  if(num > 0)
  {
    output += englishLookup(num, 0);
  }
  return output;
}

std::string englishLookup(size_t n, bool tens)
{
  if(!tens)
  {
    switch(n)
    {
      case 0:
        return 0;
      case 1:
        return "one";
      case 2:
        return "two";
      case 3:
        return "three";
      case 4:
        return "four";
      case 5:
        return "five";
      case 6:
        return "six";
      case 7:
        return "seven";
      case 8:
        return "eight";
      case 9:
        return "nine";
      case 10:
        return "ten";
      case 11:
        return "eleven";
      case 12:
        return "twelve";
      case 13:
        return "thirteen";
      case 14:
        return "fourteen";
      case 15:
        return "fifteen";
      case 16:
        return "sixteen";
      case 17:
        return "seventeen";
      case 18:
        return "eighteen";
      case 19:
        return "nineteen";
    }
  }
  if(tens)
  {
    switch(n)
    {
      case 2:
        return "twenty";
      case 3:
        return "thirty";
      case 4:
        return "forty";
      case 5:
        return "fifty";
      case 6:
        return "sixty";
      case 7:
        return "seventy";
      case 8:
        return "eighty";
      case 9:
        return "ninety";
    }
  }
  return "zero";
}

