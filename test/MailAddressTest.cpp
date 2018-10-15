#include <gtest/gtest.h>
#include "../src/MailAddress.hpp"

namespace
{

TEST(MailAddressTest, Method_get)
{
  MailAddress sut("foo", "ajt", "example.com");

  EXPECT_EQ(sut.get(), "foo@ajt.example.com");
}

}  // anonymous namespace
