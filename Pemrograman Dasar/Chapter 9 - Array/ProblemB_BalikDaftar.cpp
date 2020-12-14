#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> x;
    int input;
    while (true)
    {
        //cin.ignore();
        if (cin.eof())
           break;
        cin >> input;
        if (!cin.eof())
            x.push_back(input);
    }
    //system("clear");
    for (int i = x.size()-1; i >= 0; i--)
        cout << x[i] << "\n";

    return 0;
}