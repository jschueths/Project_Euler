//      Author: jschueths
// Description: Problem 4 of the Euler Project (projecteuler.net/problems)

#include <algorithm>
#include <string>
#include <iostream>
#include <boost/lexical_cast.hpp>

bool isPalindrome(std::string x) {
	std::string reversed = x;
	std::reverse_copy(x.begin(), x.end(), reversed.begin());
	return x == reversed;
}

int main() {
	size_t largest = 0;
	for(int i = 999; i >= 100; --i) {
		for(int j = 999; j >= i; --j) {
			size_t product = i * j;
			// If the current product is a palindrome, save it as the largest found.
			if(isPalindrome(boost::lexical_cast<std::string>(product)) && product > largest) {
				largest = product;
			}
		}
	}
	std::cout << "Largest Palindrome: " << largest << std::endl;
	return 0;
}

