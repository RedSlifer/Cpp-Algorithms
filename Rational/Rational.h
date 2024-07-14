#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
    int numerator, denominator;

public:
    Rational();
    Rational(int numerator, int denominator);

public:
    [[nodiscard]] int get_numerator() const;
    [[nodiscard]] int get_denominator() const;
    [[nodiscard]] Rational add(const Rational& second_rational) const;
    [[nodiscard]] Rational subtract(const Rational& second_rational) const;
    [[nodiscard]] Rational multiply(const Rational& second_rational) const;
    [[nodiscard]] Rational divide(const Rational& second_rational) const;
    [[nodiscard]] int compare(const Rational& second_rational) const;
    [[nodiscard]] bool equals(const Rational& second_rational) const;
    [[nodiscard]] int int_value() const;
    [[nodiscard]] double double_value() const;
    [[nodiscard]] std::string to_string() const;

private:
    static int gcd(int numerator, int denominator);
};

#endif
