#include <cstddef>
#include <memory>
#include <gtest/gtest.h>
#include "../src/Subdomain.hpp"
#include "../src/Utils.hpp"
#include "MockHash.hpp"

using namespace std;
using namespace testing;

namespace
{

class SubdomainTest
  : public Test
{
protected:
  void SetUp(void) override
  {
    mock_ = make_shared<MockHash>();
  }

  shared_ptr<MockHash> mock_;
};

TEST_F(SubdomainTest, Method_get_ArgumentType_1)
{
  Subdomain<MockHash> sut(0, mock_, "example.com");

  EXPECT_TRUE(sut.get().empty());
}

TEST_F(SubdomainTest, Method_get_ArgumentType_2)
{
  constexpr size_t length    = 3;
  auto             hash_size = ::hash_size(length);

  EXPECT_CALL(*mock_, hash(_))
    .Times(AtLeast(1))
    .WillRepeatedly(Return(253));

  EXPECT_CALL(*mock_, size())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(hash_size));

  Subdomain<MockHash> sut(length, mock_, "example.com");

  EXPECT_EQ(sut.get(), "ajt");
}

}  // anonymous namespace
