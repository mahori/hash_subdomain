#include <stdexcept>
#include <vector>
#include <gtest/gtest.h>
#include "../src/ProgramOptions.hpp"

using namespace std;

namespace
{

TEST(ProgramOptionsTest, Help)
{
  vector<const char*> args({"hash_subdomain",
                            "--help"});
  ProgramOptions sut(args);

  EXPECT_TRUE(sut.hasHelp());
  EXPECT_FALSE(sut.helpLines().empty());
  EXPECT_EQ(sut.length(), 1);
  EXPECT_TRUE(sut.user().empty());
  EXPECT_TRUE(sut.domain().empty());
}

TEST(ProgramOptionsTest, ArgumentType_1)
{
  vector<const char*> args({"hash_subdomain",
                            "--length", "3",
                            "--user",   "foo",
                            "--domain", "example.co.jp"});
  ProgramOptions sut(args);

  EXPECT_FALSE(sut.hasHelp());
  EXPECT_TRUE(sut.helpLines().empty());
  EXPECT_EQ(sut.length(), 3);
  EXPECT_EQ(sut.user(), "foo");
  EXPECT_EQ(sut.domain(), "example.co.jp");
}

TEST(ProgramOptionsTest, ArgumentType_2)
{
  vector<const char*> args({"hash_subdomain",
                            "--length", "4"});
  ProgramOptions sut(args);

  EXPECT_FALSE(sut.hasHelp());
  EXPECT_TRUE(sut.helpLines().empty());
  EXPECT_EQ(sut.length(), 4);
  EXPECT_TRUE(sut.user().empty());
  EXPECT_TRUE(sut.domain().empty());
}

TEST(ProgramOptionsTest, InvalidOptionValueException)
{
  vector<const char*> args({"hash_subdomain",
                            "--length", "foo"});

  EXPECT_THROW({
      ProgramOptions sut(args);
    },
    invalid_argument);
}

}  // anonymous namespace
