#include <iostream>
#include <algorithm>

void string_permutation(std::string& string, unsigned start_index, unsigned final_index);

int main() {
   std::string string = "ABC";

   string_permutation(string, 0, string.length() - 1);

   return 0;
}

void string_permutation(std::string& string, unsigned start_index, unsigned final_index) {
    unsigned i;

    if (start_index == final_index) { //Base case
        std::cout << string << std::endl;
    }
    else {
        for (i = start_index; i <= final_index; i++) {
            std::swap(string[start_index], string[i]);
            string_permutation(string, start_index + 1, final_index);
            std::swap(string[start_index], string[i]);
        }
    }
}
