//      Author: jschueths
// Description: Problem 1 of the Euler Project (projecteuler.net/problems)

#include <iostream>

const size_t MAX_ITERATIONS = 1000;

bool isMultipleOf(size_t base, size_t value) {
	return !(value % base);
}

int main(){
	size_t sum = 0;
	for(size_t i = 0; i < MAX_ITERATIONS; i++){
		// If the number is a multiple of 3, 5, or both, add it to the sum.
		if(isMultipleOf(3, i) || isMultipleOf(5, i)){
			sum += i;
		}
	}
	std::cout << "The sum of all the natural numbers below one thousand that are multiples of 3 or 5" << std::endl;
	std::cout << "Sum: " << sum << std::endl;
	return 0;
}

