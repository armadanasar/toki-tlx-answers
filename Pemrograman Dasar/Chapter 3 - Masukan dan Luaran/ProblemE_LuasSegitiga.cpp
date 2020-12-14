#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int alas, tinggi;
    float luas;
    cin >> alas >> tinggi;
    luas = (((float)alas * (float)tinggi)/2);
    printf("%.2f\n", luas);
}