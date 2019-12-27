#include <iostream>
#include <vector>

int main()
{
    size_t i;
    int max = 0, counter = 0, number;
    std::vector<int> container;

    while (true)
    {
        std::cin >> number;
        if (number > 0)
        {
            container.push_back(number);
        }
        else
        {
            break;
        }
    }
    max = container[0];
    counter = 1;
    for (i = 1; i < container.size(); i++)
    {
        if (container[i] > max)
        {
            max = container[i];
            counter = 1;
        }
        else if (container[i] == max)
        {
            counter++;
        }
    }
    std::cout << max << " " << counter << std::endl;
    return 0;
}