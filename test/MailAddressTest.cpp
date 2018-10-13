#include <gtest/gtest.h>
#include "../src/MailAddress.hpp"

namespace
{
class MailAddressTest
  : public ::testing::Test
{
protected:
  MailAddressTest(void) {}
  ~MailAddressTest(void) override {}

  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(MailAddressTest, get)
{
  MailAddress mailAddress("foo", "ajt", "example.co.jp");
  EXPECT_EQ(mailAddress.get(), "foo@ajt.example.co.jp");
}

}
