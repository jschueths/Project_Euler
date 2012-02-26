//      Author: jschueths
// Description: A function library for mathematical algorithms.

#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <cmath>
#include <string>
#include <sstream>
#include <cstdlib>

using std::string;
using std::stringstream;

bool is_prime(long long int x);
string convBase(unsigned long v, long base);

bool isPalindrome(string x);
string convert_to_string(long long int x);
int convert_to_int(string x);
unsigned int HCF(unsigned int n, unsigned int d);

string english_lookup(long long int n, bool tens);
string num_to_words(long long int n);

unsigned int d_amicable(unsigned int x);

#include "algorithms.hpp"

#endif
