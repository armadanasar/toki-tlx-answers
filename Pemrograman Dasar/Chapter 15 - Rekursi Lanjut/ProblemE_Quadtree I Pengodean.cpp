#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

template <typename T>
  std::string NumberToString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

using namespace std;

int papan[1024][1024];
int rows = 0, cols = 0;
string result[10240];
int dataCount = 0;
bool done = false;
int jumRow = 0, jumCol = 0;

int getNearestTwoSquare(int n) {
    int v = n;

    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;

    return v;
}

void scan(string idNow, int id, int startRow, int endRow, int startCol, int endCol) {
    int elemCount = 0;
    bool allOne = true;
    bool allZero = true;
    string current = "";
    string val = "";
    if (endCol - startCol < 0 || endRow - startRow < 0)
        return;

    //printf("\n\nDEBUG:\n");
    //cout << "idNow: " << idNow << endl;
    //printf("id: %d\nstartRow: %d\nendRow: %d\nstartCol: %d\nendCol: %d\n", id, startRow, endRow, startCol, endCol);

    if (id != -1)
         current = idNow + NumberToString(id);

    for (int i = startRow; i <= endRow; i++) {
            //cout << "Segment " << startRow << "to " << endRow << endl;
        for (int j = startCol; j <= endCol; j++) {
            elemCount++;
            //printf("%c ", papan[i][j]);
        }
        //cout << endl;
    }
    //cout << "elemCount: " << elemCount << endl;
    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            if (papan[i][j] != 0)
                allZero = false;
            else if (papan[i][j] != 1)
                allOne = false;
        }
    }

    if (id == -1) {
        if (allOne) {
            cout << "1\n1\n";
            done = true;
            return;
        }

        if (allZero) {
            cout << "0\n";
            done = true;
            return;
        }

    }

    if (id != -1) {
        if (allOne) {
            val = "1" + current;
            //cout << "val: " <<  val << endl;
            result[dataCount] = val;
            dataCount++;
            return;
        }

        if (elemCount == 1) {
          /*  if (allZero) {
                string val = "0" + id;
                result[dataCount] = val;
                dataCount++;
            }*/

            if (allOne) {
                val = "1" + current;
                //cout << "val: " <<  val << endl;
                result[dataCount] = val;
                dataCount++;
            }

            return;
        }

        /*if (allZero) {
            string val = "0" + id;
            result[dataCount] = val;
            dataCount++;
            return;
        }*/

        if (allOne) {
            val = "1" + id;
            //cout << "CODE: " << val << endl;
            result[dataCount] = val;
            dataCount++;
            return;
        }
    }

    //kiri atas
    scan(current, 0, startRow, (startRow + endRow)/2, startCol, (startCol + endCol)/2);

    //kanan atas
    scan(current, 1, startRow, (startRow + endRow)/2, ((startCol+endCol)/2)+1, endCol);

    //kiri bawah
    scan(current, 2, ((startRow + endRow)/2)+1, endRow, startCol, (startCol + endCol)/2);

    //kanan bawah
    scan(current, 3, ((startRow + endRow)/2)+1, endRow, ((startCol + endCol)/2)+1, endCol);
}


int main()
{
    cin >> jumRow >> jumCol;
    //cout << getNearestTwoSquare(jumRow) << " " << getNearestTwoSquare((jumCol));
    //getchar(); getchar();

    rows = getNearestTwoSquare(jumRow);
    cols  = getNearestTwoSquare(jumCol);

    rows = max(rows, cols);
    cols = max(rows, cols);


    int newRows = 0, newCols = 0;

    //kalo emang udah pangkat dua terdekat, lakuin ini.
    if (jumRow == getNearestTwoSquare(jumRow) && jumCol == getNearestTwoSquare(jumCol)) {
        //printf("masuk sini\n");
        for (int i = 1; i <= jumRow; i++) {
            for (int j = 1; j <= jumCol; j++) {
                cin >> papan[i][j];
            }
        }
        scan("", -1, 1, rows, 1, cols);
    }

    //kalo nggak...
    else {
        //printf(" >> %d %d\n", rows, cols);
        newRows = rows;
        newCols = cols;
        //newRows++;
        //newCols++;

        for (int i = 1; i <= newRows; i++) {
            for (int j = 1; j <= newCols; j++) {
                papan[i][j] = 0;
            }
        }

        for (int i = 1; i <= jumRow; i++) {
            //cin >> (papan[i]+1);
            for(int j=1; j<=jumCol; j++) {
                cin >> papan[i][j];
            }
        }

        scan("", -1, 1, newRows, 1, newCols);
    }

    //if (!dataCount)
    //    cout << "0\n" << endl;
    if (!done) {
        cout << dataCount << endl;
        for (int i = 0; i < dataCount; i++) {
            if ( i < (dataCount - 1))
                cout << result[i] << endl;
            else
                cout << result[i] << endl;
        }
    }

    return 0;
}