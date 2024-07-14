#include <iostream>

std::string guess_memory;

std::string encrypt_word(const std::string& word);
std::string revel_letters(const std::string& guess, std::string& encrypted_word, const std::string& word);

int main() {
    std::string word("write"), guess, predecessor_word, hidden_word, target_string;
    unsigned i = 0;

    hidden_word = encrypt_word(word);

    while (i < 6) {
        std::cin >> guess;
        target_string = revel_letters(guess, hidden_word, word);
        std::cout << target_string << std::endl;

        if (guess != guess_memory) {
            i++;
        }
        if (target_string == word) {
            break;
        }
    }

    return 0;
}

std::string encrypt_word(const std::string& word) {
    std::string encrypted_word;

    encrypted_word.append(word.length(), '*');
    return encrypted_word;
}

std::string revel_letters(const std::string& guess, std::string& encrypted_word, const std::string& word) {
    size_t position;
    position = word.find(guess);

    if (guess == guess_memory) {
        std::cout << guess << " is already in the word" << std::endl;
        return encrypted_word;
    }
    else if (position != std::string::npos) {
        while (position != std::string::npos) {
            encrypted_word.replace(position, 1, guess);
            position = word.find(guess, position + 1);
        }
    }
    else {
        std::cout << guess << " is not in the word" << std::endl;
        return encrypted_word;
    }

    guess_memory = guess;
    return encrypted_word;
}
