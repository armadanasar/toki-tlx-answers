#include <bits/stdc++.h>
using namespace std;

typedef struct Student {
	string id;
	int s1_score;
	int s2_score;
	int s3_score;
};

int N = 0, M = 0, T = 0;
vector<Student> studentArr(100);
string query;

void swapEntry(Student *a, Student *b) {
	Student temp = *a;
	*a = *b;
	*b = temp;
}

void sortStudents() {
	for (int i = 0; i < N; i++) {
		int smallestIdx = i;

		for (int j = i+1; j < N; j++) {
			if (studentArr[j].s3_score < studentArr[smallestIdx].s3_score) {
				smallestIdx = j;
			}

			if ((studentArr[j].s3_score == studentArr[smallestIdx].s3_score) && (studentArr[j].s2_score < studentArr[smallestIdx].s2_score)) {
				smallestIdx = j;
			}

			if ((studentArr[j].s3_score == studentArr[smallestIdx].s3_score) && (studentArr[j].s2_score == studentArr[smallestIdx].s2_score) && (studentArr[j].s1_score < studentArr[smallestIdx].s1_score)) {
				smallestIdx = j;
			}
		}

		if (smallestIdx != i) {
			swapEntry(&studentArr[i], &studentArr[smallestIdx]);
		}
	}	
}

void test()
 {
 	N = 3;
	studentArr[0].s1_score = 10;
	studentArr[0].s2_score = 100;
	studentArr[0].s3_score = 100;


	studentArr[1].s1_score = 0;
	studentArr[1].s2_score = 0;
	studentArr[1].s3_score = 200;


	studentArr[2].s1_score = 1;
	studentArr[2].s2_score = 100;
	studentArr[2].s3_score = 100;


	for (int i = 0; i < N; i++) {
		cout << studentArr[i].s1_score << " " << studentArr[i].s2_score << " " << studentArr[i].s3_score << endl;
	}
cout << endl;
	sortStudents();
	std::reverse(std::begin(studentArr), std::begin(studentArr) + N);
for (int i = 0; i < N; i++) {
		cout << studentArr[i].s1_score << " " << studentArr[i].s2_score << " " << studentArr[i].s3_score << endl;
	}

/*	studentArr[0].s1_score = 10;
	studentArr[0].s2_score = 100;
	studentArr[0].s3_score = 100;


	studentArr[1].s1_score = 0;
	studentArr[1].s2_score = 0;
	studentArr[1].s3_score = 200;


	studentArr[2].s1_score = 1;
	studentArr[2].s2_score = 100;
	studentArr[2].s3_score = 100;


	for (int i = 0; i < N; i++) {
		cout << studentArr[i].s1_score << " " << studentArr[i].s2_score << " " << studentArr[i].s3_score << endl;
	}
cout << endl;
	sortStudents();
for (int i = 0; i < N; i++) {
		cout << studentArr[i].s1_score << " " << studentArr[i].s2_score << " " << studentArr[i].s3_score << endl;
	}
*/
 }
int main() {

	cin >> T;


	while (T--) {
		bool found = false;
		cin >> N >> M;
		cin >> query;
		
		for (int j = 0; j < N; j++) {
			cin >> studentArr[j].id >> studentArr[j].s1_score >> studentArr[j].s2_score >> studentArr[j].s3_score;			
		}

		sortStudents();

		std::reverse(std::begin(studentArr), std::begin(studentArr) + N);

		for (int j = 0; j < M; j++) {
			if (strcmp(studentArr[j].id.c_str(), query.c_str()) == 0) {
				found = true;
			}
		}

		cout << ((found) ? "YA\n" : "TIDAK\n");
	}

	return 0;
}

