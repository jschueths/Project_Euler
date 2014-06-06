//      Author: jschueths
// Description: Problem 6 of the Euler Project (projecteuler.net/problems)

#include <iostream>

int main() {
	size_t sum_of_squares = 0;
	size_t square_of_sum = 0;
	size_t difference;

	for(size_t i = 0; i <= 100; i++) {
		sum_of_squares += (i * i);
		square_of_sum += i;
	}
	square_of_sum = square_of_sum * square_of_sum;

	difference = square_of_sum - sum_of_squares;

	std::cout << "Difference: " << difference << std::endl;
	return 0;
}
