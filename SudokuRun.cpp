#include "SudokuOps.hpp"
#include <iostream>

class SudokuRun {
public:
    void run() {
        sudops sudo;
        int level;

        while (true) {
            cout << "Enter difficulty level (1 - Easy, 2 - Medium, 3 - Hard): ";
            cin >> level;

            sudops sudup;
            sudo.level(level);
            sudo.prints();
            cout << endl;

            // Duplicate the Sudoku board and fixed numbers array
            sudup.setSudo(sudo.getsUdo());
            //int (*originalSudo)[9] = sudo.getsUdo();
            //bool (*originalFixNum)[9] = sudo.getfNum();

            /*for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    duplicateSudo[i][j] = originalSudo[i][j];
                }
            }*/

            while (true) {
                int x, y, v;
                cout << "Enter coordinates (x, y) and value to insert (or enter 0 0 0 to check): ";
                cin >> x >> y >> v;

                if (x == 0 && y == 0 && v == 0) {
                    // Use the duplicate board to solve the Sudoku
                    system("cls");
                    if (sudo.isCorrect(sudo.getsUdo(), 0, 0)) {
                        cout << "Congratulations, the solution is correct!" << endl;
                        sudo.prints();
                    } else {
                        if(sudup.solveSudoku() == true){
                            cout << "Solution is incorrect. Here is the correct solution:" << endl;
                            // Solve the duplicate grid
                            sudup.prints(); // Print the solved grid
                        }
                        else cout << "Solution incorrect, no soulution available for this level\n";
                    }
                    break;
                } else {
                    system("cls");
                    sudo.inVal(x, y, v);
                    sudo.prints();
                }
            }

            char playAgain;
            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;
            if (playAgain != 'y' && playAgain != 'Y') {
                system("cls");
                break;
            }
            system("cls");
        }
    }

    void printGrid(int grid[9][9]) {
        cout << " ";
        for (int j = 0; j < 9; j++) {
            cout << " " << j;
        }
        cout << endl;
        for (int i = 0; i < 9; i++) {
            cout << i;
            for (int j = 0; j < 9; j++) {
                cout << " " << grid[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    SudokuRun game;
    game.run();
    return 0;
}