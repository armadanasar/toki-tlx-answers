#include <iostream>
#include <stdio.h>
#include <string.h>

char input[512];

using namespace std;

int main()
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int offset = 0;
    int length = 0;
    scanf("%s %d", &input, &offset);
    length = strlen(input);

    for (int i = 0; i < length; i++) {
        putchar(alphabet[((input[i]-97) + offset) % 26]);
    }
    putchar('\n');

    getchar();
    getchar();
    //cout << "Hello world!" << endl;
    return 0;
}