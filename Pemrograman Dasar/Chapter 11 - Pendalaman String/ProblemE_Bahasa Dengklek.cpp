#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char input[512];

int main()
{
    scanf("%s", &input);

    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (islower(input[i]))
            input[i]-=32;
        else
            input[i]+=32;
    }

    printf("%s\n", input);
    return 0;
}