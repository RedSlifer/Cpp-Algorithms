#include <iostream>

int solution(int X, int Y, int D)
{
    unsigned int counter = 0;

    while (true)
    {
        if (X < Y)
        {
            X += D;
            counter++;
        }
        else
        {
            break;
        }
    }
    return counter++;
}

int main()
{
    int X = 5, Y = 1000000000, D = 2;

    std::cout << solution(X, Y, D) << std::endl;

    return 0;
}
