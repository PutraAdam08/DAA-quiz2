#include <bits/stdc++.h>
#include "SudokuClass.hpp"

class Sudops : private sudoku{
    public:
        int inVal(int s[9][9]){ // <- Insert value with checking wether the array in value is the fixed number

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
            for (int row = 0; row < 3; row++)
                for (int col = 0; col < 3; col++)
                    if (s[row + boxStartRow][col + boxStartCol] == num)
                        return true;
            return false;
        }

        bool isSafe(int s[9][9], int row, int col, int num){
            return !UsedInRow(s, row, num) && !UsedInCol(s, col, num) && !UsedInBox(s, row - row % 3, col - col % 3, num) && s[row][col] == 0;
        }


};