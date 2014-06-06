//      Author: jschueths
// Description: Problem 16 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

int main() {
	boost::multiprecision::cpp_int result = 2;

	for(size_t i = 1; i < 1000; ++i) {
		result *= 2;
	}
	size_t sum = 0;
	std::string result_str = result.str();
	for(auto it = result_str.begin(); it != result_str.end(); it++) {
		sum += boost::lexical_cast<size_t>(*it);
	}
	std::cout << "Sum: " << sum << std::endl;
	return 0;
}

