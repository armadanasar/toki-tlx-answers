#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
int arr[100001];
int arrsize = 0;
 
void countingSort() {
    int countSortCache[101];
    memset(&countSortCache, 0, 4 * 101);
    for (int i = 1; i <= arrsize; i++) {
        countSortCache[arr[i]]++;
    }
 
    int j = 1;
    for (int i = 0; i <= 100; i++) {
        if (countSortCache[i] > 0) {
            for (int k = 0; k < countSortCache[i]; k++) {
                arr[j] = i;
                j++;
            }
        }
    }
}
 
 
int main()
{
    memset(&arr, 0, 4 * 100001);
 
    int n = 0;
 
    cin >> n;
    arrsize = n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
 
    countingSort();
 
    if (arrsize % 2) {
        printf("%.1f\n", (float)(arr[(arrsize/2)+1]));
    }
 
    else {
          printf("%.1f\n", (float)((arr[(arrsize/2)] + arr[(arrsize/2)+1])/2.0));
//printf("%d %d\n", arr[(arrsize/2)], arr[(arrsize/2)+1]);
    }
    return 0;
}