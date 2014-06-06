#include "prime.h"
#include <cmath>

bool isPrime(size_t x){
	if(x == 2 || x == 3) { return true; }
	if(x < 2 || !(x % 2)) { return false; }
	if(x < 9) { return true; }
	if(!(x % 3)) { return false; }

	for(size_t f = 5; f < sqrt(x) + 1; f+=6){
		if(!(x % f)) { return false; }
		if(!(x % (f + 2))) { return false; }
	}
	return true;
}

std::set<size_t> primeFactors(size_t x) {
	std::set<size_t> result;
	while(!(x%2)) {
		result.insert(2);
		x /= 2;
	}
	
	for(size_t i = 3; i <= sqrt(x); i+=2) {
		while(!(x % i)) {
			result.insert(i);
			x /= i;
		}
	}
	if(x > 2){
		result.insert(x);
	}
	return result;
}

