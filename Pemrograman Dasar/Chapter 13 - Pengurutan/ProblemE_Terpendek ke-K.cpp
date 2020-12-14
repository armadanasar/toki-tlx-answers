#include <iostream>

using namespace std;
int arr[1001];
int arrSize = 0;

void partialSort(int n) {
    int lowestIndex = 0;
    int temp = 0;
    int j = 0;
    for (int i = 1; i<= n; i++) {
        lowestIndex = i;
        for (j = i+1; j <= arrSize; j++) {
            if (arr[j] < arr[lowestIndex])
                lowestIndex = j;
        }
        temp = arr[lowestIndex];
        arr[lowestIndex] = arr[i];
        arr[i] = temp;
    }
}


int main()
{
    int n = 0, k = 0;

    cin >> n >> k;
    arrSize = n;


    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

   // for (int i = 1; i <= n; i++) {
   //     cout << arr[i] << " ";
   // }
   // cout << endl;


    partialSort(k);

    cout << arr[k] << endl;

    /*for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    cin; cin;
    cout << "Hello world!" << endl;
    */
    return 0;
}