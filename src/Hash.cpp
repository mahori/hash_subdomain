#include "Hash.hpp"
#include <cstddef>
#include <functional>
#include <stdexcept>
#include <string>

std::size_t Hash::hash(const std::string& text, std::size_t max) const
{
  if (max == 0) {
    throw std::invalid_argument("Variable max is 0");
  }

  std::size_t result = std::hash<std::string>()(text);
  result %= max;

  return result;
};
