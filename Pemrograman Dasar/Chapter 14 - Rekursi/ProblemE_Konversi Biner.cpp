#include <iostream>
#include <bits/stdc++.h>

using namespace std;
stack<bool> result;

void convertToBinary(int n) {
    if (n <= 0)
        return;
    if (n % 2)
        result.push(true);
    else
        result.push(false);
    convertToBinary(n/2);
}

int main()
{
    int n = 0;
    cin >> n;

    convertToBinary(n);

    while (!result.empty()) {
        bool b = result.top();
        result.pop();
        if (b)
            cout << "1";
        else
            cout << "0";
    }

    cout << endl;
    //cout << "Hello world!" << endl;
    return 0;
}