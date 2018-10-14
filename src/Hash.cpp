#include "Hash.hpp"
#include <cstddef>
#include <functional>

Hash::Hash(std::size_t max)
  : max_(max)
{
}

std::size_t Hash::hash(const std::string& text) const
{
  std::size_t result = std::hash<std::string>()(text);
  result %= max_;

  return result;
};

std::size_t Hash::max(void) const
{
  return max_;
}

void Hash::setMax(size_t value)
{
  max_ = value;
}
