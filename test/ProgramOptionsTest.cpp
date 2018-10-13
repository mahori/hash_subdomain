#include <array>
#include <gtest/gtest.h>
#include "../src/ProgramOptions.hpp"

namespace
{

TEST(ProgramOptionsTest, Help)
{
  std::array<char*, 2> argv({"hash_subdomain",
                             "--help"});
  ProgramOptions po(argv.size(), argv.data());

  EXPECT_TRUE(po.hasHelp());
  EXPECT_FALSE(po.helpLines().empty());
  EXPECT_EQ(po.length(), 1);
  EXPECT_TRUE(po.user().empty());
  EXPECT_TRUE(po.domain().empty());
}

TEST(ProgramOptionsTest, ArgumentType_1)
{
  std::array<char*, 7> argv({"hash_subdomain",
                             "--length", "3",
                             "--user",   "foo",
                             "--domain", "example.co.jp"});
  ProgramOptions po(argv.size(), argv.data());

  EXPECT_FALSE(po.hasHelp());
  EXPECT_TRUE(po.helpLines().empty());
  EXPECT_EQ(po.length(), 3);
  EXPECT_EQ(po.user(), "foo");
  EXPECT_EQ(po.domain(), "example.co.jp");
}

TEST(ProgramOptionsTest, ArgumentType_2)
{
  std::array<char*, 3> argv({"hash_subdomain",
                             "--length", "4"});
  ProgramOptions po(argv.size(), argv.data());

  EXPECT_FALSE(po.hasHelp());
  EXPECT_TRUE(po.helpLines().empty());
  EXPECT_EQ(po.length(), 4);
  EXPECT_TRUE(po.user().empty());
  EXPECT_TRUE(po.domain().empty());
}

}  // anonymous namespace
