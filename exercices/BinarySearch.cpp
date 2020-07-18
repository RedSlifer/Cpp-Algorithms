#include <iostream>
#include <array>

template <typename T, unsigned S>
T binary_search(std::array<T, S> array, int key)
{
    int low_index = 0;
    int high_index = S - 1;
    int middle_index;

    while (high_index >= low_index)
    {
        middle_index = (low_index + high_index) / 2;
        if (key < array[middle_index])
        {
            high_index = middle_index - 1;
        }
        else if (key > array[middle_index])
        {
            low_index = middle_index + 1;
        }
        else
        {
            return middle_index;
        }
    }
    return false;
}

int main()
{
    const unsigned SIZE = 13;
    std::array<int, SIZE> array {2, 4, 7, 10, 11, 45, 50, 59, 60, 66, 69, 70, 79};

    std::cout << binary_search(array, 4) << std::endl;

    return 0;
}
