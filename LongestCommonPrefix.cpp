#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::vector<std::string> string_1;
    std::vector<std::string> string_2;
    std::vector<std::string> string_3;
    std::string string;
    std::string word;
    std::string max_string;
    size_t i, j;

    for (i = 0; i < 2; i++) {
        std::getline(std::cin, string);
        if (i == 0) {
            std::istringstream iss (string);
            while (iss >> string) {
                string_1.push_back(string);
            }
        }
        else {
            std::istringstream iss (string);
            while (iss >> string) {
                string_2.push_back(string);
            }
        }
    }

    for (i = 0; i < string_2.size(); i++) {
        for (j = 0; j < string_2[i].size(); j++) {
            if (string_1[i][j] == string_2[i][j]) {
                word += string_1[i][j];
            }
            else {
                break;
            }
        }
        string_3.push_back(word);
        word.clear();
    }
    
    max_string = string_3[0];
    for (i = 1; i < string_3.size(); i++) {
        if (string_3[i].size() > max_string.size()) {
            max_string.clear();
            max_string.append(string_3[i]);
        }
    }
    std::cout << max_string << std::endl;
    return 0;
}
