#include <iostream>
using namespace std;

int main() {
    // Starting puzzle grid (0 = empty)
    int grid[9][9] = {
        {1, 6, 8, 0, 0, 0, 9, 0, 2},
        {0, 0, 0, 3, 0, 1, 0, 0, 0},
        {0, 3, 0, 6, 2, 0, 0, 0, 0},
        {0, 0, 9, 0, 0, 0, 1, 0, 6},
        {0, 0, 1, 0, 0, 0, 3, 7, 0},
        {0, 4, 3, 5, 0, 0, 0, 0, 9},
        {0, 0, 0, 8, 0, 2, 6, 0, 0},
        {0, 0, 0, 9, 0, 5, 0, 2, 3},
        {2, 0, 6, 0, 3, 0, 7, 0, 0}
    };

    while (true) {
        // 1. SHOW CURRENT BOARD
        cout << "\n--- CURRENT SUDOKU BOARD ---\n";
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                cout << grid[r][c] << " ";
            }
            cout << endl;
        }

        // 2. GET USER INPUT
        int row, col, num;
        cout << "\nEnter Row (0-8), Col (0-8), Num (1-9) [-1 to reveal solution]: ";
        cin >> row;

        // IF USER TYPES -1 -> REVEAL SOLUTION AND EXIT
        if (row == -1) {
            int solved[9][9] = {
                {1, 6, 8, 7, 5, 4, 9, 3, 2},
                {4, 2, 7, 3, 9, 1, 5, 8, 6},
                {9, 3, 5, 6, 2, 8, 4, 1, 7},
                {7, 8, 9, 2, 4, 3, 1, 5, 6},
                {5, 2, 1, 8, 6, 9, 3, 7, 4},
                {6, 4, 3, 5, 1, 7, 2, 8, 9},
                {3, 5, 4, 8, 7, 2, 6, 9, 1},
                {8, 7, 2, 9, 6, 5, 4, 2, 3},
                {2, 1, 6, 4, 3, 8, 7, 9, 5}
            };

            cout << "\n=================================\n";
            cout << "   HERE IS THE SOLVED SUDOKU:   \n";
            cout << "=================================\n";
            for (int r = 0; r < 9; r++) {
                for (int c = 0; c < 9; c++) {
                    cout << solved[r][c] << " ";
                }
                cout << endl;
            }
            break;
        }

        cin >> col >> num;

        // 3. VALIDATION CHECK
        if (row >= 0 && row <= 8 && col >= 0 && col <= 8 && num >= 1 && num <= 9) {
            grid[row][col] = num;
            cout << "-> SUCCESS: Placed " << num << " at spot (" << row << ", " << col << ")\n";
        } else {
            cout << "-> INVALID INPUT! Row/Col must be 0-8 and Number must be 1-9. Try again.\n";
        }
    }

    return 0;
}