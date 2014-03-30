//      Author: jschueths
// Description: A function library for mathematical algorithms.

#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <iomanip>

using std::string;
using std::stringstream;
using std::vector;
using std::hex;

bool is_prime(long long int x);
string convBase(unsigned long long int v, unsigned long int base);

bool isPalindrome(string x);
string convert_to_string(long long int x);
int convert_to_int(string x);
unsigned int HCF(unsigned int n, unsigned int d);

string english_lookup(long long int n, bool tens);
string num_to_words(long long int n);

unsigned int d_amicable(unsigned int x);

bool is_perfect(unsigned int x);
bool is_deficient(unsigned int x);
bool is_abundant(unsigned int x);

void phi(vector<unsigned long int> &x);

bool is_permutation(unsigned int x, unsigned int y);
bool is_pandigital(string x, unsigned int min, unsigned int max);

bool is_perfect_square(unsigned int x);

unsigned long long int combination(long long int n, long long int r);
unsigned long long int fact(long long int n);
#include "algorithms.hpp"

#endif
