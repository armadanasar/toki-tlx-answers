#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string catat[10000];
bool pernah[10240];
int jumCetak = 0;

template <typename T>
  std::string NumberToString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

void permutasiBerulang(int kedalaman, int n) {
    int i = 0;

    if (kedalaman > n) {
        for (int i = 1; i <= n; i++) {
            cout << catat[i];
        }

        cout << endl;
        jumCetak++;
    }

    else {
        for (int i = 1; i <= n; i++) {
            catat[kedalaman] = NumberToString(i);
            permutasiBerulang(kedalaman+1, n);
        }
    }
}

void permutasiTanpaUlang(int kedalaman, int n) {

    int i = 0;

    if (kedalaman > n) {
        for (int i = 2; i <= n-1; i++) {
            // aturan
            // if ((catat[i] < catat[i-1] && catat[i] < catat[i+1]) || (catat[i] > catat[i-1] && catat[i] > catat[i+1]))

            //negasinya yang dipake :)
            if (!(catat[i] < catat[i-1] && catat[i] < catat[i+1]) && !(catat[i] > catat[i-1] && catat[i] > catat[i+1]))
                return;
        }


        for (int i = 1; i <= n; i++) {
            cout << catat[i];
        }

        cout << endl;
        jumCetak++;
    }

    else {
        for (int i = 1; i <= n; i++) {
            if (!pernah[i]) {
                pernah[i] = true;
                catat[kedalaman] = NumberToString(i);
                permutasiTanpaUlang(kedalaman+1, n);
                pernah[i] = false;
            }
        }
    }
}

void permutasiTanpaUlangHelp(int kedalaman, int n) {
    for (int i = 0; i < 10240; i++) {
        pernah[i] = false;
    }

    permutasiTanpaUlang(kedalaman, n);
}

int main()
{
    int n = 0;
    cin >> n;

    permutasiTanpaUlangHelp(1, n);
    return 0;
}