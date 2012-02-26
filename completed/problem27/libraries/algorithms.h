//      Author: jschueths
// Description: A function library for mathematical algorithms.

#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <cmath>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

bool is_prime(long long int x);
string convBase(unsigned long v, long base);

bool isPalindrome(string x);
string convert_to_string(long long int x);
unsigned int HCF(unsigned int n, unsigned int d);
#include "algorithms.hpp"

#endif
