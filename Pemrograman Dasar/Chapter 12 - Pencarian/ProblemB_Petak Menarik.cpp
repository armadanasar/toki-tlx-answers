#include <iostream>
#include <bits/stdc++.h>

#define g getchar();
using namespace std;

typedef struct Petak {
    int value;
    int adjacentValue;
};

Petak petaks[102][102];

int getAdjacentValues(int posX, int posY) {
    int atas = petaks[posX-1][posY].value;
    int bawah = petaks[posX+1][posY].value;
    int kiri = petaks[posX][posY-1].value;
    int kanan = petaks[posX][posY+1].value;

    return (atas * bawah * kiri * kanan);
}


int main()
{
    int n = 0, m = 0, k = 0;
    int minX = 0;
    int minY = 0;

    //ctor Petaks class
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            petaks[i][j].value = 1;
            petaks[i][j].adjacentValue = 0;
        }
    }

    scanf("%d %d %d", &n, &m, &k); g

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &petaks[i][j].value);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            petaks[i][j].adjacentValue = getAdjacentValues(i, j);

        }
    }

    //Loop baru dengan kolom dulu baru baris/ditranspose
    int termo = 0;
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (petaks[i][j].adjacentValue == k) {
                minX = i;
                minY = j;
                termo = 1;
                break;
            }
        }
        if (termo) {
            break;
        }
    }

    printf("%d %d\n", minX, minY);
    return 0;
}