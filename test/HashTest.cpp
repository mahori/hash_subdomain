#include <cstddef>
#include <limits>
#include <stdexcept>
#include <gtest/gtest.h>
#include "../src/Hash.hpp"

namespace
{

TEST(HashTest, Method_hash_NormalArgument)
{
  Hash sut;

  std::size_t hash = sut.hash("example.com", 17576U);

  EXPECT_EQ(hash, 253U);
}

TEST(HashTest, Method_hash_Integer_0)
{
  Hash sut;

  EXPECT_THROW({
      std::size_t hash = sut.hash("example.com", 0U);
    },
    std::invalid_argument);
}

TEST(HashTest, Method_hash_Integer_Maximum)
{
  Hash sut;

  std::size_t hash = sut.hash("example.com", std::numeric_limits<std::size_t>::max());

  EXPECT_EQ(hash, 12161068328669395661U);
}

TEST(HashTest, Method_hash_NoIntegerArgument)
{
  Hash sut;

  std::size_t hash = sut.hash("example.com");

  EXPECT_EQ(hash, 12161068328669395661U);
}

TEST(HashTest, Method_hash_EmptyString)
{
  Hash sut;

  std::size_t hash = sut.hash("");

  EXPECT_EQ(hash, 11160318154034397263U);
}

}  // anonymous namespace
