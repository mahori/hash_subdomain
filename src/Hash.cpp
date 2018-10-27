#include "Hash.hpp"
#include <cstddef>
#include <functional>
#include <stdexcept>
#include <string>

using namespace std;

Hash::Hash(size_t size)
  : size_(size)
{
  if (size_ == 0) {
    throw invalid_argument("hash size is 0");
  }
}

size_t Hash::hash(const string& text) const
{
  auto value = std::hash<string>()(text);
  value %= size_;

  return value;
}

size_t Hash::size(void) const
{
  return size_;
}
