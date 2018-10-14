#include <limits>
#include <gtest/gtest.h>
#include "../src/Hash.hpp"

namespace
{

TEST(HashTest, NullConstractor)
{
  Hash sut;

  EXPECT_EQ(sut.max(), std::numeric_limits<std::size_t>::max());
}

TEST(HashTest, Constractor)
{
  Hash sut(12345);

  EXPECT_EQ(sut.max(), 12345);
}

TEST(HashTest, Getter_Setter)
{
  Hash sut;
  sut.setMax(12345);

  EXPECT_EQ(sut.max(), 12345);
}

TEST(HashTest, Method_hash)
{
  Hash sut(17576);

  std::size_t hash = sut.hash("example.com");

  EXPECT_EQ(hash, 253);
}

}  // anonymous namespace
