#include <memory>
#include <gtest/gtest.h>
#include "HashMock.hpp"
#include "../src/Subdomain.hpp"

namespace
{

class SubdomainTest
  : public ::testing::Test
{
protected:
  void SetUp(void) override
  {
    mock_ = std::make_shared<HashMock>(17576);
  }

  std::shared_ptr<HashMock> mock_;
};

TEST_F(SubdomainTest, Method_get_ArgumentType_1)
{
  Subdomain sut(mock_, "example.com", 0);

  EXPECT_TRUE(sut.get().empty());
}

TEST_F(SubdomainTest, Method_get_ArgumentType_2)
{
  EXPECT_CALL(*mock_, hash(testing::_))
    .Times(testing::AtLeast(1))
    .WillRepeatedly(testing::Return(253));

  EXPECT_CALL(*mock_, setMax(testing::_))
    .Times(testing::AtLeast(1));

  Subdomain sut(mock_, "example.com", 3);

  EXPECT_EQ(sut.get(), "ajt");
}

}  // anonymous namespace
