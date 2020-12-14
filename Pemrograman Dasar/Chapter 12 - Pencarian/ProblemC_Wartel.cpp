#include <iostream>
#include <bits/stdc++.h>

typedef struct Contact {
    char name[20];
    char phonenumber[20];
};

Contact contacts[101000];
int contactsCount = 0;
int queriesCount = 0;
char *binarySearchHelper(char *contactName, int left, int right);
using namespace std;

char* findContact(char *contactName) {
    return binarySearchHelper(contactName, 0, contactsCount-1);
}

char *binarySearchHelper(char *contactName, int left, int right) {
    int mid = (left + right)/2;
    //printf("I am called, I am at index %d! On Contact: %s\n", mid, contacts[mid].name);
    if (right >= left) {
    int strCheck = strcmp(contacts[mid].name, contactName);
    if (strCheck == 0) {
        //printf("found!");
        return contacts[mid].phonenumber;
    }
    if (strcmp(contacts[mid].name, contactName) > 0)
        return binarySearchHelper(contactName, left, mid-1);

    else if (strcmp(contacts[mid].name, contactName) < 0)
        return binarySearchHelper(contactName, mid+1, right);
    }

    return "";
}

int main()
{
    scanf("%d %d", &contactsCount, &queriesCount);

    int i = 0;
    char query[20];
    while (i < contactsCount) {
        scanf("%s %s", &contacts[i].name, &contacts[i].phonenumber);
        char x[100];
        char y[100];
        strcpy(x, contacts[contactsCount].name);
        strcpy(y, contacts[contactsCount].phonenumber);

        //contactsCount++;
        i++;

    }

    i = 0;
    while (i < queriesCount) {
        scanf("%s", query);
        char *result = binarySearchHelper(query, 0, contactsCount-1);
        if (strcmp("", result) == 0) {
            printf("NIHIL\n");
        }

        else {
            printf("%s\n", result);
        }

        i++;
    }

    //cout << "Hello world!" << endl;
    return 0;
}