#include <iostream>

unsigned greatest_common_divisor(unsigned number_1, unsigned number_2);

int main()
{
    unsigned number_1, number_2;

    std::cout << "Enter with two numbers:";
    std::cin >> number_1 >> number_2;

    std::cout << greatest_common_divisor(number_1, number_2);

    return 0;
}

unsigned greatest_common_divisor(unsigned number_1, unsigned number_2)
{
    if (number_1 % number_2 == 0)
    {
        return number_2;
    }
    else
    {
        return greatest_common_divisor(number_2, number_1 % number_2);
    }
}
