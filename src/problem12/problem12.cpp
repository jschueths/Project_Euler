//      Author: jschueths
// Description: Problem 12 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <cmath>


int main() {
/*   num := 0;
  j := 0;
  repeat
  inc(j);
  f := 0;
  num := num + j;
    for n := 1 to round(sqrt(num)) do
    if num mod n = 0 then
    f := f + 2;
  until
  f > 500;
*/ 

	size_t triNum = 0;
	size_t j = 0;
	size_t numDivisors = 0;
	while(numDivisors <= 500) {
		numDivisors = 0;
		triNum += ++j;
		for (size_t i = 1; i < sqrt(triNum) + 1; ++i) {
			if(!(triNum % i)) {
				numDivisors += 2;
			}
		}
	} 
  
	std::cout << "Triangle Number: " << triNum << std::endl;
	return 0;
}

