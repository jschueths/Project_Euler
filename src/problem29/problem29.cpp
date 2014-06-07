//      Author: jschueths
// Description: Problem 29 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <set>
#include <boost/multiprecision/cpp_int.hpp>

int main() {
	std::set<boost::multiprecision::cpp_int> result;
	for(size_t i = 2; i <= 100; i++) {
		for(size_t j = 2; j <= 100; j++) {
			result.insert(
				boost::multiprecision::pow(
					boost::multiprecision::cpp_int(i), j));
		}
	}

	std::cout << "Total Distint Values: " << result.size() << std::endl;
	return 0;
}

