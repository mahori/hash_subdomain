#ifndef HASH_MOCK_H
#define HASH_MOCK_H

#include <cstddef>
#include <string>
#include <gmock/gmock.h>

class HashMock
{
public:
  HashMock(void) =default;
  ~HashMock(void) =default;

  MOCK_CONST_METHOD2(hash, std::size_t(const std::string&, std::size_t));
};

#endif  // HASH_MOCK_H
