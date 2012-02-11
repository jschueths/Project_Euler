//      Author: jschueths
// Description: Implementation of mathematical algorithms.


bool is_prime(unsigned long long int x)
{
  unsigned long long int i = 1;
  if(x == 2 || x == 3)
    return true;
  if(!(x % 2) || !(x % 3) || !x || x == 1)
    return false;
  while((6 * i) - 1 < sqrt(x) + 1)
  {
    if(!(x % ((6*i) + 1)))
      return false;
    if(!(x % ((6*i) - 1)))
      return false;
    i++;
  }
  return true;
}

string convBase(unsigned long v, long base)
{
  string digits = "0123456789abcdef";
  string result;
  if((base < 2) || (base > 16))
  {
    result = "Error: base out of range.";
  }
  else
  {
    do
    {
      result = digits[v % base] + result;
      v /= base;
    }while(v);
  }
  return result;
}

bool isPalindrome(string x)
{
  string reversed = x;
  int size = x.length();
  for(int i = size - 1, j = 0; i >= 0, j < size; j++, i--)
  {
    reversed[j] = x[i];
  }
  return (x == reversed);
}

string convert_to_string(long long int x)
{
  stringstream oss;
  oss << x;
  return oss.str();
}

unsigned int HCF(unsigned int n, unsigned int d)
{
  unsigned int result = d % n;
  unsigned int x1, x2;

  x1 = d;
  x2 = n;
  while(true)
  {
    result = x1 % x2;
    if(result == 0)
    {
      result = x2;
      break;
    }
    x1 = x2;
    x2 = result;
  }
  return result;
}
