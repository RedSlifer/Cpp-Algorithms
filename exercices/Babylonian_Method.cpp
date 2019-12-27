#include <iostream>

int main()
{
    float number, aux = 1, accuracy = 0.000001, square_root;

    std::cin >> number;
    square_root = number;
    
    while (square_root - aux > accuracy)
    { 
        square_root = (square_root + aux) / 2; 
        aux = number / square_root; 
    } 

    std::cout << square_root << std::endl;
    return 0;
}