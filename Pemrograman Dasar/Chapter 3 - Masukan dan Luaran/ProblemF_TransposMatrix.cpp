#include <iostream>

using namespace std;

int main()
{
    int matrix[3][3];
    int result[3][3];

    for (int i = 0; i < 3; i++)
    {
        cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];
        cin.ignore();
    }

    for (int i = 0; i < 3; i++)
    {
        result[0][i] = matrix[i][0];
        result[1][i] = matrix[i][1];
        result[2][i] = matrix[i][2];
    }

    for (int i = 0; i < 3; i++)
    {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;;
        //cin.ignore();
    }
}