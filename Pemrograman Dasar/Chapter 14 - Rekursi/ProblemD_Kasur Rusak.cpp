#include <bits/stdc++.h>

using namespace std;

bool helperOdd(char *s, int length, int idx) {
	if (s[idx] != s[length-1-idx])
		return false;
	if (idx == (length-1-idx))
		return true;

	return helperOdd(s, length, (idx+1));
}
int midIdxStop = 0;
bool helperEven(char *s, int length, int idx) {
	if (s[idx] != s[length-1-idx])
		return false;
	if (idx == (length-1-idx+1))
		return true;

	return helperEven(s, length, (idx+1));
}

bool checkPalindrome(char *s, int length) {
	if (length % 2)
		return helperOdd(s, length, 0);
	else
		return helperEven(s, length, 0);
}

int main() {
	char tes[1024];
	scanf("%s", &tes);

	bool result = checkPalindrome(tes, strlen(tes));
	if (result)
        cout << "YA" << endl;
    else
        cout << "BUKAN" << endl;

    //getchar(); getchar();

    return 0;
}