#ifndef HASH_MOCK_H
#define HASH_MOCK_H

#include <cstddef>
#include <string>
#include <gmock/gmock.h>

class HashMock
{
public:
  HashMock(std::size_t size = std::numeric_limits<std::size_t>::max())
    : size_(size)
  {
  }

  ~HashMock(void) =default;

  MOCK_CONST_METHOD1(hash, std::size_t(const std::string&));
  MOCK_CONST_METHOD0(size, std::size_t(void));

private:
  std::size_t size_;
};

#endif  // HASH_MOCK_H
