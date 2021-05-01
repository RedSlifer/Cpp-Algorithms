#include <iostream>

const unsigned NUMBER_OF_QUEENS = 8;
unsigned queens[NUMBER_OF_QUEENS];

bool is_valid_position(unsigned row, unsigned column);
bool search_row_position(unsigned row);
void print_result();

int main()
{
    search_row_position(0);
    print_result();

    return 0;
}

bool is_valid_position(unsigned row, unsigned column)
{
    unsigned i;

    for (i = 1; i <= row; i++)
    {
        if(queens[row - i] == column or queens[row - i] == column - i or queens[row - i] == column + i)
        {
            return false;
        }
    }

    return true;
}

bool search_row_position(unsigned row)
{
    unsigned column;

    if (row == NUMBER_OF_QUEENS)
    {
        return true;
    }

    for (column = 0; column < NUMBER_OF_QUEENS; column++)
    {
        queens[row] = column;
        if (is_valid_position(row, column) and search_row_position(row + 1))
        {
            return true;
        }
    }

    return false;
}

void print_result()
{
    unsigned row, column;

    std::cout << "  a b c d e f g h"<< std::endl;
    for (row = 0; row < NUMBER_OF_QUEENS; row++)
    {
        std::cout << row + 1 << " ";
        for (column = 0; column < NUMBER_OF_QUEENS; column++)
        {
            std::printf(column == queens[row] ? "Q " : "X ");
        }
        std::cout << row + 1;
        std::cout << std::endl;
    }
    std::cout << "  a b c d e f g h"<< std::endl;
}
