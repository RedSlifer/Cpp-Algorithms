#include <iostream>
#include <array>

std::string pattern_0 ("000102");
std::string pattern_1 ("101112");
std::string pattern_2 ("202122");
std::string pattern_3 ("001020");
std::string pattern_4 ("011121");
std::string pattern_5 ("021222");
std::string pattern_6 ("001122");
std::string pattern_7 ("021120");

void print_lines()
{
    unsigned i, j;
    for (i = 0; i < 5; i++)
    {
        std::cout << "-" << "";
    }
    std::cout << std::endl;
}

std::array<std::array<char, 3>, 3> initializer_matrix(std::array<std::array<char, 3>, 3>& tic_tac_toe_board)
{
    for (auto rows : tic_tac_toe_board)
    {
        for(auto elements : rows)
        {
            elements = ' ';
        }
    }

    return tic_tac_toe_board;
}

void tic_tac_toe_board_printer(const std::array<std::array<char, 3>, 3>& tic_tac_toe_board)
{
    for (auto rows : tic_tac_toe_board)
    {
        for(auto elements : rows)
        {
            std::cout << elements << " ";
        }
        std::cout << std::endl;
    }
}

bool find_winner(const std::array<std::array<char, 3>, 3>& tic_tac_toe_board, unsigned flag)
{
    std::string positions;
    unsigned i, j;

    if (flag % 2 == 0)
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (tic_tac_toe_board[i][j] == 'X')
                {
                    positions.append(std::to_string(i));
                    positions.append(std::to_string(j));
                }
            }
        }

        return positions == pattern_0 || positions == pattern_1 || positions == pattern_2 || positions == pattern_3 ||
               positions == pattern_4 || positions == pattern_5 || positions == pattern_6 || positions == pattern_7;
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (tic_tac_toe_board[i][j] == 'O')
                {
                    positions.append(std::to_string(i));
                    positions.append(std::to_string(j));
                }
            }
        }

        return positions == pattern_0 || positions == pattern_1 || positions == pattern_2 || positions == pattern_3 ||
               positions == pattern_4 || positions == pattern_5 || positions == pattern_6 || positions == pattern_7;
    }
}

int main()
{
    std::array<std::array<char, 3>, 3> tic_tac_toe_board{};
    unsigned i = 0, row, column;

    initializer_matrix(tic_tac_toe_board);

    for (i = 0; i < 9; i++)
    {
        print_lines();
        tic_tac_toe_board_printer(tic_tac_toe_board);
        print_lines();

        if (i % 2 == 0)
        {
            std::cout << "Enter a row for player X: ";
            std::cin >> row;
            std::cout << "Enter a column for player X: ";
            std::cin >> column;
            tic_tac_toe_board[row][column] = 'X';
        }
        else
        {
            std::cout << "Enter a row for player O: ";
            std::cin >> row;
            std::cout << "Enter a column for player O: ";
            std::cin >> column;
            tic_tac_toe_board[row][column] = 'O';
        }
        if (i >= 4)
        {
            if (find_winner(tic_tac_toe_board, i))
            {
                if (i % 2 == 0)
                {
                    print_lines();
                    tic_tac_toe_board_printer(tic_tac_toe_board);
                    print_lines();
                    std::cout << "X win the game"<< std::endl;
                    return 0;
                }
                else
                {
                    print_lines();
                    tic_tac_toe_board_printer(tic_tac_toe_board);
                    print_lines();
                    std::cout << "O win the game"<< std::endl;
                    return 0;
                }
            }
        }
    }

    print_lines();
    tic_tac_toe_board_printer(tic_tac_toe_board);
    print_lines();
    std::cout << "Draw" << std::endl;
    return 0;
}
