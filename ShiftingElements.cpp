#include <iostream>

int main()
{
    unsigned i;
    const int SIZE = 9;
    int array[SIZE] = {1, 4, 8, 3, 1, 4, 6, 10, 7};
    int temporary;

    temporary = array[0];

    for (i = 1; i < SIZE; i++)
    {
        array[i - 1] = array[i];
    }
    array[SIZE - 1] = temporary;
    
    for (i = 0; i < SIZE; i++)
    {
        std::cout << array[i] << " ";
    }
    return 0;
}