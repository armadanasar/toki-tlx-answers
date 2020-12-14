#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct Beras {
    int stock;
    int totalHarga;
    double hargaPerKilo;
};

Beras listBeras[10240];
int dataCount = 0;

void sortDataBeras() {
    int idx = 0;
    for (int i = 0; i < dataCount; i++) {
        idx = i;
        for (int j = (i+1); j < dataCount; j++) {
            if (listBeras[j].hargaPerKilo > listBeras[idx].hargaPerKilo)
                idx = j;
        }

            Beras temp = listBeras[i];
            listBeras[i] = listBeras[idx];
            listBeras[idx] = temp;

    }
}

int main()
{
    int n = 0, x = 0;
    cin >> n >> x;
    cin;

    for (int i = 0; i < n; i++) {
        cin >> listBeras[i].stock;
    }

    for (int i = 0; i < n; i++) {
        cin >> listBeras[i].totalHarga;
        listBeras[i].hargaPerKilo = (double)listBeras[i].totalHarga/(double)listBeras[i].stock;
        dataCount++;
    }

    sortDataBeras();

    for (int i = 0; i < n; i++) {
        //cout << listBeras[i].hargaPerKilo << " ";
    }
    //cout << endl;

    int pos = 0;
    double result = 0.0f;

    while (x > 0 && pos < dataCount) {
        if (x >= listBeras[pos].stock) {
            x-= listBeras[pos].stock;
            result += (double)listBeras[pos].totalHarga;
        }

        else {
            result += (double)x * (double)(listBeras[pos].hargaPerKilo);
            x-=x;
        }
        //printf("Result now: %.5f\tX now: %d\n", result, x);
        pos++;
    }

    printf("%.5f\n", result);
    return 0;
}