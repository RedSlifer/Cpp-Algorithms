#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    const int NUMBER_OF_TRIALS = 1000000;
    int number_of_hits = 0, i;
    double x, y, pi;
    std::srand(time(0));

    for (i = 0; i < NUMBER_OF_TRIALS; i++)
    {
        x = std::rand() * 2.0 / RAND_MAX - 1;
        y = std::rand() * 2.0 / RAND_MAX - 1;

        if (x * x + y * y <= 1) //Check inside the circle
        {
            number_of_hits++;
        }
    }
    pi = 4.0 * number_of_hits / NUMBER_OF_TRIALS;   //Aproximation for Pi
    std::cout << "PI is " << pi << std::endl;

    return 0;
}