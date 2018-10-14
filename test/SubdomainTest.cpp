#include <gtest/gtest.h>
#include "../src/Subdomain.hpp"

namespace
{

TEST(SubdomainTest, Method_get_ArgumentType_1)
{
  Subdomain sut("example.com", 0);

  EXPECT_TRUE(sut.get().empty());
}

TEST(SubdomainTest, Method_get_ArgumentType_2)
{
  Subdomain sut("example.com", 3);

  EXPECT_EQ(sut.get(), "ajt");
}

}  // anonymous namespace
