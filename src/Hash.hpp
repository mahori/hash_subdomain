#ifndef HASH_H
#define HASH_H

#include <cstddef>
#include <limits>
#include <string>

class Hash
{
public:
  Hash(std::size_t max = std::numeric_limits<std::size_t>::max());
  virtual ~Hash(void) =default;

  virtual std::size_t hash(const std::string& text) const;

  virtual std::size_t max(void) const;
  virtual void setMax(size_t value);

private:
  std::size_t max_;
};

#endif  // HASH_H
