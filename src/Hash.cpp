#include "Hash.hpp"
#include <cstddef>
#include <functional>
#include <stdexcept>
#include <string>

using invalid_argument = std::invalid_argument;
using size_t           = std::size_t;
using string           = std::string;
using string_hash      = std::hash<std::string>;

Hash::Hash(size_t size)
  : size_(size)
{
  if (size_ == 0) {
    throw invalid_argument("hash size is 0");
  }
}

size_t Hash::hash(const string& text) const
{
  size_t hash = string_hash()(text);
  hash %= size_;

  return hash;
}

size_t Hash::size(void) const
{
  return size_;
}
