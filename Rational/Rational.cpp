#include <cstdlib>
#include <iostream>
#include "Rational.h"

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int numerator, int denominator) {
    int factor = gcd(numerator, denominator);
    this -> numerator = ((denominator > 0) ? 1 : -1) * numerator / factor;
    this -> denominator = std::abs(denominator) / factor;
}

int Rational::get_numerator() const {
    return this -> numerator;
}

int Rational::get_denominator() const {
    return this -> denominator;
}

Rational Rational::add(const Rational& second_rational) const {
    int numerator = this -> numerator * second_rational.get_denominator() + denominator * second_rational.get_numerator();
    int denominator = this -> denominator * second_rational.get_denominator();

    return Rational(numerator, denominator);
}

Rational Rational::subtract(const Rational& second_rational) const {
    int numerator = this -> numerator * second_rational.get_denominator() - denominator * second_rational.get_numerator();
    int denominator = this -> denominator * second_rational.get_denominator();
    
    return Rational(numerator, denominator);
}

Rational Rational::multiply(const Rational& second_rational) const {
    int numerator = this -> numerator * second_rational.get_numerator();
    int denominator = this -> denominator * second_rational.get_denominator();
    
    return Rational(numerator, denominator);
}

Rational Rational::divide(const Rational& second_rational) const {
    int numerator = this -> numerator * second_rational.get_denominator();
    int denominator = this -> denominator * second_rational.get_numerator();

    return Rational(numerator, denominator);
}

int Rational::compare(const Rational& second_rational) const {
    Rational temp = subtract(second_rational);

    if (temp.get_numerator() < 0) {
        return -1;
    }
    else if (temp.get_numerator() == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

bool Rational::equals(const Rational& second_rational) const {
    return compare(second_rational) == 0;
}

int Rational::int_value() const {
    return get_numerator() / get_denominator();
}

double Rational::double_value() const {
    return 1.0 * get_numerator() / get_denominator();
}

std::string Rational::to_string() const {
   if (this -> denominator > 1) {
       return std::to_string(this -> numerator)  + "/" + std::to_string(this -> denominator);
   }
   else {
       return std::to_string(this -> numerator);
   }
}

int Rational::gcd(int numerator, int denominator) {
    int number_1 = std::abs(numerator);
    int number_2 = std::abs(denominator);
    int gcd = 1;
    int i;

    for (i = 1; i <= number_1 && i <= number_2; i++) {
        if (number_1 % i == 0 && number_2 % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}
