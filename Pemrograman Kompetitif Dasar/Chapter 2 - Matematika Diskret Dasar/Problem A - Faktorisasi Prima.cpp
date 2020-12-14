#include <bits/stdc++.h>

using namespace std;

//k ^ n
typedef struct Factor {
	int k;
	int pangkat;
};

std::list<Factor> listFactor;

bool isPrime(int n) {
	if (n == 2) return true;
	for (int i = 2; i <= sqrt(i); i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}

void factorize(int n) {
if (n == 1) {
cout << "1" << endl;
    return;
}
    int n1 = n;
	for (int i = 2; i <= n1; i++) {
		if (isPrime(i) && (n % i == 0)) {
			Factor f;
			f.k = i;
			f.pangkat = 0;
			while (n % i == 0) {
				f.pangkat++;
				n/=i;
			}
			//cout << "f: " << f.k << " " << f.pangkat << endl;
			listFactor.push_back(f);
		}
	}
}

int main() {
    int k = 0;
	cin >> k;
	factorize(k);
	std::list<Factor>::iterator it;

	for (it = listFactor.begin(); it != listFactor.end(); ++it) {
		if (it->pangkat == 1)
            cout << it->k;
		else if (it->pangkat > 1)
            cout << it->k << "^" << it->pangkat;
        if (it != --listFactor.end())
            cout << " x ";
	}

	cout << endl;


return 0;
}

