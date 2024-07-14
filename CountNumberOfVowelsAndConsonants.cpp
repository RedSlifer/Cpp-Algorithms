#include <iostream>
#include <vector>

int main() {
    std::vector<char> letters;
    unsigned i, vowels = 0, consonants = 0;
    char letter;

    while (true) {
        std::cin >> letter;
        if (letter != '0') {
            if (isupper(letter)) {
                letters.push_back(tolower(letter));
            }
            else {
                letters.push_back(letter);
            }
        }
        else {
            break;
        }
    }
    
    for (i = 0; i < letters.size(); i++) {
        if ((letters[i] == 'a') || (letters[i] == 'e') || (letters[i] == 'i') || (letters[i] == 'o') || (letters[i] == 'u')) {
            vowels++;
        }
        else {
            consonants++;
        }
    }

    std::cout << vowels << " " << consonants << std::endl;

    return 0;
}
