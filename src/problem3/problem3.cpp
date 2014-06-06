//      Author: jschueths
// Description: Problem 3 of the Euler Project (projecteuler.net/problems)

#include <iostream>
#include <prime.h>
#include <set>

using std::cout;
using std::endl;

int main() {
	size_t num = 600851475143; // Num provided by the problem.

	std::set<size_t> factors = primeFactors(num);
	cout << "Largest Prime Factor: " << *(factors.rbegin()) << endl;
	return 0;
}
