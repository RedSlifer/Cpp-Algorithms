#include <iostream>
#include <iomanip>

int main() {
    size_t number_of_lines, i, j, blank_space = 0;
    int indent = 0;

    std::cin >> number_of_lines;
    indent = (number_of_lines * 2 - 1);

    for (i = 1; i <= number_of_lines; i++) {
        for (j = 0; j < i + (i - 1); j++) {
            if (j < i) {
                if (j == 0) {
                    std::cout << std::setw(indent);
                    std::cout << i - j << " ";
                }
                else {
                    std::cout << i - j << " ";
                }
            }
            else {
                std::cout <<  j - (i - 2) << " ";
            }
        }
        indent -= 2;
        std::cout << std::endl;
    }
    return 0;
}
