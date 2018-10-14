#include <gtest/gtest.h>
#include "../src/MailAddress.hpp"

namespace
{

TEST(MailAddressTest, Method_get)
{
  MailAddress sut("foo", "ajt", "example.co.jp");

  EXPECT_EQ(sut.get(), "foo@ajt.example.co.jp");
}

}  // anonymous namespace
