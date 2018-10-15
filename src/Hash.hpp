#ifndef HASH_H
#define HASH_H

#include <cstddef>
#include <limits>
#include <string>

class Hash
{
public:
  Hash(std::size_t size = std::numeric_limits<std::size_t>::max());
  ~Hash(void) =default;

  std::size_t hash(const std::string& text) const;
  std::size_t size(void) const;

private:
  std::size_t size_;
};

#endif  // HASH_H
