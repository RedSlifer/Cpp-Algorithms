#include <iostream>

unsigned recursive_fibonacci(unsigned index);

int main() {
    unsigned index;

    std::cin >> index;
    std::cout << recursive_fibonacci(index) << std::endl;

    return 0;
}

unsigned recursive_fibonacci(unsigned index) {
    if (index == 0) {
        return 0;
    }
    else if (index == 1) {
        return 1;
    }
    else {
        return recursive_fibonacci(index - 2) + recursive_fibonacci(index - 1);
    }
}
