#include <cstddef>
#include <memory>
#include <gtest/gtest.h>
#include "../src/Subdomain.hpp"
#include "../src/Utils.hpp"
#include "MockHash.hpp"

namespace
{

class SubdomainTest
  : public ::testing::Test
{
protected:
  void SetUp(void) override
  {
    mock_ = std::make_shared<MockHash>();
  }

  std::shared_ptr<MockHash> mock_;
};

TEST_F(SubdomainTest, Method_get_ArgumentType_1)
{
  Subdomain<MockHash> sut(0, mock_, "example.com");

  EXPECT_TRUE(sut.get().empty());
}

TEST_F(SubdomainTest, Method_get_ArgumentType_2)
{
  const std::size_t length    = 3;
  const std::size_t hash_size = ::hash_size(length);

  EXPECT_CALL(*mock_, hash(testing::_))
    .Times(testing::AtLeast(1))
    .WillRepeatedly(testing::Return(253));

  EXPECT_CALL(*mock_, size())
    .Times(testing::AtLeast(1))
    .WillRepeatedly(testing::Return(hash_size));

  Subdomain<MockHash> sut(length, mock_, "example.com");

  EXPECT_EQ(sut.get(), "ajt");
}

}  // anonymous namespace
