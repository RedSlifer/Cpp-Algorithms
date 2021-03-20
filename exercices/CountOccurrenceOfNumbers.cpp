#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vector;
    unsigned i, j = 0, k = 0, number, times = 0;

    while (true)
    {
        std::cin >> number;
        if (number > 0)
        {
            vector.push_back(number);
        }
        else
        {
            break;
        }
    }
    
    std::sort(vector.begin(), vector.end());

    for (i = 0; i < vector.size(); i += times)
    {
        times = std::count(vector.begin(), vector.end(), vector[i]);
        std::cout << vector[i] << " " << times << std::endl;
    }

    return 0;
}