//      Author: jschueths
// Description: Problem 7 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <cmath>
#include <prime.h>

int main(){
	size_t num = 6;
	size_t prime;
	size_t count = 3;

	while(count < 10001) {
		if(isPrime(num)) {
			prime = num;
			count++;
		}
		num++;
	}
	std::cout << "10001st Prime: " << prime << std::endl;
	return 0;
}

