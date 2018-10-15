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
  HashMock(void) =default;
  ~HashMock(void) override =default;

  MOCK_CONST_METHOD2(hash, std::size_t(const std::string&, std::size_t));
};

#endif  // HASH_MOCK_H
