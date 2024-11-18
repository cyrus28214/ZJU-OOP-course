#include <gtest/gtest.h>
#include <iostream>
#include "Fraction.h"

// Test case for constructor with valid input (numerator and denominator)
TEST(FractionTest, ConstructorValidInput) {
    // Test valid fraction
    Fraction f1(3, 4);
    EXPECT_EQ(f1.get_numerator(), 3);
    EXPECT_EQ(f1.get_denominator(), 4);

    // Test negative denominator
    Fraction f2(-3, 4);
    EXPECT_EQ(f2.get_numerator(), -3);
    EXPECT_EQ(f2.get_denominator(), 4);

    // Test zero denominator, should throw exception
    EXPECT_THROW(Fraction(3, 0), std::invalid_argument);
}

// Test constructor with decimal input
TEST(FractionTest, ConstructorFromDecimal) {
    Fraction f1("0.75");
    EXPECT_EQ(f1.get_numerator(), 3);
    EXPECT_EQ(f1.get_denominator(), 4);

    Fraction f2("-1.25");
    EXPECT_EQ(f2.get_numerator(), -5);
    EXPECT_EQ(f2.get_denominator(), 4);

    Fraction f3("1.3125");
    EXPECT_EQ(f3.get_numerator(), 21);
    EXPECT_EQ(f3.get_denominator(), 16);
}

// Test simplification
TEST(FractionTest, Simplification) {
    Fraction f1(8, 4); // Simplified to 2/1
    EXPECT_EQ(f1.get_numerator(), 2);
    EXPECT_EQ(f1.get_denominator(), 1);

    Fraction f2(10, 5); // Simplified to 2/1
    EXPECT_EQ(f2.get_numerator(), 2);
    EXPECT_EQ(f2.get_denominator(), 1);

    Fraction f3(24, 65676);
    EXPECT_EQ(f3.get_numerator(), 2);
    EXPECT_EQ(f3.get_denominator(), 5473);
}

// Test arithmetic operations
TEST(FractionTest, ArithmeticOperations) {
    Fraction f1(22, 7);
    Fraction f2(255, 113);

    // Test addition
    Fraction result_add = f1 + f2;
    EXPECT_EQ(result_add.get_numerator(), 4271);
    EXPECT_EQ(result_add.get_denominator(), 791);

    // Test subtraction
    Fraction result_sub = f1 - f2;
    EXPECT_EQ(result_sub.get_numerator(), 701);
    EXPECT_EQ(result_sub.get_denominator(), 791);

    // Test multiplication
    Fraction result_mul = f1 * f2;
    EXPECT_EQ(result_mul.get_numerator(), 5610);
    EXPECT_EQ(result_mul.get_denominator(), 791);

    // Test division
    Fraction result_div = f1 / f2;
    EXPECT_EQ(result_div.get_numerator(), 2486);
    EXPECT_EQ(result_div.get_denominator(), 1785);
}

// Test comparison operators
TEST(FractionTest, ComparisonOperators) {
    Fraction f1(1, 2);
    Fraction f2(2, 4);
    Fraction f3(1, 3);

    // Test equality operator
    EXPECT_TRUE(f1 == f2);
    EXPECT_FALSE(f1 == f3);

    // Test inequality operator
    EXPECT_FALSE(f1 != f2);
    EXPECT_TRUE(f1 != f3);

    // Test less than operator
    EXPECT_TRUE(f3 < f1);

    // Test greater than operator
    EXPECT_TRUE(f1 > f3);

    // Test less than or equal to operator
    EXPECT_TRUE(f1 <= f2);

    // Test greater than or equal to operator
    EXPECT_FALSE(f3 >= f1);
}

// Test conversion to double
TEST(FractionTest, ConversionToDouble) {
    Fraction f1(1, 2);
    EXPECT_DOUBLE_EQ(static_cast<double>(f1), 0.5);

    Fraction f2(-123, 32);
    EXPECT_DOUBLE_EQ(static_cast<double>(f2), -3.84375);
}

// Test input/output operators
TEST(FractionTest, InputOutputOperators) {
    std::stringstream ss;

    // Test output stream
    Fraction f1(2, 555);
    ss << f1;
    EXPECT_EQ(ss.str(), "2/555");

    // Test input stream
    ss.str("3/412");
    Fraction f2;
    ss >> f2;
    EXPECT_EQ(f2.get_numerator(), 3);
    EXPECT_EQ(f2.get_denominator(), 412);
}

// Test handling of negative fractions (denominator is negative)
TEST(FractionTest, NegativeFractions) {
    Fraction f1(-3, 4); // Should simplify to -3/4
    EXPECT_EQ(f1.get_numerator(), -3);
    EXPECT_EQ(f1.get_denominator(), 4);

    Fraction f2(3, -4); // Should simplify to -3/4
    EXPECT_EQ(f2.get_numerator(), -3);
    EXPECT_EQ(f2.get_denominator(), 4);
}

// Test handling of large numbers
TEST(FractionTest, LargeNumbers) {
    Fraction f1(1000000, 500000); // Should simplify to 2/1
    EXPECT_EQ(f1.get_numerator(), 2);
    EXPECT_EQ(f1.get_denominator(), 1);
}

// Test handling of edge cases for decimal input
TEST(FractionTest, EdgeCaseDecimalInput) {
    Fraction f1("0");
    EXPECT_EQ(f1.get_numerator(), 0);
    EXPECT_EQ(f1.get_denominator(), 1);

    Fraction f2("12345");
    EXPECT_EQ(f2.get_numerator(), 12345);
    EXPECT_EQ(f2.get_denominator(), 1);

    Fraction f3("-0.0001");
    EXPECT_EQ(f3.get_numerator(), -1);
    EXPECT_EQ(f3.get_denominator(), 10000);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
