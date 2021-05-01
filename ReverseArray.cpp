#include <iostream>

void reverse_array(const int array[], int new_array[], int size)
{
    unsigned i, j;
    for (i = 0, j = size - 1; i < size; i++, j--)
    {
        new_array[j] = array[i];
    }
}

void print_array(const int array[], int size)
{
    unsigned i;
    for (i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}

int main()
{
    const int SIZE = 6;
    int array[] = {1, 2, 3, 4, 5, 6};
    int new_array[SIZE];

    reverse_array(array, new_array, SIZE);
    print_array(array, SIZE);
    std::cout << std::endl;
    print_array(new_array, SIZE);

    return 0;
}
