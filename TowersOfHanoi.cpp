#include <iostream>

void move_disks(int n, char origin_tower, char destiny_tower, char auxiliary_tower);

int main()
{
    int n;

    std::cout << "Enter number of disks:";
    std::cin >> n;

    std::cout << "The moves are:" << std::endl;
    move_disks(n, 'A', 'B', 'C');

    return 0;
}

void move_disks(int n, char origin_tower, char destiny_tower, char auxiliary_tower)
{
    //Base case
    if (n == 1)
    {
        std::cout << "Move disk " << n << " from " << origin_tower << " to " << destiny_tower << std::endl;
    }
    //Recursion
    else
    {
        move_disks(n - 1, origin_tower, auxiliary_tower, destiny_tower);
        std::cout << "Move disk " << n << " from " << origin_tower << " to " << destiny_tower << std::endl;
        move_disks(n - 1, auxiliary_tower, destiny_tower, origin_tower);
    }
}
