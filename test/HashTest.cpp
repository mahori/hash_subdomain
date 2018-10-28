#include <cstddef>
#include <limits>
#include <stdexcept>
#include <gtest/gtest.h>
#include "../src/Hash.hpp"

using namespace std;

constexpr const size_t size_t_max = numeric_limits<size_t>::max();

namespace
{

TEST(HashTest, Constructor_NormalArgument)
{
  constexpr size_t hash_size = 17576U;

  Hash sut(hash_size);

  EXPECT_EQ(sut.size(), hash_size);
}

TEST(HashTest, Constructor_NullArgument)
{
  Hash sut;

  EXPECT_EQ(sut.size(), size_t_max);
}

TEST(HashTest, Constructor_ZeroArgument)
{
  constexpr size_t hash_size = 0U;

  EXPECT_THROW({
      Hash sut(hash_size);
    },
    invalid_argument);
}

TEST(HashTest, Constructor_MaximumIntegerArgument)
{
  constexpr size_t hash_size = size_t_max;

  Hash sut(hash_size);

  EXPECT_EQ(sut.size(), hash_size);
}

TEST(HashTest, Method_hash_NormalArgument)
{
  Hash sut(17576U);

  EXPECT_EQ(sut.hash("example.com"), 253U);
}

TEST(HashTest, Method_hash_EmptyString)
{
  Hash sut;

  EXPECT_EQ(sut.hash(""), 11160318154034397263U);
}

}  // anonymous namespace
