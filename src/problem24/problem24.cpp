//      Author: jschueths
// Description: Problem 24 of the Euler Project (projecteuler.net/problems)

#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const size_t MAX_ITERATIONS = 1000000;

int main(){
	clock_t start, end;
	start = clock();
	
	string digits = "0123456789";
	for(size_t i = 0; i <= MAX_ITERATIONS; i++){
		next_permutation(digits.begin(), digits.end());
	}
	end = clock();
  	
	cout << digits << endl;
	cout << "Time elapsed: " << ((double) end - start) / CLOCKS_PER_SEC << endl;
	return 0;
}

