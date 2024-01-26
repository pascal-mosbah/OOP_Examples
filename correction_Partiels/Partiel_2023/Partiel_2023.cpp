//
#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

template <std::size_t Size1, std::size_t Size2>
auto add(std::array<int, Size1> &array1, std::array<int, Size2> &array2)
{
  constexpr std::size_t size = std::max(Size1, Size2) + 1;
  std::array<int, size> array3;
  std::fill(array3.begin(), array3.end(), 0);
  std::copy(array1.rbegin(), array1.rend(), array3.rbegin());
  auto j = array3.rbegin();
  for (auto i = array2.rbegin(); i != array2.rend(); ++i)
  {
    *j += *i;
    if (*j > 9)
    {
      *j -= 10;
      *(j + 1) += 1;
    }
    ++j;
  }
  return array3;
}

class Big_natural_number
{
private:
  std::vector<unsigned short> tab_;

public:
  Big_natural_number operator+(const Big_natural_number &other) const;
  Big_natural_number operator*(const short unsigned &nb) const;
  Big_natural_number operator*(const Big_natural_number &other) const;
  friend Big_natural_number &operator>>(Big_natural_number &other, const int &nb);
  friend std::ostream &operator<<(std::ostream &os, const Big_natural_number &other);
};

Big_natural_number Big_natural_number::operator*(const short unsigned &nb) const
{
  Big_natural_number result;
  if (nb < 10)
  {
    result.tab_.resize(tab_.size() + 1);
    std::fill(result.tab_.begin(), result.tab_.end(), 0);
    auto j = result.tab_.rbegin();
    short unsigned dummy;
    for (auto i = tab_.rbegin(); i != tab_.rend(); ++i)
    {
      *j += *i * nb;
      if (*j > 9)
      {
        *(j + 1) += *j / 10;
        *j -= *j / 10 * 10;
      }
      ++j;
    }
  }
  else
  {
    std::cerr << "Error Big_natural_number::operator*" << std::endl;
  }
  return result;
}

Big_natural_number Big_natural_number::operator*(const Big_natural_number &other) const
{
  Big_natural_number result;
  result.tab_.resize(tab_.size() + other.tab_.size() + 1);
  std::fill(result.tab_.begin(), result.tab_.end(), 0);
  unsigned shift = 0;
  for (auto i = tab_.rbegin(); i != tab_.rend(); ++i)
  {
    auto tmp = other * (*i);
    for (unsigned j = 0; j < shift; ++j)
    {
      tmp >> 0;
    }
    result = result + tmp;
    ++shift;
  }
  return result;
}

std::ostream &operator<<(std::ostream &os, const Big_natural_number &other)
{
  auto iter = other.tab_.begin();
  while (*iter == 0 && iter != other.tab_.end())
  {
    ++iter;
  }
  while (iter != other.tab_.end())
  {
    os << *iter;
    ++iter;
  }
  return os;
}

Big_natural_number Big_natural_number::operator+(const Big_natural_number &other) const
{
  const std::size_t size = tab_.size() + other.tab_.size() + 1;
  Big_natural_number result;
  result.tab_.resize(size);
  std::fill(result.tab_.begin(), result.tab_.end(), 0);
  std::copy(other.tab_.rbegin(), other.tab_.rend(), result.tab_.rbegin());
  auto j = result.tab_.rbegin();
  for (auto i = tab_.rbegin(); i != tab_.rend(); ++i)
  {
    *j += *i;
    if (*j > 9)
    {
      *j -= 10;
      *(j + 1) += 1;
    }
    ++j;
  }
  return result;
}

Big_natural_number &operator>>(Big_natural_number &other, const int &nb)
{
  if (nb != 0)
  {
    int size = log10(nb) + 1;
    int calc = pow(10, size - 1);
    int nb1 = nb;
    for (int i = 0; i < size; ++i)
    {
      other.tab_.push_back(nb1 / calc);
      nb1 -= nb1 / calc * calc;
      calc /= 10;
    }
  }
  else
  {
    other.tab_.push_back(0);
  }
  return (other);
}

int main()
{
  std::array<int, 5> array1{0, 1, 2, 3, 8};
  std::array<int, 4> array2{0, 1, 2, 3};
  auto result = add(array1, array2);
  auto print = [](auto &elem)
  { std::cout << elem; };
  std::ranges::for_each(array1, print);
  std::cout << " + ";
  std::ranges::for_each(array2, print);
  std::cout << " = ";
  std::ranges::for_each(result, print);
  std::cout << std::endl;
  /****************************/
  Big_natural_number a1;
  a1 >> 123;
  a1 >> 4 >> 5;
  Big_natural_number a2;
  a2 >> 5 >> 3;
  std::cout << "a1 = " << a1 << std::endl;
  std::cout << "a2 = " << a2 << std::endl;
  std::cout << "a3 = " << a1 + a2 << " = " << 12345 + 53 << std::endl;
  std::cout << "a4 = " << a1 * 5 << " = " << 12345 * 5 << std::endl;
  std::cout << "a5 = " << a1 * a2 << " = " << 12345 * 53 << std::endl;
}