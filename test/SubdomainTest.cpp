#include <cmath>
#include <cstddef>
#include <memory>
#include <gtest/gtest.h>
#include "HashMock.hpp"
#include "../src/Subdomain.hpp"
#include "../src/Utils.hpp"

namespace
{

TEST(SubdomainTest, Method_get_ArgumentType_1)
{
  std::shared_ptr<HashMock> mock = std::make_shared<HashMock>();

  Subdomain<HashMock> sut(mock, "example.com", 0);

  EXPECT_TRUE(sut.get().empty());
}

TEST(SubdomainTest, Method_get_ArgumentType_2)
{
  std::size_t length = 3;
  std::size_t hash_size = ::hash_size(length);
  std::shared_ptr<HashMock> mock = std::make_shared<HashMock>(hash_size);

  EXPECT_CALL(*mock, hash(testing::_))
    .Times(testing::AtLeast(1))
    .WillRepeatedly(testing::Return(253));

  EXPECT_CALL(*mock, size())
    .Times(testing::AtLeast(1))
    .WillRepeatedly(testing::Return(hash_size));

  Subdomain<HashMock> sut(mock, "example.com", length);

  EXPECT_EQ(sut.get(), "ajt");
}

}  // anonymous namespace
