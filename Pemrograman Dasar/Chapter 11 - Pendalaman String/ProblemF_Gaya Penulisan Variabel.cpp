#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string x = "";
    cin >> x;
    const char *xcp = x.c_str();
    int xcp_len = strlen(xcp);
    for (int i = 0; i < xcp_len; i++) {
        if (isupper(xcp[i])) {
            putchar('_');
            putchar(xcp[i]+32);
        }

        else if (xcp[i] == '_') {
            if (islower(xcp[i+1])) {
                putchar(xcp[i+1]-32);
            }

            else {
                putchar(xcp[i+1]);
            }

            i+=1;
        }

        else {
            putchar(xcp[i]);
        }
    }

    putchar('\n');
    getchar();
    //cout << "Hello world!" << endl;
    return 0;
}
