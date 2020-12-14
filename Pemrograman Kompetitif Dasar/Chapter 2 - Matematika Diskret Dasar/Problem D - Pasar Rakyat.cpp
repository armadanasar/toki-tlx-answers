#include <bits/stdc++.h>

using namespace std;
vector<long long> intervalsPedagang;

long long gcd(long long a, long long b) {
	long long dividend = (a > b) ? a : b;
	long long divisor = (a < b) ? a : b;

	if (divisor == 0)
		return dividend;
	return gcd(dividend%divisor, divisor);
}

long long kpk(long long a, long long b) {
	return ((a * b)/gcd(a, b));
}

long long calculatePasarRakyat(vector<long long> intervals) {
	int a = 0, b = 0, c = 0;
	for (int i = 1; i < intervals.size(); i++) {
		//a = c;
        if (i == 1) {
            c = kpk(intervals[i-1], intervals[i]);
        }
		c = kpk(c, kpk(intervals[i-1], intervals[i]));
	}

	return c;
}

int main() {
    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        long long x = 0;
        cin >> x;
        intervalsPedagang.push_back(x);
    }

    cout << calculatePasarRakyat(intervalsPedagang) << endl;;
	return 0;
}
