#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "SudokuClass.hpp"
using namespace std;

int main(){
    sudoku Sudo;
    Sudo.print();
    Sudo.assign(0, 0, 9);
    int t;
    cin >> t;
    system("cls");
    Sudo.print();
    return 0;
}