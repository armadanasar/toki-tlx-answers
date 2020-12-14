#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
typedef struct resultNode
{
    int base;
    int exponent;
    resultNode* next;
    resultNode* previous;
};

resultNode* head = nullptr;
resultNode* tail = nullptr;

void insertTail(int base, int exponent)
{
    resultNode* newData = new resultNode();
    newData->base = base;
    newData->exponent = exponent;
    if (head == nullptr)
        head = newData;
    else
    {
        newData->previous = tail;
        tail->next = newData;
    }
    newData->next = nullptr;
    tail = newData;
}
//fix memory leak
void cleanup()
{
    resultNode* deleteHead = nullptr;
    while (head != nullptr)
    {
        deleteHead = head;
        head = head->next;
        delete deleteHead;
    }
    tail = nullptr;
    head = nullptr;
}
void displayList()
{
    resultNode* copy = head;
    while (copy != nullptr)
    {
        switch(copy->exponent)
        {
        case 1:
        case 0:
            cout << copy->base;
            break;
        default:
            cout << copy->base << "^" << copy->exponent;
            break;
        }

        switch((unsigned long)copy->next)
        {
        case 0:
            cout << endl;
            break;
        default:
            cout << " x ";
            break;
        }
        copy = copy->next;
    }
}
void generatePrimeFactor(int n)
{
    int i = 0, exponent = 0;
    if (n == 1)
        insertTail(1,0);
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            exponent = 0;
            while (n%i == 0)
            {
                n/=i;
                exponent++;
            }
            if (exponent > 1)
                insertTail(i, exponent);

            else if (exponent == 1)
                insertTail(i, exponent);

        }
    }

    if (n != 1)
        insertTail(n, 1);
}

int main()
{
    int input;
    scanf("%d", &input);
    fflush(stdin);
    generatePrimeFactor(input);
    displayList();
    cleanup();
    return 0;
}