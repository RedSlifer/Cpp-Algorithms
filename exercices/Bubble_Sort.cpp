#include <iostream>
#include <vector>

int main()
{
    bool changed;
    std::vector<int> numbers {2, 1, 45, 9, 3, -7, 8, 5, 200};
    unsigned i, temporary;

    do
    {
        changed = false;
        for (i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] > numbers[i + 1])
            {
                temporary = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temporary;
                changed = true;
            }
        }
    } while (changed);
    
    for (i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << " ";
    }

    return 0;
}