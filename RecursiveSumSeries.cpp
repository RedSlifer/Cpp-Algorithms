#include <iostream>

float recursive_sum_series(float n);

int main() {
    float n;

    std::cout << "Enter with n:";
    std::cin >> n;

    std::cout << recursive_sum_series(n) << std::endl;

    return 0;
}

float recursive_sum_series(float n) {
    if (n == 1) {
        return 1;
    }
    else {
        return recursive_sum_series(n - 1) + (3 / (n + 2));
    }
}
