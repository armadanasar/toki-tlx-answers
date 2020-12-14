#include <bits/stdc++.h>

using namespace std;
typedef struct Fraction {
	long long top;
	long long bottom;
};


Fraction a, b, c;

Fraction addFractions(Fraction a, Fraction b) {
	Fraction c;
	c.top = (a.top * b.bottom) + (a.bottom * b.top);
	c.bottom = (a.bottom * b.bottom);


	if (c.top == c.bottom) {
		c.top = c.bottom = 1;
	}

	return c;
}

long long gcd(long long a, long long b) {
	long long dividend = (a > b) ? a : b;
	long long divisor = (a < b) ? a : b;

	if (divisor == 0)
		return dividend;
	return gcd(dividend%divisor, divisor);
}


int main() {
	//  4/9
	cin >> a.top >> a.bottom;
	//  3/6
	cin >> b.top >> b.bottom;
	// 51/54

	c = addFractions(a, b);

	//cout << c.top << " " << c.bottom << endl;
	long long commonFactor = gcd(c.top, c.bottom);
	c.top/=commonFactor;
	c.bottom/=commonFactor;
	if (c.top == c.bottom)
        cout << "1" << endl;
    else
        cout << c.top << " " << c.bottom << endl;
	return 0;
}

