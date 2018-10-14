#include <array>
#include <gtest/gtest.h>
#include "../src/ProgramOptions.hpp"

namespace
{

TEST(ProgramOptionsTest, Help)
{
  std::array<char*, 2> argv({"hash_subdomain",
                             "--help"});
  ProgramOptions sut(argv.size(), argv.data());

  EXPECT_TRUE(sut.hasHelp());
  EXPECT_FALSE(sut.helpLines().empty());
  EXPECT_EQ(sut.length(), 1);
  EXPECT_TRUE(sut.user().empty());
  EXPECT_TRUE(sut.domain().empty());
}

TEST(ProgramOptionsTest, ArgumentType_1)
{
  std::array<char*, 7> argv({"hash_subdomain",
                             "--length", "3",
                             "--user",   "foo",
                             "--domain", "example.co.jp"});
  ProgramOptions sut(argv.size(), argv.data());

  EXPECT_FALSE(sut.hasHelp());
  EXPECT_TRUE(sut.helpLines().empty());
  EXPECT_EQ(sut.length(), 3);
  EXPECT_EQ(sut.user(), "foo");
  EXPECT_EQ(sut.domain(), "example.co.jp");
}

TEST(ProgramOptionsTest, ArgumentType_2)
{
  std::array<char*, 3> argv({"hash_subdomain",
                             "--length", "4"});
  ProgramOptions sut(argv.size(), argv.data());

  EXPECT_FALSE(sut.hasHelp());
  EXPECT_TRUE(sut.helpLines().empty());
  EXPECT_EQ(sut.length(), 4);
  EXPECT_TRUE(sut.user().empty());
  EXPECT_TRUE(sut.domain().empty());
}

}  // anonymous namespace
