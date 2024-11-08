#ifndef FRACTION_H
#define FRACITON_H

#include <cstdint>
#include <string>

class Fraction {
public:
    using num_t = std::size_t;
    Fraction() : numerator(0), denominator(1) {}
    Fraction(num_t numerator, num_t denominator);
    Fraction(const Fraction& other);
    Fraction(const std::string& decimal);

    num_t get_numerator() const;
    num_t get_denominator() const;

    void simplify();
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    explicit operator double() const;
    std::string to_string() const;
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& is, Fraction& fraction);
    void from_decimal(const std::string& decimal);
private:
    num_t numerator;
    num_t denominator;
};

#endif // !FRACTION_H
