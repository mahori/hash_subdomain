#include <gtest/gtest.h>
#include "../src/MailAddress.hpp"

namespace
{

TEST(MailAddressTest, Method_get)
{
  MailAddress ma("foo", "ajt", "example.co.jp");

  EXPECT_EQ(ma.get(), "foo@ajt.example.co.jp");
}

}  // anonymous namespace
