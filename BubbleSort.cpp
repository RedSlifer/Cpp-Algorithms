#include <iostream>
#include <vector>

int main() {
    bool changed;
    std::vector<int> numbers {1, 2, 3, 5, 4};
    unsigned i, temporary;

    do {
        changed = false;
        for (i = 0; i < numbers.size() - 1; i++) {
            if (numbers.at(i) > numbers.at(i + 1)) {
                temporary = numbers.at(i);
                numbers.at(i) = numbers.at(i + 1);
                numbers.at(i + 1) = temporary;
                changed = true;
            }
        }
    } while (changed);

    for (i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}
