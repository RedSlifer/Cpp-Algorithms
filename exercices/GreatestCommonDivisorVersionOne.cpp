#include <iostream>

int main()
{
    int number_1, number_2, gcd = 1, k = 2;

    std::cin >> number_1 >> number_2;

    while (k <= number_1 && k <= number_2)
    {
        if (number_1 % k == 0 && number_2 % k == 0)
        {
            gcd = k;
        }
        k++;
    }
    std::cout << gcd << std::endl;

    return 0;
}