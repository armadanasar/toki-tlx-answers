#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int rowCount = 0, colCount = 0, rows = 0, cols = 0, argLen = 0, ma = 0, dataCount = 0;
string args[25600], cur;
char papan[1024][1024];

int main()
{
    int n = 0;
    cin >> n;
    int loop = 0;
    while (loop < n) {
        cin >> cur;
        args[dataCount] = cur;
        dataCount++;
        loop++;
    }
    cin >> rows >> cols;

    for (int i = 0; i < dataCount; i++) {
        argLen = args[i].length();
        ma = max(ma, argLen);
    }



    int side = max(rows, cols), idx = 1;

    while (idx < side) {
        idx *= 2;
    }

    rowCount = idx, colCount = idx;

    for (int i = 1; i <= rowCount; i++) {
        for (int j = 1; j <= colCount; j++) {
            papan[i][j] = '0';
        }
    }

    for (int i = 0; i < dataCount; i++) {
        int pos = rowCount, left = 1, top = 1, bottom = rowCount, right = rowCount, len = args[i].length();

        string temp = args[i];

        for (int j = 1; j < len; j++) {
            pos /= 2;

            if (temp[j] == '0'){
                right = (left+right)/2;
                bottom -= pos;
            }
            else if (temp[j] == '1') {
                bottom = (top+bottom)/2;
                left += pos;
            }

            else if (temp[j] == '2') {
                right = (left + right)/2;
                top += pos;
            }
            else if (temp[j] == '3') {
                left += pos;
                top += pos;
            }
        }

        for (int j = top; j <= bottom; j++) {
            for (int k = left; k <= right; k++) {
                papan[j][k] = '1';
            }
        }
    }
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (j == cols)
                cout << papan[i][j] << endl;
            else
                cout << papan[i][j] << " ";
        }
        //cout << endl;
    }
    return 0;
}
