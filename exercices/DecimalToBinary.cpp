#include <iostream>

int main()
{
    int decimal_number, binary_value;
    char binary_char;
    std::string binary_number = "";

    std::cin >> decimal_number; //Imput decimal number

    while (decimal_number != 0)
    {
        binary_value = decimal_number % 2;  //Decimal to binary
        binary_char = static_cast<char>(binary_value + '0');    //Get binary char
        binary_number = binary_char + binary_number;    //Add to binary string
        decimal_number = decimal_number / 2;
    }
    std::cout << binary_number << std::endl;

    return 0;
}
