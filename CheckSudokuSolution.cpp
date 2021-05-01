#include <iostream>
#include <array>

void read_solution(std::array<std::array<unsigned, 9>, 9>& solution_sudoku)
{
    unsigned i, j;

    std::cout << "Enter the sudoku solution" << std::endl;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            std::cin >> solution_sudoku[i][j];
        }
    }
}

bool validate_rows_of_sudoku_solution(const std::array<std::array<unsigned, 9>, 9>& solution_sudoku)
{
    unsigned i, j, k;
    unsigned pivot;

    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 8; j++)
        {
            pivot = solution_sudoku[i][j];
            for(k = j + 1; k < 9; k++)
            {
                if (pivot == solution_sudoku[i][k])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool validate_columns_of_sudoku_solution(const std::array<std::array<unsigned, 9>, 9>& solution_sudoku)
{
    unsigned i, j, k;
    unsigned pivot;

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 9; j++)
        {
            pivot = solution_sudoku[i][j];
            for(k = i + 1; k < 9; k++)
            {
                if (pivot == solution_sudoku[k][j])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    std::array<std::array<unsigned, 9>, 9> guess_sudoku{};

    read_solution(guess_sudoku);

    if (validate_rows_of_sudoku_solution(guess_sudoku) && validate_columns_of_sudoku_solution(guess_sudoku))
    {
        std::cout << "Correct Answer" << std::endl;
    }
    else
    {
        std::cout << "Wrong Answer" << std::endl;
    }

    return 0;
}
