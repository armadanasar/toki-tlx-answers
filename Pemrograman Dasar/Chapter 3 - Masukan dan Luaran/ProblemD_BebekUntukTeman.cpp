#include <iostream>

using namespace std;

int main()
{
    int jumBebek, jumTeman, jumBebekMasingMasing, modulo;
    cin >> jumBebek >> jumTeman;

    jumBebekMasingMasing = jumBebek/jumTeman;
    modulo = jumBebek%jumTeman;

    cout << "masing-masing " << jumBebekMasingMasing << endl;
    cout << "bersisa " << modulo << endl;
}