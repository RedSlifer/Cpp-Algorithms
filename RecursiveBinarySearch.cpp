#include <iostream>

int binary_search(const int list[] , int key, int low_index, int high_index);
int binary_search(const int list[], int key, int size);

int main()
{
    int list[] = {2, 4, 7, 10, 11, 45, 50, 59, 60, 66, 69, 70, 79};

    std::cout << binary_search(list, 11, 13) << std::endl;
    std::cout << binary_search(list, 2, 13) << std::endl;
    std::cout << binary_search(list, 12, 13) << std::endl;

    return 0;
}

int binary_search(const int list[] , int key, int low_index, int high_index)
{
    int middle_index;

    if (low_index > high_index)
    {
        return - low_index - 1;
    }

    middle_index = (low_index + high_index) / 2;

    if (key < list[middle_index])
    {
        return binary_search(list, key, low_index, middle_index - 1);
    }
    else if (key == list[middle_index])
    {
        return middle_index;
    }
    else
    {
        return binary_search(list, key, middle_index + 1, high_index);
    }
}

int binary_search(const int list[], int key, int size)
{
    int low_index = 0;
    int high_index = size - 1;

    return binary_search(list, key, low_index, high_index);
}
