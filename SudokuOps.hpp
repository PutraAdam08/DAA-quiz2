#include <bits/stdc++.h>
#include "SudokuClass.hpp"

class sudops : private sudoku{
    public:
        void inVal(int x, int y, int v) {
            bool (*fixn)[9] = getfNum();
            if (!fixn[y][x]) {
                assign(y, x, v);
            } else {
                cout << "Warning: You cannot insert number in that cell" << endl;
            }
        }

        bool UsedInRow(int s[9][9], int row, int num){
            for (int col = 0; col < 9; col++)
                if (s[row][col] == num)
                    return true;
            return false;
        }

        bool UsedInCol(int s[9][9], int col, int num){
            for (int row = 0; row < 9; row++)
                if (s[row][col] == num)
                    return true;
            return false;
        }
        
        bool UsedInBox(int s[9][9], int boxStartRow, int boxStartCol, int num){
            if(num == 0)
                return false;

            for (int row = 0; row < 3; row++)
                for (int col = 0; col < 3; col++)
                    if (s[row + boxStartRow][col + boxStartCol] == num)
                        return true;
            return false;
        }

        bool isSafeC(int s[9][9], int row, int col, int num){
            return !UsedInRowC(s, row, num) && !UsedInColC(s, col, num) && !UsedInBoxC(s, row - row % 3, col - col % 3, num) && s[row][col] == 0;
        }

        bool UsedInRowC(int s[9][9], int row, int num){
            if(num == 0)
                return false;

            for (int col = 0; col < 9; col++)
                if (s[row][col] == num)
                    return true;
            return false;
        }

        bool UsedInColC(int s[9][9], int col, int num){
            if(num == 0)
                return false;

            for (int row = 0; row < 9; row++)
                if (s[row][col] == num)
                    return true;
            return false;
        }
        
        bool UsedInBoxC(int s[9][9], int boxStartRow, int boxStartCol, int num){
            if(num == 0)
                return false;

            for (int row = 0; row < 3; row++)
                for (int col = 0; col < 3; col++)
                    if (s[row + boxStartRow][col + boxStartCol] == num)
                        return true;
            return false;
        }

        bool isSafe(int s[9][9], int row, int col, int num){
            return !UsedInRow(s, row, num) && !UsedInCol(s, col, num) && !UsedInBox(s, row - row % 3, col - col % 3, num) && s[row][col] == 0;
        }

        void level(int difficulty) {
            // Clear the current sudoku board
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    assign(i, j, 0);
                    setFixed(i, j, false);
                }
            }

            int prefilledCells;
            switch (difficulty) {
                case 1: // Easy
                    prefilledCells = 36;
                    break;
                case 2: // Medium
                    prefilledCells = 27;
                    break;
                case 3: // Hard
                    prefilledCells = 18;
                    break;
                default:
                    prefilledCells = 36; // Default to Easy
            }

            srand(time(0));
            while (prefilledCells > 0) {
                int row = rand() % 9;
                int col = rand() % 9;
                int num = (rand() % 9) + 1;
                if (isSafe(getSudo(), row, col, num)) {
                    assign(row, col, num);
                    setFixed(row, col, true);
                    prefilledCells--;
                }
            }
        }

        bool isCorrect(int grid[9][9], int row, int col){
            if (row == 9 - 1 && col == 9)
                return true;
            if (col == 9) {
                row++;
                col = 0;
            }

            if (isSafeC(grid, row, col, grid[row][col]))
                return isCorrect(grid, row, col + 1);
            else
                return false;
        }

        bool solveSudoku(int grid[9][9], int row, int col)
        {
 
            if (row == 9 - 1 && col == 9)
                return true;
            if (col == 9) {
                row++;
                col = 0;
            }
            if (grid[row][col] > 0)
                return solveSudoku(grid, row, col + 1);
        
            for (int num = 1; num <= 9; num++) 
            {

                if (isSafe(grid, row, col, num)) 
                {

                    grid[row][col] = num;
                    if (solveSudoku(grid, row, col + 1))
                        return true;
                }
                grid[row][col] = 0;
            }
            return false;
        }
        void prints(){
            print();
        } 

        int(*getsUdo())[9]{
            return getSudo();
        } 


};