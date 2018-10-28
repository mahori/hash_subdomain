#include "Utils.hpp"
#include <cmath>
#include <cstddef>
#include <sstream>
#include <string>

using namespace std;

constexpr const char kAlphabets[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                                     'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                                     'u', 'v', 'w', 'x', 'y', 'z'};
constexpr const size_t kNumberOfAlphabets = sizeof(kAlphabets) / sizeof(char);

string get_alphabet(size_t value, size_t current)
{
  current /= kNumberOfAlphabets;

  if (current < kNumberOfAlphabets) {
    return string(1, kAlphabets[value]);
  }

  ostringstream s;
  s << kAlphabets[value/current];
  s << ::get_alphabet(value % current, current);

  return s.str();
}

string get_alphabets(size_t hash_size, size_t hash_value)
{
  return ::get_alphabet(hash_value, hash_size);
}

size_t hash_size(size_t length)
{
  return ::pow(kNumberOfAlphabets, length);
}
