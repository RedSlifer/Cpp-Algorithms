#include <iostream>

int main()
{
    size_t i;
    int decimal_number = 0;
    std::string hexadecimal_number;

    std::cin >> hexadecimal_number;

    for (i = 0; i < hexadecimal_number.size(); i++)
    {
        if (hexadecimal_number[i] >= 'A' && hexadecimal_number[i] <= 'F')
        {
            decimal_number = decimal_number * 16 + (10 + hexadecimal_number[i] - 'A');
        }
        else
        {
            decimal_number = decimal_number * 16 + (hexadecimal_number[i] - '0');
        }
    }
    std::cout << decimal_number << std::endl;

    return 0;
}