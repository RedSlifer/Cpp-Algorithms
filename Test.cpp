#include <iostream>

int main()
{
	int number {100};

	auto value = [number]()mutable{number += 100; std::cout << number << std::endl;};

	value();
	std::cout << number << std::endl;

	std::cout << &value << std::endl;

	value();
	std::cout << number << std::endl;

	std::cout << &value << std::endl;

	return 0;
}
