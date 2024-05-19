#include <bits/stdc++.h>
using namespace std;

class sudoku{
    private: 
        int sudoArr[9][9];
        bool fixNum[9][9];
    
    public:
        void assign(int x, int y, int v){
            sudoArr[x][y] = v;
        }

        void setFixed(int x, int y, int v){
            fixNum[x][y] = v;
        }

        sudoku(){
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    sudoArr[i][j] = 0;
                    fixNum[i][j] = false;
                }
            }
        }
}

