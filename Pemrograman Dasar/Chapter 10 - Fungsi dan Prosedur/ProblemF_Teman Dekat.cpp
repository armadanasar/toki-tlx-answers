#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define g getchar();
using namespace std;

typedef struct TemanDetail {
    int xi;
    int yi;
};



int closenessMatrix[1001][1001];

int main()
{
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++)
            closenessMatrix[i][j] = -1;
    }

    FILE *fileWriter = 0;
    int jumlahTeman = 0;
    int pangkat = 0;
    int max = 0;
    int min = INT_MAX;
    TemanDetail temans[1001];
    scanf("%d %d", &jumlahTeman, &pangkat); //g

    for (int i = 1; i <= jumlahTeman; i++) {
        scanf("%d %d", &temans[i].xi, &temans[i].yi);
    }




    for (int i = 1; i <= jumlahTeman; i++) {
        for (int j = 1; j <= jumlahTeman; j++) {
            if (i == j)
                continue;
            if (closenessMatrix[i][j] == -1) {
                if (closenessMatrix[j][i] == -1) {
                    closenessMatrix[i][j] = pow(abs(temans[j].xi - temans[i].xi), pangkat) + pow(abs(temans[j].yi - temans[i].yi), pangkat);
                }
               else {
                    closenessMatrix[i][j] = closenessMatrix[j][i];
                }
                int helper = closenessMatrix[i][j];
                if (helper > max)
                    max = helper;
                if (helper < min)
                    min = helper;
                //printf("%d ", helper);
            }
        }
        //putchar('\n');
    }
    /*
    for (int i = 0; i < jumlahTeman; i++) {
        for (int j = 0; j < jumlahTeman; j++) {
            printf("%d ", closenessMatrix[i][j]);
        }
        putchar('\n');
    }*/
    //printf("Done!\n");
    printf("%d %d\n", min, max);
    //g

    //cout << "Hello world!" << endl;
    return 0;
}