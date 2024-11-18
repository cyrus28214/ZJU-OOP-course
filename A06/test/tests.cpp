#include <gtest/gtest.h>
#include "Vector.h"
#include <stdexcept> // for std::out_of_range

/**
 * @brief Test suite for the Vector class.
 */
class VectorTest : public ::testing::Test {
};

TEST_F(VectorTest, DefaultConstructor) {
    Vector<int> vec;
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec.size(), 0);
}

TEST_F(VectorTest, ConstructorWithSize) {
    Vector<int> vec(10);
    EXPECT_EQ(vec.size(), 10);
    for (int i = 0; i < vec.size(); ++i) {
        EXPECT_NO_THROW(vec[i]);
    }
}

TEST_F(VectorTest, CopyConstructor) {
    Vector<int> vec1(3);
    vec1.push_back(42);
    Vector<int> vec2(vec1);

    EXPECT_EQ(vec1.size(), vec2.size());
    EXPECT_EQ(vec1[3], vec2[3]);

    vec2[3] = 99;
    EXPECT_NE(vec1[3], vec2[3]); // ensure vec1 is not affected
}

TEST_F(VectorTest, PushBackSimple) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
}

TEST_F(VectorTest, ClearSimple) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    vec.clear();
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec.size(), 0);
}

TEST_F(VectorTest, AtOutOfBounds) {
    Vector<int> vec(2);

    EXPECT_THROW(vec.at(-1), std::out_of_range);
    EXPECT_THROW(vec.at(2), std::out_of_range);
}

TEST_F(VectorTest, DynamicResizing) {
    Vector<int> vec;
    int initial_capacity = 2;
    for (int i = 0; i < 1000; ++i) {
        vec.push_back(i);
        EXPECT_EQ(vec[i], i);
    }
    EXPECT_EQ(vec.size(), 1000);
}

TEST_F(VectorTest, LargeScaleData) {
    Vector<int> vec;
    const int num_elements = 1'000'000;
    for (int i = 0; i < num_elements; ++i) {
        vec.push_back(i);
    }
    EXPECT_EQ(vec.size(), num_elements);
    EXPECT_EQ(vec[0], 0);
    EXPECT_EQ(vec[num_elements - 1], num_elements - 1);
}

TEST_F(VectorTest, MultipleVectorInteraction) {
    Vector<int> vec1(5);
    for (int i = 0; i < 5; ++i) {
        vec1[i] = i * 10;
    }

    Vector<int> vec2 = vec1;
    vec2[0] = 100;

    EXPECT_NE(vec1[0], vec2[0]); // ensure vec1 is not affected

    vec1.push_back(50);
    vec2.push_back(60);

    EXPECT_EQ(vec1.size(), 6);
    EXPECT_EQ(vec2.size(), 6);
    EXPECT_NE(vec1[5], vec2[5]);
}

TEST_F(VectorTest, MixedOperations) {
    Vector<int> vec;

    for (int i = 0; i < 500; ++i) {
        vec.push_back(i);
    }
    EXPECT_EQ(vec.size(), 500);

    vec.clear();
    EXPECT_TRUE(vec.empty());

    for (int i = 500; i < 1000; ++i) {
        vec.push_back(i);
    }
    EXPECT_EQ(vec.size(), 500);

    for (int i = 0; i < 500; ++i) {
        EXPECT_EQ(vec[i], i + 500);
    }
}

TEST_F(VectorTest, ExceptionHandlingStability) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    try {
        vec.at(-1);
    }
    catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "Index out of range");
    }

    try {
        vec.at(3);
    }
    catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "Index out of range");
    }

    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
}

