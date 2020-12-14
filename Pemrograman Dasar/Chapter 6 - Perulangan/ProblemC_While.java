#include <iostream>

using namespace std;

int main()
{
    string input = "";
    while(true)
    {

        cin >> input;
        cin.ignore();
        if (cin.eof())
            break;
        if (input[0] == '^' && input[1] == 'Z')
            break;
        cout << input << endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}