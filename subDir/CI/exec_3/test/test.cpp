
#include "greet.h"
#include <gtest/gtest.h>

TEST(MISC, Empty) { EXPECT_EQ(greet(""), "Hello, my friend."); }

TEST(Undercase, Single) { EXPECT_EQ(greet("balls"), "Hello balls."); }

TEST(Undercase, Multi_double) {
  EXPECT_EQ(greet("balls, falls"), "Hello balls and falls.");
}

TEST(Undercase, Multi_triple) {
  EXPECT_EQ(greet("balls, falls, malls"), "Hello balls, falls and malls.");
}

TEST(Uppercase, Single) { EXPECT_EQ(greet("FUMO"), "HELLO FUMO!"); }
TEST(Uppercase, Multi_double) {
  EXPECT_EQ(greet("WALLS, HALLS"), "HELLO WALLS AND HALLS!");
}
TEST(Uppercase, Multi_triple) {
  EXPECT_EQ(greet("FUMO, WALLS, BALLS"), "HELLO FUMO, WALLS AND BALLS!");
}

TEST(Mixed_case, Multi_hexa) {
  EXPECT_EQ(greet("Fumo, WUMO, Dumo, SUMO, Sunno, FALTER"),
            "Hello Fumo, Dumo and Sunno. AND HELLO WUMO, SUMO AND FALTER!");
}

int main(int argc, char const *argv[]) {
  ::testing::InitGoogleTest(&argc, const_cast<char **>(argv));
  return RUN_ALL_TESTS();
}
