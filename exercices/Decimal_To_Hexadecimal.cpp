#include <iostream>

int main()
{
    int decimal_number, hexadecimal_value;
    char hexadecimal_char;
    std::string hexadecimal_number = "";
    
    std::cin >> decimal_number; //Imput decimal number

    while (decimal_number != 0)
    {
        hexadecimal_value = decimal_number % 16;    //Decimal to hexadecimal
        //Get hexadecimal char
        hexadecimal_char = (hexadecimal_value <= 9 && hexadecimal_value >= 0) ? static_cast<char>(hexadecimal_value + '0') : static_cast<char>(hexadecimal_value - 10 + 'A');
        hexadecimal_number = hexadecimal_char + hexadecimal_number; //Add to hexadecimal string
        decimal_number = decimal_number / 16;
    }
    std::cout << hexadecimal_number << std::endl;
    
    return 0;
}