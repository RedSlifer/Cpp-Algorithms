#include <iostream>
#include <algorithm>
#include <stack>

void common_characters(std::string string_1, std::string string_2) {
    unsigned i;
    std::stack<char> letters;
    std::string common_characters;

    std::sort(string_1.begin(), string_1.end());
    std::sort(string_2.begin(), string_2.end());

    for (i = 0; i < string_1.length(); i++) {
        if (i == 0) {
            letters.push(string_1.at(i));
        }
        else if (i > 0) {
            if (string_1.at(i) == string_1.at(i - 1)) {
                continue;
            }
            else {
                letters.push(string_1.at(i));
            }
        }
    }

    while (!letters.empty()) {
        if (string_2.find(letters.top()) != std::string::npos) {
            common_characters.append(1, letters.top());
            letters.pop();
        }
        else {
            letters.pop();
        }
    }

    if (common_characters.length() > 0) {
        std::sort(common_characters.begin(), common_characters.end());
        std::cout << "Commmon Characters " << common_characters << std::endl;
    }
    else {
        std::cout << "No Commmon Characters" << std::endl;
    }
}

int main() {
    std::string string_1;
    std::string string_2;

    std::cout << "Enter the strings" << std::endl;
    std::cin >> string_1 >> string_2;

    common_characters(string_1, string_2);
    return 0;
}
