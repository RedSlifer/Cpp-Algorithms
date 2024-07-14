#include <iostream>
#include <vector>
#include <list>
#include <bitset>

int main() {
	std::vector<std::bitset<1>> number_1;
	std::vector<std::bitset<1>> number_2;
	std::list<std::bitset<1>> result;
	std::bitset<1> sum, bit;
	std::bitset<1> carry = 0;
	int number_of_bits;

	std::cout << "Number of bits: ";
	std::cin >> number_of_bits;
	std::cout << "\n";

	std::cout << "Augend: ";
	for (int i = 0; i < number_of_bits; i++) {
		std::cin >> bit;
		number_1.push_back(bit);
	}

	std::cout << "\n";

	std::cout << "Addend: ";
	for (int i = 0; i < number_of_bits; i++) {
		std::cin >> bit;
		number_2.push_back(bit);
	}

	std::cout << "\n";

	for (int i = (int)(number_1.size() - 1); i >= 0; i--) {
		sum = number_1[i] ^ (number_2[i] ^ carry); // Boolean Expression to calculate the sum. S = A XOR (B XOR Carry In)
		carry = (number_2[i] & carry) | (number_1[i] & carry) | (number_1[i] & number_2[i]); // Boolean Expression to calculate the carry out. Carry Out = (B AND Carry In) OR (A AND Carry In) OR (A AND B)

		result.push_front(sum);
	}

	if (carry == 1) {
		result.push_front(carry);
	}

	std::cout << "Result: ";
	for (auto i : result) {
		std::cout << i << " ";
	}

	return 0;
}
