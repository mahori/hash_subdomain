#include <cstddef>
#include <limits>
#include <stdexcept>
#include <gtest/gtest.h>
#include "../src/Hash.hpp"

namespace
{

TEST(HashTest, Constructor_NormalArgument)
{
  Hash sut(17576U);

  std::size_t hash_size = sut.size();

  EXPECT_EQ(hash_size, 17576U);
}

TEST(HashTest, Constructor_NullArgument)
{
  Hash sut;

  std::size_t hash_size = sut.size();

  EXPECT_EQ(hash_size, std::numeric_limits<std::size_t>::max());
}

TEST(HashTest, Constructor_ZeroArgument)
{
  EXPECT_THROW({
      Hash sut(0U);
    },
    std::invalid_argument);
}

TEST(HashTest, Constructor_MaximimIntegerArgument)
{
  Hash sut(std::numeric_limits<std::size_t>::max());

  std::size_t hash_size = sut.size();

  EXPECT_EQ(hash_size, std::numeric_limits<std::size_t>::max());
}

TEST(HashTest, Method_hash_NormalArgument)
{
  Hash sut(17576U);

  std::size_t hash = sut.hash("example.com");

  EXPECT_EQ(hash, 253U);
}

TEST(HashTest, Method_hash_EmptyString)
{
  Hash sut;

  std::size_t hash = sut.hash("");

  EXPECT_EQ(hash, 11160318154034397263U);
}

}  // anonymous namespace
