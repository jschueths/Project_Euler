//      Author: jschueths
// Description: Problem 9 of the Euler Project (projecteuler.net/problems)

#include <iostream>

int main() {

	for(size_t c = 998; c > 2; --c) {
		for(size_t b = 1000 - c - 1; b > c/2; --b) {
			size_t a = 1000 - c - b;
			if(a + b + c == 1000 && (a * a) + (b * b) == (c * c)) {
				std::cout << "Product: " << a * b * c << std::endl;
				return 0;
			}
		}
	}
	return 0;
}

