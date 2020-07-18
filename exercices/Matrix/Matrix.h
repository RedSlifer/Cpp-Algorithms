#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

class Matrix
{
private:
    std::vector<std::vector<unsigned int>> elements;

public:
    Matrix();

public:
    std::vector<std::vector<unsigned>> matrix_builder(const unsigned int& rows, const unsigned int& columns);
    unsigned int sum_elements();
    void matrix_printer();
};

#endif
