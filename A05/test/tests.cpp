#include "Fraction.h"
#include <gtest/gtest.h>

TEST(SampleTest, AssertionTrue) {
    EXPECT_TRUE(true);
}

TEST(SampleTest2, AssertionTrue) {
    EXPECT_TRUE(true);
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}