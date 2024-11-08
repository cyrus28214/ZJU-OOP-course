#include "Fraction.h"
#include <numeric>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cctype>

Fraction::Fraction(num_t numerator, num_t denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    this->numerator = numerator;
    this->denominator = denominator;
    this->simplify();
}

Fraction::Fraction(const Fraction& other) {
    this->numerator = other.numerator;
    this->denominator = other.denominator;
}

Fraction::Fraction(const std::string& decimal) {
    this->from_decimal(decimal);
}

Fraction::num_t Fraction::get_numerator() const {
    return this->numerator;
}
Fraction::num_t Fraction::get_denominator() const {
    return this->denominator;
}

void Fraction::simplify() {
    num_t gcd = std::gcd(this->numerator, this->denominator);
    this->numerator /= gcd;
    this->denominator /= gcd;
    if (this->denominator < 0) {
        this->numerator = -this->numerator;
        this->denominator = -this->denominator;
    }
}

Fraction Fraction::operator+(const Fraction& other) const {
    Fraction result(
        this->numerator * other.denominator + other.numerator * this->denominator,
        this->denominator * other.denominator
    );
    result.simplify();
    return result;
}

Fraction Fraction::operator-(const Fraction& other) const {
    Fraction result(
        this->numerator * other.denominator - other.numerator * this->denominator,
        this->denominator * other.denominator
    );
    result.simplify();
    return result;
}

Fraction Fraction::operator*(const Fraction& other) const {
    Fraction result(
        this->numerator * other.numerator,
        this->denominator * other.denominator
    );
    result.simplify();
    return result;
}

Fraction Fraction::operator/(const Fraction& other) const {
    Fraction result(
        this->numerator * other.denominator,
        this->denominator * other.numerator
    );
    result.simplify();
    return result;
}

bool Fraction::operator==(const Fraction& other) const {
    return this->numerator * other.denominator == other.numerator * this->denominator;
}

bool Fraction::operator!=(const Fraction& other) const {
    return this->numerator * other.denominator != other.numerator * this->denominator;
}

bool Fraction::operator<(const Fraction& other) const {
    // a/b - c/d = (ad - bc) / bd
    bool rev = (this->denominator < 0) ^ (other.denominator < 0);
    return (this->numerator * other.denominator < other.numerator * this->denominator) ^ rev;
}

bool Fraction::operator>(const Fraction& other) const {
    bool rev = (this->denominator < 0) ^ (other.denominator < 0);
    return (this->numerator * other.denominator > other.numerator * this->denominator) ^ rev;
}

Fraction::operator double() const {
    return static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
}

std::string Fraction::to_string() const {
    return std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.to_string();
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& fraction) {
    char sep;
    is >> fraction.numerator >> sep >> fraction.denominator;
    fraction.simplify();
    return is;
}

/**
 * @brief set the fraction from a decimal string
 * @param decimal the decimal string, matching the regex \s*[+-]?\d*(\.\d*)?
 */
void Fraction::from_decimal(const std::string& decimal) {
    this->numerator = 0;
    this->denominator = 1;
    char* s = const_cast<char*>(decimal.c_str());

    while (*s && std::isspace(*s)) s++;

    bool sign = false;
    while (*s == '+' || *s == '-') {
        sign ^= (*s == '-');
        s++;
    }

    while (*s && std::isdigit(*s)) {
        this->numerator = this->numerator * 10 + (*s - '0');
        s++;
    }

    if (*s != '.') return;
    s++;

    while (*s && std::isdigit(*s)) {
        this->numerator = this->numerator * 10 + (*s - '0');
        this->denominator *= 10;
        s++;
    }

    if (sign) this->numerator = -this->numerator;

    this->simplify();
}