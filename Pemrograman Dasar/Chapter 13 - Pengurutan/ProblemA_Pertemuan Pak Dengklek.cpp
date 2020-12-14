#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string arr[501];
int arrsize = 0;

void selectionSort() {
    int lowestIndex = 0;
    int temp = 0;
    int j = 0;
    for (int i = 1; i<= arrsize; i++) {
        lowestIndex = i;
        for (j = i+1; j <= arrsize; j++) {
            if (arr[j].length() < arr[lowestIndex].length())
                lowestIndex = j;
            if ( (arr[j].length() == arr[lowestIndex].length()) &&
                 (strcmp(arr[j].c_str(), arr[lowestIndex].c_str()) < 0)
                )
                    lowestIndex = j;
        }
        string temp = arr[lowestIndex];
        arr[lowestIndex] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int n = 0;
    cin >> n;
    arrsize = n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    selectionSort();

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << endl;
    }

    //cin; cin;
    //cout << "Hello world!" << endl;
    return 0;
}