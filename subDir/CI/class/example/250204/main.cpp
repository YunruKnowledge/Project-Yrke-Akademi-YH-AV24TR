#include <gtest/gtest.h>
void func(int _a) {
  if (_a == 2) {
    exit(1);
  } else {
    std::cerr << "ahh" ;
    exit(4);
  }
}

TEST(SuiteName, TestName) {
  EXPECT_EQ(1,1);
}
TEST(SuiteName, Bruam) {
  
}

TEST(SuiteName_DeathTest, death_lmao) {
  EXPECT_DEATH(func(2), "Bad Thing.*");
}
TEST(SuiteName_DeathTest, death_2) {
  EXPECT_EXIT(func(2), ::testing::ExitedWithCode(1), "Bad Thing.*");
}