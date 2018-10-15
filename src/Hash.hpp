#ifndef HASH_H
#define HASH_H

#include <cstddef>
#include <limits>
#include <string>

class Hash
{
public:
  Hash(void) =default;
  ~Hash(void) =default;

  std::size_t hash(const std::string& text, std::size_t max = std::numeric_limits<std::size_t>::max()) const;
};

#endif  // HASH_H
