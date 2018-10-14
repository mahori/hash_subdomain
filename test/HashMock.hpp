#ifndef HASH_MOCK_H
#define HASH_MOCK_H

#include <cstddef>
#include <string>
#include <gmock/gmock.h>
#include "../src/Hash.hpp"

class HashMock
  : public Hash
{
public:
  HashMock(std::size_t max)
    : Hash(max)
  {
  }

  MOCK_CONST_METHOD1(hash, std::size_t(const std::string&));

  MOCK_CONST_METHOD0(max, std::size_t(void));
  MOCK_METHOD1(setMax, void(std::size_t));
};

#endif  // HASH_MOCK_H
