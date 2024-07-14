#include <iostream>

int main() {
	std::string string;
	int columns = 1, foo = 2;

	std::cin >> string;

	for (int i = 0; i < string.length(); i++) {
		for (int k = 0; k < string.length() - 1 - i; k++) {
			std::cout << " ";
		}

		for (int j = 0; j < columns; j++) {
			if  (j <= i) {
				std::cout << string[j];

			}
			else if (j > 1) {
				std::cout << string[j - foo];
				foo+=2;
			}
		}

		for (int k = 0; k < string.length() - 1 - i; k++) {
			std::cout << " ";
		}

		std::cout << "\n";

		columns += 2;
		foo = 2;
	}

	return 0;
}
