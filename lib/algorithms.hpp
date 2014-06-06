//      Author: jschueths
// Description: Implementation of mathematical algorithms.


bool is_prime(long long int x)
{
  long long int i = 1;
  if(x == 2 || x == 3)
    return true;
  if(!(x % 2) || !(x % 3) || x <= 1)
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

bool is_perfect_square(unsigned long long int x)
{
  bool result = true;
  long double temp = sqrt((double) x);
  //std::cout << "Temp: " << temp << "\t floor(temp): " << floor(temp) << endl;
  if((temp - floor(temp)) > 0)
    result = false;
 // std::cout << std::boolalpha << result << endl;
  return result;
}

bool is_perfect_cube(unsigned long long int x)
{
  bool result = true;
  unsigned long long int upper_limit = sqrt(x);
  for(unsigned long long int i = 1; i < upper_limit; i++)
  {
    if(i * i * i == x)
      return true;
  }
  return false;
}

string convBase(unsigned long long int v, unsigned long int base)
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

unsigned int d_amicable(unsigned int x)
{
  unsigned int sum = 0;
  for(unsigned int i = x / 2; i > 0; i--)
  {
    if(!(x % i))
      sum += i;
  }
  return sum;
}

bool is_perfect(unsigned int x)
{
  if(d_amicable(x) == x)
    return true;
  return false;
}

bool is_deficient(unsigned int x)
{
  if(d_amicable(x) < x)
    return true;
  return false;
}

bool is_abundant(unsigned int x)
{
  if(d_amicable(x) > x)
    return true;
  return false;
}

void phi(vector<unsigned long int> &x)
{
  unsigned int size = x.size();
  for(unsigned int i = 2; i < size; i++)
  {
    if(x[i] == i)
    {
      for(unsigned int n = i; n < size; n += i)
        x[n] = x[n] / i * (i - 1);
    }
  }
  return;
}

unsigned long long int phi(unsigned long long int x)
{
  unsigned long long int result = x;
  unsigned long long int new_x = x;
  
  if(is_prime(x))
  {
    if(!(x % 2))
      new_x -= (new_x / 2);
    for(unsigned long long int i = 3; i <= x; i += 2)
    {
      if(!is_prime(i))
        continue;
      if(!(x % i))
      {
        new_x -= (new_x / i);
      }
    }
    return new_x;
  }
  else
  {
    for(unsigned long long i = 2; i < new_x; i++)
    {
      if(is_prime(i) && (x % i == 0))
      {
        result *= i - 1;//phi(i);
        result /= i;
      }
    } 
  }
  return result;
}

string convert_to_string(unsigned long long int x)
{
  stringstream oss;
  oss << x;
  return oss.str();
}

long long int convert_to_int(string x)
{
  return (atoi(x.c_str()));
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

unsigned int gcd(unsigned int n, unsigned int d)
{
  if(n == 0)
    return d;
  
  return gcd(d % n, n);
}

bool is_pandigital(string x, unsigned int min, unsigned int max)
{
  string input = x;
  string temp;
  size_t position;
  for(unsigned int i = max; i >= min; i--)
  {
    temp = convert_to_string(i);
    position = input.find(temp);
    if(position == string::npos)
      return false;
    input.replace(position, temp.length(), "");
  }
  if(input.length() != 0)
    return false;
  return true;
}

string num_to_words(long long int n)
{
  long long num = n;
  string output = "";
  if(num < 0)
    output += "negative ";
  if(num >= 1000)
  {
    output += english_lookup(num / 1000, 0);
    if(n % 1000)
      output += " thousand ";
    else
      output += " thousand";
    num = num % 1000;
  }
  if(num >= 100)
  {
    output += english_lookup(num / 100, 0);
    if(num % 100)
      output += " hundred and ";
    else
      output += " hundred";
    num = num % 100;
  }
  if(num >= 20)
  {
    output += english_lookup(num / 10, 1);
    num = num % 10;
    if(num != 0)
      output += "-";
  }
  if(num > 0)
  {
    output += english_lookup(num, 0);
  }
  return output;
}

string english_lookup(long long int n, bool tens)
{
  if(!tens)
  {
    switch(n)
    {
      case 0:
        return 0;
      case 1:
        return "one";
      case 2:
        return "two";
      case 3:
        return "three";
      case 4:
        return "four";
      case 5:
        return "five";
      case 6:
        return "six";
      case 7:
        return "seven";
      case 8:
        return "eight";
      case 9:
        return "nine";
      case 10:
        return "ten";
      case 11:
        return "eleven";
      case 12:
        return "twelve";
      case 13:
        return "thirteen";
      case 14:
        return "fourteen";
      case 15:
        return "fifteen";
      case 16:
        return "sixteen";
      case 17:
        return "seventeen";
      case 18:
        return "eighteen";
      case 19:
        return "nineteen";
    }
  }
  if(tens)
  {
    switch(n)
    {
      case 2:
        return "twenty";
      case 3:
        return "thirty";
      case 4:
        return "forty";
      case 5:
        return "fifty";
      case 6:
        return "sixty";
      case 7:
        return "seventy";
      case 8:
        return "eighty";
      case 9:
        return "ninety";
    }
  }
  return "zero";
}

bool is_permutation(unsigned int x, unsigned int y)
{
  string x_string;
  string y_string;
  x_string = convert_to_string(x);
  y_string = convert_to_string(y);
  unsigned int x_size = x_string.length();
  unsigned int y_size = y_string.length();
  if(x_size != y_size)
    return false;
  for(unsigned int i = 0; i < x_size; i++)
  {
    bool found = false;
    for(unsigned int j = 0; j < y_size; j++)
    {
      if(x_string[i] == y_string[j])
      {
        found = true;
        y_string.erase(j, 1);
        y_size = y_string.size();
        break;
      }
    }
    if(!found)
    {
      return false;
    }
  }
  if(y_size != 0)
  {
    return false;
  }
  return true;
}

unsigned long long int combination(long long int n, long long int r)
{
  unsigned long long int n_fact;
  unsigned long long int n_r_fact;
  unsigned long long int result = n;
  unsigned long long int temp;
  if(n == r || r == 0)
    return 1;
  
  if(r == 1)
    return n;
  
  if((n - r) > r)
  {
    n_r_fact = fact(r);
    r = n - r;
  }
  else
  {
    n_r_fact = fact(n - r);
  }
  
  for(unsigned long long int i = result - 1; i > r; i--)
    result *= i;

  if(n == 100 && r == 50)
  {
    std::cout << result << "\t" << n_r_fact << std::endl;
  }
  
  return (result / n_r_fact);
}

unsigned long long int fact(long long int n)
{
  unsigned long long int result = n;
  
  if(n == 0)
    return 1;
  result = n * (fact(n - 1));
  
  return result;
}
