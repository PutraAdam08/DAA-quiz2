#include <bits/stdc++.h>
using namespace std;

class sudoku{
    private: 
        int sudoArr[9][9];
        bool fixNum[9][9];
    
    public:
        void assign(int y, int x, int v){
            sudoArr[y][x] = v;
        }

        void setSudo(int s[9][9]) {
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    sudoArr[i][j] = s[i][j];
                }
            }
        }

        void setFixed(int x, int y, bool v){
            fixNum[x][y] = v;
        }

        int(*getSudo())[9] {
            return sudoArr;
        }

        bool(*getfNum())[9] {
            return fixNum;
        }

        void print(){
            cout << " ";
            for(int j = 0; j < 9; j++){
                cout << " " << j;
            }
            cout << endl;
            for(int i = 0; i < 9; i++){
                cout << i;
                for(int j = 0; j < 9; j++){
                    cout << " " << sudoArr[i][j];
                }
                cout << endl;
            }
        }

        sudoku(){
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    sudoArr[i][j] = 0;
                    fixNum[i][j] = false;
                }
            }
        }
};

