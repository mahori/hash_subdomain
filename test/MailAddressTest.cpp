#include <memory>
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

  void SetUp(void) override
  {
    mailAddress_ = std::make_shared<MailAddress>("foo", "ajt", "example.co.jp");
  }

  void TearDown(void) override {}

  std::shared_ptr<MailAddress> mailAddress_;
};

TEST_F(MailAddressTest, get)
{
  EXPECT_EQ(mailAddress_->get(), "foo@ajt.example.co.jp");
}

}  // anonymous namespace
