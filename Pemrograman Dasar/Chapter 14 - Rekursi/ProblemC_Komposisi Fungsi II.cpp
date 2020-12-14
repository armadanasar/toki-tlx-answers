#include <iostream>

using namespace std;

int a = 0, b = 0, k = 0, x = 0, fx = 0;
int counter = 0;

int abs(int n) {
    if (n < 0)
        return (n * (-1));
    else
        return n;
}

//rumus: abs(ax+b)
void doCalc(int *x) {
    if (counter >= 1 && counter <= k) {
        fx = abs((a * *x) + b);
        counter++;
        doCalc(&fx);
    }
}

int main()
{
    cin >> a >> b >> k >> x;
    counter = 1;
    doCalc(&x);


    cout << fx << endl;

    //cout << "Hello world!" << endl;
    return 0;
}