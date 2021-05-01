#include <iostream>

unsigned long long int fibonacci(unsigned index);

int main()
{
    unsigned index;

    std::cin >> index;
    std::cout << fibonacci(index) << std::endl;

    return 0;
}

unsigned long long int fibonacci(unsigned index)
{
    unsigned long long int first = 0, second = 1, target = 0;
    unsigned i;

    if (index == 0)
    {
        return first;
    }
    else if (index == 1)
    {
        return second;
    }
    else
    {
        for (i = 2; i <= index; i++)
        {
            target = first + second;
            first = second;
            second = target;
        }
    }

    return target;
}
