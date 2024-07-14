#include <iostream>
#include <cmath>

int main() {
    std::string number;
    size_t n, i, sum = 0;

    std::cin >> number;
    n = number.size();

    for (i = 0; i < number.size(); i++) {
        sum += std::pow(number[i] - '0', n);
    }
    
    if (std::stoi(number) == sum) {   //Convert a string to a number
        std::cout << "Armstrong Number" << std::endl;
    }
    else {
        std::cout << "Not an Armstrong Number" << std::endl;
    }
    
    return 0;
}
