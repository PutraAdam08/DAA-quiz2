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
    cin >> x >> y >> v;
    sudo.inVal(x, y, v);
    sudo.prints();
    


    return 0;
}