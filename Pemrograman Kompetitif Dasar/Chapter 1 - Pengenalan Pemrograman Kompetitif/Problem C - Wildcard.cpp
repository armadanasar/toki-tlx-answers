#include <bits/stdc++.h>

using namespace std;

string pattern, pattern2, pattern1;
string queries[110];
int N = 0, start = 0, pos = 0;

int findPos() {
	if (pattern[0] == '*')
		return 1;
	else if (pattern[pattern.length() - 1] == '*')
		return 3;
	else
		return 2;
}

void pecah(int start) {
	int len = pattern.length();
	if (start == 1) {
		pattern2 = pattern.substr(1, len-1);
		pos = 0;
	}

	else if (start == 2) {
		int x = 1, y = pattern.length() - 2;

		while (pattern[x] != '*' && pattern[y] != '*') {
			x++;
			y--;
		}

		if (pattern[x] == '*') {
			pos = x;
		}

		else if (pattern[y] == '*') {
			pos = y;
		}

		pattern1 = pattern.substr(0, pos);
		pattern2 = pattern.substr(pos+1, pattern.length()-pos-1);
	}
	else {
		pattern1 = pattern.substr(0, pattern.length()-1);
		pos = pattern.length()-1;
	}
}



bool isValid(int w) {
	int x, y, len2;
	string curr = queries[w];
	int len = curr.length();

	bool kena = false;


	if (start == 1) {
		len2 = pattern2.length();
		if (len >= len2) {
			x = len-len2;
			string ss= curr.substr(x, len2);

			if (pattern2 == ss)
				kena = true;
		}
	}

	else if (start == 2) {
		int len1 = pattern1.length();
		int len2 = pattern2.length();
		string ss;
		string ss2;
		if (len >= len1 && len >= len2) {
			 ss = curr.substr(0, len1);
			 ss2 = curr.substr(len-len2, len2);
		}

		if (ss == pattern1 && ss2 == pattern2 && (len1-1 < len-len2))
			kena = true;

	}

	else if (start == 3) { 
		int len2 = pattern1.length();
		string ss;
		if (len >= len2) {
			ss = curr.substr(0, len2);
			if (pattern1 == ss)
				kena = true;
		}
	}


	return kena;
}


int main() {
	cin >> pattern;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> queries[i];
	}

	if (pattern == "*") {
		for (int i = 0; i < N; i++) {
			cout << queries[i] << endl;
		}
	} 

	else {
		start = findPos();
		pecah(start);

		for (int i = 0; i < N; i++) {
			if (isValid(i))
				cout << queries[i] << endl;
		}
	}

	return 0;
}


