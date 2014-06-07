//      Author: jschueths
// Description: Problem 20 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>

boost::multiprecision::cpp_int factorial(boost::multiprecision::cpp_int x) {
	if(x == 0) {
		return 1;
	}
	return x * factorial(x-1);
}

int main() {
	size_t sum = 0;
	boost::multiprecision::cpp_int fact = factorial(100);
	std::string factString = fact.str();
	for(auto it = factString.begin(); it != factString.end(); it++) {
		sum += boost::lexical_cast<size_t>(*it);
	}
  
	std::cout << "Sum: " << sum << std::endl;
	return 0;
}

