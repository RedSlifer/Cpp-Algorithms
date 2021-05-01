#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix my_matrix;

    my_matrix.matrix_builder(2, 2);
    my_matrix.matrix_printer();
    std::cout << std::endl;
    std::cout << my_matrix.sum_elements() << std::endl;

    return 0;
}
