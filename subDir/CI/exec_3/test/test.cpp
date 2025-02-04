
#include <gtest/gtest.h>
#include "../lib/greet/greet.h"

TEST(GREET_NAMES, Single) {
  EXPECT_EQ(greet("balls"), "Hello balls");
}

