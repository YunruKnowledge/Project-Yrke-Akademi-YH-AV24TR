#include <gtest/gtest.h>
#include "../lib/greetings.h"

TEST(test_null_name, test_null_name)
{
    EXPECT_EQ(greet(""), "Hello, my friend.");
}

TEST(test_single_name, test_single_name)
{
    EXPECT_EQ(greet("Bob"), "Hello, Bob.");
}

TEST(test_bold_single_name, test_bold_single_name)
{
    EXPECT_EQ(greet("BOB"), "HELLO BOB!");
}

TEST(test_two_name, test_two_name)
{
    EXPECT_EQ(greet("Jill, Jane"), "Hello, Jill and Jane.");
}

TEST(test_two_bold_name, test_two_bold_name)
{
    EXPECT_EQ(greet("BOB, JANE"), "HELLO BOB AND JANE!");
}

TEST(test_multy_name, test_multy_name)
{
    EXPECT_EQ(greet("Amy, Brian, Charlotte"),
              "Hello, Amy, Brian and Charlotte.");
}

TEST(test_multy_bold_name, test_multy_bold_name)
{
    EXPECT_EQ(greet("BRIAN, BOB, JANE"),
              "HELLO BRIAN, BOB AND JANE!");
}

TEST(test_multy_combine_names, test_multy_combine_names)
{
    EXPECT_EQ(greet("Amy, BRIAN, Charlotte"),
              "Hello, Amy and Charlotte. AND HELLO BRIAN!");
}

TEST(test_multy_combine_many_names, test_multy_combine_many_names)
{
    EXPECT_EQ(greet("Amy, BRIAN, Charlotte, BOB, Jill, JANE"),
              "Hello, Amy, Charlotte and Jill. AND HELLO BRIAN, BOB AND JANE!");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}