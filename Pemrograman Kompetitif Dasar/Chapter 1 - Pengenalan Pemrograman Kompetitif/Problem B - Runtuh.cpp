#include <bits/stdc++.h>
using namespace std;
string papan[1024];

int rows = 0, cols = 0;

vector<int> checkHBlank() {
    //cout << "on hBlank check\n";
    vector<int> hasil;
    for (int i = rows-1; i >= 0; i--) {
        bool isHBlankable = true;
        for (int j = 0; j < cols; j++) {
            if (papan[i][j] != '1')
                isHBlankable = false;
        }
        if (isHBlankable) {
            hasil.push_back(i);
            //   cout << i << endl;
            // getchar();
            //getchar();
        }
    }
    return hasil;
}

void hBlank(int row) {
    for (int i = 0; i < cols; i++) {
        papan[row][i] = '0';
    }
}


//ide: cek dari baris teratas, cek baris bawahnya
//kalo ada muat masukin blok ke space kosong di bawah, masukin

void collapse(int baris, int kolom) {
    int j, k , l;
    for (int j = baris; j < rows-1 ; j++) {
        if (papan[j+1][kolom] == '1') break;
        else {
            papan[j+1][kolom] = '1';
            papan[j][kolom] = '0';

        }
    }
}

//ide: mulai dulu dari cek baris penuh, kosongin, terus runtuhin terus cek lg dr awal. kalo ada yg penuh, lanjut, kalo ga da brenti.
void mainLoop() {
    // cout << "at main loop\n";
    vector<int> hBlankList = checkHBlank();

    while (hBlankList.size() > 0) {
        //  getchar();
        //do {
        for (int i = 0; i < hBlankList.size(); i++) {

            hBlank(hBlankList[i]);
            //cout << "hBlanked " << hBlankList[i] << endl;
        }
        //    collapse2();
        //    hBlankList = checkHBlank();
        //} while (hBlankList.size() > 0);
        int mulaiRuntuh = hBlankList[0];
        //   cout << mulaiRuntuh << endl;
        // cout << "at process\n";
        for (int i = mulaiRuntuh-1; i >= 0; i--) {
            for (int j = 0; j < cols; j++) {
                if (papan[i][j] == '1')
                    collapse(i, j);
            }
        }
        hBlankList = checkHBlank();
    }
}

int main() {
    //funcTest();
    scanf("%d %d", &rows, &cols);

    for (int i = 0; i < rows; i++) {
        cin >> papan[i];
    }

    mainLoop();

    for (int i = 0; i < rows; i++) {
        //cout << "filling " << i << endl;
        //for (int j = 0; j < 6; j++) {
        cout << papan[i];
        //}
        cout << endl;
    }
    return 0;
}