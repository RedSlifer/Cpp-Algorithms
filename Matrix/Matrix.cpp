#include <iostream>
#include <vector>
#include "Matrix.h"

Matrix::Matrix() {
   this -> elements.reserve(0);
}

std::vector<std::vector<unsigned int>> Matrix::matrix_builder(const unsigned int& rows, const unsigned int& columns) {
    unsigned int i, j, elements;
    std::vector<unsigned int> row;

    std::cout << "Enter the elements" << std::endl;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            std::cin >> elements;
            row.push_back(elements);
        }
        this -> elements.push_back(row);
        row.clear();
    }
    return this -> elements;
}

unsigned int Matrix::sum_elements() {
    unsigned int sum = 0;

    for(const auto& rows : this -> elements) {
      for(auto element : rows) {
        sum = sum + element;
      }
    }

    return sum;
}

void Matrix::matrix_printer() {
    for (const auto& rows : this -> elements) {
        for(auto element : rows) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}
