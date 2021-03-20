#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

double solution(int A, int B, int C, int D);

int main()
{
    std::cout << solution(1, 1, 2, 3) << std::endl;

    return 0;
}

double solution(int A, int B, int C, int D)
{
    std::vector<int> coordinates;
    double maximum_distance, distance;

    coordinates.push_back(A);
    coordinates.push_back(B);
    coordinates.push_back(C);
    coordinates.push_back(D);

    std::sort(coordinates.begin(), coordinates.end());

    maximum_distance = 0;

    do
    {
        distance = std::sqrt(std::pow(coordinates[1] - coordinates[0], 2) + std::pow(coordinates[3] - coordinates[2], 2));

        if (distance > maximum_distance)
        {
            maximum_distance = distance;
        }
    }
    while (std::next_permutation(coordinates.begin(), coordinates.end()));

    return maximum_distance;
}
