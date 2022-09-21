#include "gtest/gtest.h"

TEST(TESTCASE, test0) {
    EXPECT_EQ(0, 1);
}

TEST(TESTCASE, test1) {
    EXPECT_EQ(0, 0);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}