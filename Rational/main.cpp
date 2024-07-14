#include <iostream>
#include "Rational.h"

int main() {
    Rational rational_number(9, 8);
    Rational other_rational_number(4, 3);

    std::cout << rational_number.get_numerator() << std::endl;
    std::cout << rational_number.get_denominator() << std::endl;
    std::cout << rational_number.add(other_rational_number).to_string() << std::endl;


    return 0;
}
