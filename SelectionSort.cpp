#include <iostream>

void selection_sort(double array[], unsigned size)
{
    unsigned i, j, current_minimum_index;
    double current_minimum;

    for (i = 0; i < size - 1; i++)
    {
        // Find the minimum in the array
        current_minimum = array[i];
        current_minimum_index = i;
        
        for (j = i + 1; j < size; j++)
        {
            if (current_minimum > array[j])
            {
                current_minimum = array[j];
                current_minimum_index = j;
            }
        }
        // Swap array[i] with array[current_minimum_index]
        if (current_minimum_index != i)
        {
            array[current_minimum_index] = array[i];
            array[i] = current_minimum;
        }
    }
}

int main()
{
    unsigned i;
    const unsigned SIZE = 6;
    double array[SIZE] = {1, 9, 4.5, 6.6, 5.7, -4.5};
    
    selection_sort(array, SIZE);
    for (i = 0; i < SIZE; i++)
    {
        std::cout << array[i] << " ";
    }
    return 0;
}