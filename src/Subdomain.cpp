#include "Subdomain.hpp"
#include <cmath>
#include <cstddef>
#include <functional>
#include <string>

constexpr char kCharacters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                                'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                                'u', 'v', 'w', 'x', 'y', 'z'};
constexpr std::size_t kSize = sizeof(kCharacters) / sizeof(char);

namespace
{

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

}  // anonymous namespace

Subdomain::Subdomain(const std::string& domain, std::size_t length)
  : length_(length)
  , domain_(domain)
{
  hash_ = std::hash<std::string>()(domain_);
  total_ = std::pow(kSize, length_);

  hash_ %= total_;
}

std::string Subdomain::get(void) const
{
  if (length_) {
    return get_subdomain(hash_, total_);
  } else {
    return "";
  }
}
