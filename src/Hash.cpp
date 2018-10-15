#include "Hash.hpp"
#include <cstddef>
#include <functional>
#include <stdexcept>
#include <string>

Hash::Hash(std::size_t size)
  : size_(size)
{
  if (size_ == 0) {
    throw std::invalid_argument("hash size is 0");
  }
}

std::size_t Hash::hash(const std::string& text) const
{
  std::size_t result = std::hash<std::string>()(text);
  result %= size_;

  return result;
}

std::size_t Hash::size(void) const
{
  return size_;
}
