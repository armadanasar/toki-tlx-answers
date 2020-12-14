#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int papan[1000][1000];

int baris = 0, kolom = 0;


void floodFill(int y, int x, int val, int *output) {
    if (y < 0 || y > baris-1)
        return;
    if (x < 0 || x > kolom-1)
        return;

    if (papan[y][x] != val)
        return;
    if (papan[y][x] == -1)
        return;

    (*output)++;
    //cout << (*output) << endl;

    papan[y][x] = -1;   //disabled

    floodFill(y-1, x, val, output);
    floodFill(y+1, x, val, output);
    floodFill(y, x-1, val, output);
    floodFill(y, x+1, val, output);
}

int main()
{
    cin >> baris >> kolom;

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cin >> papan[i][j];
        }
    }

    int maxScore = 0;

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            int result = 0;
            floodFill(i, j, papan[i][j], &result);

            int curr = (result * (result - 1));
            if (curr >= maxScore)
                maxScore = curr;
        }
    }


    cout << maxScore << endl;
    return 0;
}