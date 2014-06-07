//      Author: jschueths
// Description: Problem 25 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

int main() {
	boost::multiprecision::cpp_int last = 1;
	boost::multiprecision::cpp_int curr = 1;
	boost::multiprecision::cpp_int next = 1;

	size_t i = 2;
	next = curr;

	for(i = 2; next.str().size() < 1000; ++i) {
		last = curr;
		curr = next;
		next = last + curr;
	}
		  
	std::cout << "Term: " << i << std::endl;
	return 0;
}

