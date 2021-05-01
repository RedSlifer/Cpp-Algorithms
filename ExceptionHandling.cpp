#include <iostream>

int main()
{
    double n1 = 1, n2 = 0;

    try
    {
        if (n2 == 0)
        {
            throw std::runtime_error("Denominator equals to zero");
        }
        else
        {
            std::cout << n1 / n2 << std::endl;
        }
    }
    catch (std::exception& exception)
    {
        std::cout << exception.what() << std::endl;
    }

    return 0;
}
