#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string catat[10000];
bool pernah[10240];
int jumCetak = 0;
int jumlah = 0;
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
int n = 0;
void permutasiTanpaUlang(int kedalaman, int stop) {
    int i = 0;

    if (kedalaman > stop) {
        for (int i = 1; i <= stop; i++) {
            cout << catat[i] << " ";
        }

        cout << endl;
        jumCetak++;
    }

    else {
        for (int i = 1; i <= n; i++) {
            if (!pernah[i]) {
                pernah[i] = true;
                catat[kedalaman] = NumberToString(i);
                permutasiTanpaUlang(kedalaman+1, stop);
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


//bool pernah[10240];

void permutasiTanpaUlangNew(int kedalaman, int n) {

    int i = 0;

    if (kedalaman > n) {
        for (int i = 1; i <= n; i++) {
            cout << catat[i] << " ";
        }

        cout << endl;
        jumCetak++;
    }

    else {
        for (int i = 1; i <= jumlah; i++) {
            if (!pernah[i]) {
                pernah[i] = true;
                catat[kedalaman] = NumberToString(i);
                permutasiTanpaUlang(kedalaman+1, n);
                pernah[i] = false;
            }
        }
    }
}

//yes, I use libraries
template <typename Iterator>
bool next_combination(const Iterator first, Iterator k, const Iterator last)
{
   /* Credits: Mark Nelson http://marknelson.us */
   if ((first == last) || (first == k) || (last == k))
      return false;
   Iterator i1 = first;
   Iterator i2 = last;
   ++i1;
   if (last == i1)
      return false;
   i1 = last;
   --i1;
   i1 = k;
   --i2;
   while (first != i1)
   {
      if (*--i1 < *i2)
      {
         Iterator j = k;
         while (!(*i1 < *j)) ++j;
         std::iter_swap(i1,j);
         ++i1;
         ++j;
         i2 = k;
         std::rotate(i1,j,last);
         while (last != j)
         {
            ++j;
            ++i2;
         }
         std::rotate(k,i2,last);
         return true;
      }
   }
   std::rotate(first,k,last);
   return false;
}

int main()
{
//    for (int i = 0; i < 10240; i++) {
//        pernah[i] = false;
//    }
    int k = 0;
    cin >> jumlah >> k;
    n = jumlah;
    //permutasiTanpaUlangHelp(1, k);
  //  cout << endl << endl << endl;
   // permutasiTanpaUlangNew(1,k);
    string s = "";
    for (int i = 1; i <= jumlah; i++) {
        s = s + NumberToString(i);
    }

   do {
     for (int i = 0; i < k; i++) {
        if (i < k-1)
            cout << s[i] << " ";
        else
            cout << s[i];
     }
     cout << endl;
   } while (next_combination(s.begin(), s.begin() + k, s.end()));


    return 0;
}
