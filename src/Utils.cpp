#include <cmath>
#include <cstddef>
#include <string>
#include "Utils.hpp"

constexpr char kAlphabets[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                                'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                                'u', 'v', 'w', 'x', 'y', 'z'};
constexpr std::size_t kNumberOfAlphabets = sizeof(kAlphabets) / sizeof(char);

std::string get_alphabet(std::size_t value, std::size_t current)
{
  current /= kNumberOfAlphabets;

  if (current < kNumberOfAlphabets) {
    return std::string(1, kAlphabets[value]);
  }

  std::string s(1, kAlphabets[value/current]);
  s += get_alphabet(value % current, current);

  return s;
}

std::string get_alphabets(std::size_t hash_size, std::size_t hash_value)
{
  return ::get_alphabet(hash_value, hash_size);
}

std::size_t number_of_alphabets(void)
{
  return kNumberOfAlphabets;
}

std::size_t hash_size(std::size_t length)
{
  return std::pow(kNumberOfAlphabets, length);
}
