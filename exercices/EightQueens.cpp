#include <iostream>
#include <array>
#include <ctime>

int index(std::array<char, 8> array)
{
    unsigned i;

    for (i = 0; i < 8; i++)
    {
        if (array[i] == 'Q')
        {
            return i;
        }
    }
}

int main()
{
    std::array<std::array<char, 8>, 8> chessboard;
    unsigned i, j, k, drawn_position, queen_position, next_queen_position;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            chessboard[i][j] = 'X';
        }
    }
    // Valid output to test
    /*
    chessboard[0][0] = 'Q';
    chessboard[1][4] = 'Q';
    chessboard[2][7] = 'Q';
    chessboard[3][5] = 'Q';
    chessboard[4][2] = 'Q';
    chessboard[5][6] = 'Q';
    chessboard[6][1] = 'Q';
    chessboard[7][3] = 'Q';
    */
    
    srand(time(0));

    for (i = 0; i < 8; i++)
    {
        drawn_position  = rand() % 8;
        chessboard[i][drawn_position] = 'Q';
    }
    
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            
            std::cout << chessboard[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (i = 0; i < 7; i++)
    {
        queen_position = index(chessboard[i]);
        for (j = i + 1; j <= 7; j++)
        {
           next_queen_position = index(chessboard[j]);
           if ((queen_position == next_queen_position) || (abs(i - j) == abs(queen_position - next_queen_position)))
           {
               std::cout << "Invalid Queens disposition";
               goto end; 
           }
        }
    }

    end:  

    return 0;
}