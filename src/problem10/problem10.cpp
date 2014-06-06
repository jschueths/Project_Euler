#include <iostream>
#include <prime.h>
#include <vector>
#include <cmath>

const size_t LIMIT = 2000000;


int main() {

	std::vector<bool> sieve(LIMIT, true);
	sieve[0] = false;
	sieve[1] = false;
	for(size_t i = 2; i < sqrt(LIMIT) + 1; ++i) {
		if(!sieve[i]) {
			continue;
		}
		size_t coefficient = 2;
		while(i * coefficient < sieve.size()) {
			sieve[i * coefficient] = false;
			coefficient++;
		}
	}

		

	size_t sum = 0;
	for(size_t i = 0; i < sieve.size(); ++i) {
		if(sieve[i]) {
			sum += i;
		}
	}
	std::cout << "Sum of primes < 2,000,000: " << sum << std::endl;
	return 0;
}

