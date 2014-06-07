//      Author: jschueths
// Description: Problem 21 of the Euler Project (projecteuler.net/problems)


#include <iostream>
#include <vector>
#include <numeric>

std::vector<size_t> properDivisors(size_t x);
size_t sumProperDivisors(size_t x);

int main() {
	size_t result = 0;
	for(size_t i = 1; i < 10000; i++) {
		std::vector<size_t> divisors = properDivisors(i);
		size_t d = std::accumulate(divisors.begin(), divisors.end(), 0);
		if(d < 10000 && sumProperDivisors(d) == i && d != i) {
			result += i;
		}
	}
	std::cout << "Sum: " << result << std::endl;
	return 0;
}

size_t sumProperDivisors(size_t x) {
	std::vector<size_t> divisors = properDivisors(x);
	return std::accumulate(divisors.begin(), divisors.end(), 0);
}

std::vector<size_t> properDivisors(size_t x) {
	std::vector<size_t> result;
	for(size_t i = 1; i < x/2 + 1; ++i) {
		if(!(x % i)) {
			result.push_back(i);
		}
	}
	return result;
}


	

