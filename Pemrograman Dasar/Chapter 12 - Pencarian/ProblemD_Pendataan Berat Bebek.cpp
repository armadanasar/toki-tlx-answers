#include <iostream>
#include <bits/stdc++.h>

int querycount = 0;
int x = 0, y = 0;

int beratbebek[101000];
int jumlahbebek = 0;

using namespace std;

int main()
{
    int n = 0;

    scanf("%d", &n);

    int i = 0;
    while (i < n) {
        scanf("%d", &beratbebek[i]);
        i++;
    }
    jumlahbebek = n;

    vector<int> v(beratbebek, beratbebek+jumlahbebek);
    vector<int>::iterator low, up;

    scanf("%d", &querycount);

    i = 0;
    while (i < querycount) {
        scanf("%d %d", &x, &y);
        low = lower_bound(v.begin(), v.end(), x+1);
        up = upper_bound(v.begin(), v.end(), y);

        printf("%d\n", up-low);
        i++;
    }
    return 0;
}