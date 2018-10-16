#ifndef MOCK_HASH_H
#define MOCK_HASH_H

#include <cstddef>
#include <string>
#include <gmock/gmock.h>

class MockHash
{
public:
  MockHash(void) =default;
  ~MockHash(void) =default;

  MOCK_CONST_METHOD1(hash, std::size_t(const std::string&));
  MOCK_CONST_METHOD0(size, std::size_t(void));
};

#endif  // MOCK_HASH_H
