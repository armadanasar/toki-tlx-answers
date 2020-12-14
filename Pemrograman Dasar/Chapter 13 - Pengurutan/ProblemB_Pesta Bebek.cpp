#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> strarr;


int main()
{
    int tc = 0;
    int i = 0;
    char in[512];
    int datacount = 0;
    int j = 0;
    cin >> tc;
    cin;
    while (tc--) {
        j = 0;
        string instr = "";
        cin >> instr;
        strarr.push_back(instr);
        sort(strarr.begin(), strarr.end());
        datacount++;

        for (int i = 0; i < datacount; i++) {
            if (strcmp(instr.c_str(), strarr[i].c_str()) == 0) {
                cout << (i+1) << endl;
                break;
            }
        }
        //j = datacount;
        /*while (j > 0 && strcmp(instr.c_str(), strarr[j].c_str()) > 0) {
            strarr[j+1] = strarr[j];
            j--;
        }*/

        //for (int i = 0; i < datacount; i++) {
        //    cout << strarr[i] << endl;
        //}
        //strarr[j] = instr;
        //datacount++;
        //cout <<(j+1) << endl;
        //cout << instr << endl;

    }
    //cout << "Hello world!" << endl;
    return 0;
}