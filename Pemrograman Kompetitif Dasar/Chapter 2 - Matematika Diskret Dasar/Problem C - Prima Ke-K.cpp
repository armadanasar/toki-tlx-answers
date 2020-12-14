#include <bits/stdc++.h>


using namespace std;

int primes[100000];
bool sieve[1100000];
int counter = 1;

bool isPrime(int k) {
	if (k == 2)
		return true;
	else {
		for (int i = 2; i <= sqrt(k); i++) {
			if (k % i == 0)
				return false;
		}
		return true;
	}
	return false;
}

int generatePrime(int nth) {
	return primes[nth];
}

//preload prime table rather than generating it on demand.
void sieveOfEras() {
	for (int i = 2; i <= sqrt(1100000); i++)
		if (sieve[i])
			for (int j = i * 2; j <= 1100000; j+=i)
                sieve[j] = false;

	for (int i = 2; i <= 1100000; i++)
        if (sieve[i])
            primes[counter++] = i;
}

int newGenprime(int k) {
	return primes[k];
}

int main() {
    for (int i = 0; i < 1100000; i++) {
		sieve[i] = true;
	}

	sieveOfEras();

	//for (int i = 1; i <= counter; i++) {
      //  cout << primes[i] << endl;
	//}
	int n = 0, k = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        printf("%d\n", newGenprime(k));
	}

    return 0;
}