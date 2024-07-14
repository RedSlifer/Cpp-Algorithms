#include <iostream>

unsigned counter_even_digits(unsigned number);
unsigned counter_even_digits(const std::string& number);

int main() {
    unsigned number, number_even_digits, number_odd_digits;

    std::cin >> number;

    number_even_digits = counter_even_digits(number);
    number_odd_digits = std::to_string(number).size() - number_even_digits;

    std:: cout << "Number of even digits is: " << number_even_digits << std::endl;
    std:: cout << "Number of odd digits is: " << number_odd_digits;

    return 0;
}

unsigned counter_even_digits(unsigned number) {
    return counter_even_digits(std::to_string(number));
}

unsigned counter_even_digits(const std::string& number) {
    if (number.length() == 1) {
        if (std::stoi(number) % 2 == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if (number[number.length() - 1] % 2 == 0) {
            return counter_even_digits(number.substr(0, number.length() - 1)) + 1;
        }
        else {
            return counter_even_digits(number.substr(0, number.length() - 1));
        }
    }
}
