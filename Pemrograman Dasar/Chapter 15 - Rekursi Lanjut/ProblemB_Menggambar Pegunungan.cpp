#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//FILE *logfile = 0;
void print(int n) {
        for (int i = 0; i < n; i++) {
            putchar('*');
        }
        putchar('\n');
        printf("*\n");
}

void helperUp(int curr, int stop) {
    if (curr < stop) {
        print(curr);
        print(2);
        helperUp(curr+1, stop);

    }

    else {
        print(curr);
        print(2);
    }
}


void helperDown(int curr) {
    if (curr == 2) {
        print(2);
    }

    else {
        print(curr);
        helperDown(curr-1);
    }
}

void cetak(int n) {
    //fprintf(logfile, "Called: %d\n", n);
    if (n > 0 && n <= 2) {
        print(n);
    }

    else {
        cetak(n-1);
        print(n);
        cetak(n-1);
    }
}


void printMountain(int n) {
    putchar('*');
    putchar('\n');
    helperUp(2, n);
    helperDown(n-1);

}


int main()
{
    //logfile = fopen("log.txt", "w");

    int n = 0;
    cin >> n;

    if (n == 1) {
        printf("*\n");
        return 0;
    }

/*    else if (n == 2) {
        printf("*\n**\n*\n");
        return 0;
    }*/
    printf("*\n");
    cetak(n);
  //  printMountain(n);



    getchar(); getchar();

    //cout << "Hello world!" << endl;
    //fclose(logfile);
    return 0;
}