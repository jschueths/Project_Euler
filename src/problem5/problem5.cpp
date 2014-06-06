//      Author: jschueths
// Description: Problem 5 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <boost/math/common_factor.hpp>

int main() {
	size_t result = boost::math::lcm(1, 2);
	for(size_t i = 3; i <= 20; ++i){
		result = boost::math::lcm(result, i);
	}
	std::cout << "LCM of [1, 20]: " << result << std::endl;
	return 0;
}
