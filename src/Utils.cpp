#include <cstddef>
#include <string>
#include "Utils.hpp"

constexpr char kCharacters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                                'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                                'u', 'v', 'w', 'x', 'y', 'z'};
constexpr std::size_t kSize = sizeof(kCharacters) / sizeof(char);

std::string get_character(std::size_t value, std::size_t current)
{
  current /= kSize;

  if (current < kSize) {
    return std::string(1, kCharacters[value]);
  }

  std::string s(1, kCharacters[value/current]);
  s += get_character(value % current, current);

  return s;
}

std::string get_subdomain(std::size_t hash, std::size_t total)
{
  return get_character(hash, total);
}

std::size_t get_size(void)
{
  return kSize;
}
