#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <ctime>

const int NUMBER_OF_SLOTS = 8;
const int NUMBER_OF_RESULTS = 7;    //Equal to NUMBER_OF_SLOTS - 1

int main() {
    std::vector<int> slots(NUMBER_OF_SLOTS, 0);
    std::array<char, NUMBER_OF_RESULTS> results; 
    unsigned i, j, number_of_balls, slot,  highest_column;

    srand(time(0));
    std::cin >> number_of_balls;

    for (i = 0; i < number_of_balls; i++) {
        for (j = 0; j < NUMBER_OF_RESULTS; j++) {
            if (rand() % 2 == 0) {
                results[j] = 'L';
                std::cout << 'L' << " ";
            }
            else {
                results[j] = 'R';
                std::cout << 'R' << " ";
            }
        }
        slot = std::count(results.begin(), results.end(), 'R');
        std::cout << slot << std::endl;
        slots[slot - 1]++;
        std::cout << std::endl;
    }

    highest_column = *std::max_element(slots.begin(), slots.end());

    for (i = highest_column; i > 0; i--) {
       for (auto value : slots) {
           if (i <= value) {
               std::cout << '0';
           }
           else {
               std::cout << ' ';
           }
       }
       std::cout << std::endl;
    }
    
    return 0;
}
