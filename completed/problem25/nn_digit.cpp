
#include "nn_digit.h"

NN_DIGIT::NN_DIGIT()
{
}

NN_DIGIT::NN_DIGIT(const NN_DIGIT &src)
{
  m_digit = src.m_digit;
}

NN_DIGIT::NN_DIGIT(const unsigned int &src)
{
  unsigned int carry = src;
  while(carry != 0)
  {
    m_digit.push_back(carry % 10);
    carry = carry / 10;
  }
}

NN_DIGIT::NN_DIGIT(const string &src)
{
  unsigned int length = src.length();
  for(unsigned int i = 0; i < length; i++)
    m_digit.push_front(get_int(src[i]));
}

NN_DIGIT::~NN_DIGIT(){}

NN_DIGIT& NN_DIGIT::operator+=(const NN_DIGIT &rhs)
{
  deque<int> sum, temp;
  deque<int>::iterator i1; 
  deque<int>::iterator i2;
  int carry = 0;
  int result;
  int x1, x2;
  temp = rhs.m_digit;
  unsigned int length = m_digit.size();
  if(rhs.m_digit.size() > m_digit.size())
    length = rhs.m_digit.size();
    
  i1 = m_digit.begin();
  i2 = temp.begin();
  
  for(unsigned int i = 0; i < length; i++)
  {
    if(i1 == m_digit.end())
      x1 = 0;
    else
      x1 = *i1;
    if(i2 == temp.end())
      x2 = 0;
    else
      x2 = *i2;
    result = x1 + x2 + carry;
    carry = result / 10;
    sum.push_back(result % 10);
    if(i1 != m_digit.end())
      i1++;
    if(i2 != temp.end())
      i2++;
    if(i == length - 1 && carry != 0)
      length++;
  }
  
  m_digit = sum;
  return *this;
}

const NN_DIGIT NN_DIGIT::operator+(const NN_DIGIT &rhs) const
{
  NN_DIGIT result = *this;
  result += rhs;
  return result;
}

NN_DIGIT& NN_DIGIT::operator=(const NN_DIGIT &rhs)
{
  if(this != &rhs)
  {
    m_digit = rhs.m_digit;
  }
  return *this;
}

int& NN_DIGIT::operator[](const unsigned int i)
{
  if(i >= m_digit.size())
  {
    std::cerr << "Invalid Index!" << std::endl;
  }
  return m_digit[i];
}

unsigned int NN_DIGIT::size()
{
  return m_digit.size();
}

const int& NN_DIGIT::operator[](const unsigned int i) const
{
  if(i >= m_digit.size())
  {
    std::cerr << "Invalid Index!" << std::endl;
  }
  return m_digit[i];
}

istream& operator>>(istream& in, NN_DIGIT &data)
{
  string temp;
  in >> temp;
  NN_DIGIT tempDigit(temp);
  data = temp;
  return in;
}

ostream& operator<<(ostream& out, const NN_DIGIT &data)
{
  unsigned int length = data.m_digit.size();
  for(unsigned int i = length - 1; i > 0; i--)
    out << data.m_digit[i];
  out << data.m_digit[0];
  return out;
}

int NN_DIGIT::get_int(const char &character) const
{
  int result;
  switch(character)
  {
    case '0':
      result = 0;
      break;
    case '1':
      result = 1;
      break;
    case '2':
      result = 2;
      break;
    case '3':
      result = 3;
      break;
    case '4':
      result = 4;
      break;
    case '5':
      result = 5;
      break;
    case '6':
      result = 6;
      break;
    case '7':
      result = 7;
      break;
    case '8':
      result = 8;
      break;
    case '9':
      result = 9;
      break;
  }
  return result;
}

NN_DIGIT& NN_DIGIT::operator*=(const int &rhs)
{
  int carry = 0;
  int result;
  int x;
  deque<int>::iterator it = m_digit.begin();
  deque<int> product;
  unsigned int length = m_digit.size();
  for(unsigned int i = 0; i < length; i++)
  {
    if(it == m_digit.end())
      x = 0;
    else
      x = *it;
    result = carry + (rhs * x);
    product.push_back(result % 10);
    carry = result / 10;
    it++;
    if(it == m_digit.end() && carry != 0)
      length++;
  }

  m_digit = product;
  return *this;
}

const NN_DIGIT NN_DIGIT::operator*(const int &rhs) const
{
  NN_DIGIT result = *this;
  result *= rhs;
  return result;
}

bool NN_DIGIT::operator==(const NN_DIGIT &rhs) const
{
  unsigned int length = m_digit.size();
  if(length != rhs.m_digit.size())
    return false;
  for(unsigned int i = 0; i < length; i++)
  {
    if(m_digit[i] != rhs.m_digit[i])
      return false;
  }
  return true;
}

bool NN_DIGIT::operator!=(const NN_DIGIT &rhs) const
{
  return !(*this == rhs);
}

