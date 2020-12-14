#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//hapus char ke-i dengan timpa i+1 ke i sampai selesai
string erase(string s, int x) {
    int y = x, len = s.size();
    while (y < len) {
        s[y] = s[y+1];
        y++;
    }
    return s;
}

int main()
{
    string a, b, aa;
    int lena = 0, lenb = 0;
    int dist = 0, posa = 0, posb = 0;
    int hur1[26], hur2[26], temp, count;
    bool iya;
    cin >> a;
    cin >> b;

    lena = a.size(); lenb = b.size();
    //std::sort(a, (a+lena));
    //std::sort(b, (b+lenb));
    //cout << a << " " << b << endl;

    //kalau emang difference length a dg b > 1, maka tidak bisa
    if (lena - lenb > 1 || lena - lenb < 1) {
            cout << "Wah, tidak bisa :(\n";
            return 0;
    }

    else {
        bool sama1 = false, sama2;
        int i = 0;

        //selama tidak sama 1 && i < lena
        while (!sama1 && i < lena) {
            //coba satu2, hapus char by char
            aa = erase(a, i);
            //geledah aa dg b karakter per karakter
            for (int j = 0; j < lenb; j++) {
                //asumsi betul aja dulu
                sama2 = true;
                //kalo ga sama sama2 = false
                if (aa[j] != b[j])
                    sama2 = false;
            }
            //kalo sama2 = true, maka sama1 = true juga dan break!
            if (sama2)
                sama1 = true;

            //maju idx by 1
            i++;
        }

        //print hasil
        if (sama1)
            cout << "Tentu saja bisa!\n";
        else
            cout << "Wah, tidak bisa :(\n";
    }

    return 0;
}