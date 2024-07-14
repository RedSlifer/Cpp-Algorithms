#include <iostream>

int main() {
    int low = 0, high;
    bool is_palindrome = true;
    std::string string;

    std::getline(std::cin, string);

    high = string.length() - 1;
    while (low < high) {
        if (string[low] != string[high]) {
            is_palindrome = false;
            break;
        }
        low++;
        high--;
    }
    if (is_palindrome) {
        std::cout << "Palimdrome" << std::endl;
    }
    else {
        std::cout << "Not Palimdrome" << std::endl;
    }
    return 0;
}
