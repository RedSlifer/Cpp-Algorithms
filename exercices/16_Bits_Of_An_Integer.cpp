#include <iostream>

int main()
{
    int number;
    unsigned i;

   std::cin >> number;

    for (i = 1 << 15; i > 0; i = i / 2)
    {
        (number & i)? printf("1") : printf("0");
    }
    return 0;
}