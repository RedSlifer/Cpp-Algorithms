#include <iostream>
using namespace std;

const int numberOfRows = 6;
const int numberOfColumns = 7;
const int maxNumberOfElementsInDiagonal = 10;

bool isConsecutiveFour(char values[][7]);
bool isConsecutiveFour(const char values[], int size);

int main() {
    char values[6][7] = {{'0', '1', '0', '3', '1', '6', '1'},
                         {'0', '1', '6', '8', '6', '0', '1'},
                         {'5', '6', '2', '1', '8', '2', '9'},
                         {'6', '5', '1', '6', '1', '9', '1'},
                         {'1', '1', '3', '1', '4', '0', '7'},
                         {'3', '3', '3', '3', '4', '0', '7'}};

    /*
    for (auto & value : values)
    {
        for (char j : value)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    */

    cout << isConsecutiveFour(values) << endl;

    return 0;
}

bool isConsecutiveFour(char values[][7]) {
    // Check rows
    for (int i = 0; i < numberOfRows; i++) {
        if (isConsecutiveFour(values[i], numberOfRows))
            return true;
    }

    // Check columns
    for (int j = 0; j < numberOfColumns; j++) {
        char column[numberOfRows];

        // Get a column into an array
        for (int i = 0; i < numberOfRows; i++)
            column[i] = values[i][j];

        if (isConsecutiveFour(column, numberOfRows))
            return true;
    }

    // Check major diagonal (lower part)
    for (int i = 0; i < numberOfRows - 3; i++) {
        int numberOfElementsInDiagonal = min(numberOfRows - i, numberOfColumns);
        char diagonal[maxNumberOfElementsInDiagonal];

        for (int k = 0; k < numberOfElementsInDiagonal; k++)
            diagonal[k] = values[k + i][k];

        if (isConsecutiveFour(diagonal, numberOfElementsInDiagonal))
            return true;
    }

    // Check major diagonal (upper part)
    for (int j = 1; j < numberOfColumns - 3; j++) {
        int numberOfElementsInDiagonal = min(numberOfColumns - j, numberOfRows);
        char diagonal[maxNumberOfElementsInDiagonal];

        for (int k = 0; k < numberOfElementsInDiagonal; k++)
            diagonal[k] = values[k][k + j];

        if (isConsecutiveFour(diagonal, numberOfElementsInDiagonal))
            return true;
    }

    // Check sub-diagonal (left part)
    for (int j = 3; j < numberOfColumns; j++) {
        int numberOfElementsInDiagonal = min(j + 1, numberOfRows);
        char diagonal[maxNumberOfElementsInDiagonal];

        for (int k = 0; k < numberOfElementsInDiagonal; k++)
            diagonal[k] = values[k][j - k];

        if (isConsecutiveFour(diagonal, numberOfElementsInDiagonal))
            return true;
    }

    // Check sub-diagonal (right part)
    for (int i = 1; i < numberOfRows - 3; i++) {
        int numberOfElementsInDiagonal = min(numberOfRows - i, numberOfColumns);
        char diagonal[maxNumberOfElementsInDiagonal];

        for (int k = 0; k < numberOfElementsInDiagonal; k++)
            diagonal[k] = values[k + i][numberOfColumns - k - 1];

        if (isConsecutiveFour(diagonal, numberOfElementsInDiagonal))
            return true;
    }

    return false;
}

bool isConsecutiveFour(const char values[], int size) {
    for (int i = 0; i < size - 3; i++) {
        bool isEqual = true;

        for (int j = i; j < i + 3; j++) {
            if (values[j] == ' ' || values[j] != values[j + 1]) {
                isEqual = false;
                break;
            }
        }

        if (isEqual) return true;
    }

    return false;
}
