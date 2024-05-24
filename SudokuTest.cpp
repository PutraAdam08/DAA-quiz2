#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "SudokuOps.hpp"
using namespace std;

int main(){
    sudops sudo;
    int l = 0;

    cin >> l;
    sudo.level(l);
    sudo.prints();
    cout << endl;

    int v, x, y;
    if(sudo.isCorrect(sudo.getsUdo(), 0, 0))
        cout << "Yes" << endl;
    else{
        cout << "No" << endl;
    }
    
    sudo.solveSudoku(sudo.getsUdo(), 0, 0);
    
    //cin >> x >> y >> v;
    //sudo.inVal(x, y, v);
    //sudo.prints();


    


    return 0;
}