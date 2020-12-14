#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int score = 0;
int papanmain[1024][1024];
int rowCount = 0;
int colCount = 0;

void floodFill(int val, int row, int col) {

    if (papanmain[row][col] == 0)
        return;
    if (papanmain[row][col] != val)
        return;

    papanmain[row][col] = 0;
    score++;

    //kalo belom mentok atas, naik ke atas
    if (row > 0)
        floodFill(val, row-1, col);

    //kalo belom mentok bawah, turun ke bawah
    if (row < rowCount-1)
        floodFill(val, row+1, col);

    //kalo belom mentok kanan, lari ke kanan
    if (col < colCount-1)
        floodFill(val, row, col+1);

    //kalo belom mentok kiri, periksa ke kiri
    if (col > 0)
        floodFill(val, row, col-1);
}

int main()
{
    cin >> rowCount >> colCount;

    for (int i = 0; i< rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cin >> papanmain[i][j];
        }
    }
    //cin; cin;
    int row = 0, col = 0;

    cin >> row >> col;

    floodFill(papanmain[row][col], row, col);

    //floodFillCheck(peta[y-1][x-1], y-1, x-1);

    cout << score * (score-1) << endl;

    //getchar(); getchar();
    //cout << "Hello world!" << endl;
    return 0;
}