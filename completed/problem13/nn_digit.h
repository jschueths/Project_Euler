//      Author: jschueths
// Description: A library to deal with large natural numbers that are too large for
//            the compiler to handle on its own.

#ifndef __NN_DIGIT_H__
#define __NN_DIGIT_H__

#include <string>
#include <deque>
#include <iostream>
#include <cstdlib>

using std::istream;
using std::ostream;
using std::string;
using std::deque;


class NN_DIGIT
{
  public:
    NN_DIGIT();
    NN_DIGIT(const NN_DIGIT &src);
    NN_DIGIT(const unsigned int &src);
    NN_DIGIT(const string &src);
    ~NN_DIGIT();
    
    NN_DIGIT& operator+=(const NN_DIGIT &rhs);
    const NN_DIGIT operator+(const NN_DIGIT &rhs) const;
    
    NN_DIGIT& operator*=(const int &rhs);
    const NN_DIGIT operator*(const int &rhs) const;
    
    NN_DIGIT& operator*=(const NN_DIGIT &rhs);
    const NN_DIGIT operator*(const NN_DIGIT &rhs) const;
    
    const NN_DIGIT power(const unsigned int y) const;
    
    int& operator[](const unsigned int i);
    const int& operator[](const unsigned int i) const;
    
    NN_DIGIT& operator=(const NN_DIGIT &rhs);
    
    friend istream& operator>>(istream& in, NN_DIGIT &data);
    friend ostream& operator<<(ostream& out, const NN_DIGIT &data);
    
    bool operator==(const NN_DIGIT &rhs) const;
    bool operator!=(const NN_DIGIT &rhs) const;
    
    
    
    unsigned int size();
    
  private:
    deque<int> m_digit;
    int get_int(const char &character) const;
};
  
#endif
