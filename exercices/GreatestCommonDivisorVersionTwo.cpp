#include <iostream>

int main()
{
    int number_1, number_2, minimum, gcd, i = 0;

    std::cin >> number_1 >> number_2;
    //Determine the minimun between number_1 and number_2
    if (number_1 > number_2)
    {
        minimum = number_2;
    }
    else if (number_1 < number_2)
    {
        minimum = number_1;
    }
    else
    {
        minimum = number_1;
    }
    //The first between minimum, minimun - 1, minimum - 2, ..., 2 or 1. Is the GCD
    while(minimum >= 1)
    {
        if (number_1 % minimum == 0 && number_2 % minimum == 0)
        {
            gcd = minimum;
            break;
        }
        i++;
        minimum -= i;
    }
    std::cout << gcd << std::endl;

    return 0;
}