#include <iostream>

int main()
{
    int number, divisor;
    std::string result = "Prime";
    
    std::cin >> number;

    for (divisor = 2; divisor <= number / 2; divisor++)
    {
        if (number % divisor == 0)
        {
            result = "Not Prime";
            break;
        }
    }
    std::cout << result << std::endl;
    return 0;
}