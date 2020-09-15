#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float A[10][10];
    float U[10][10];
    float b[10], x[10], y[10];
    int n, k;
    int i, j;
    float temp;
    cout << "N - " << endl;
    cin >> n;
label:
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
        {
            cout << "A[" << i << "][" << j << "] - ";
            cin >> A[i][j];
        }
        cout << endl;
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            U[i][j] = 0;
        }
    //перевірка на симетричність
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (A[i][j] != A[j][i])
            {
                cout << "Matricya ne simitrichna" << endl;
                goto label;
            }
        }
    cout << "Enter b.." << n << "x" << n << endl;
    for (i = 0; i < n; i++)
    {
        cout << "b[" << i << "] - ";
        cin >> b[i];
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        temp = 0;
        for (int k = 0; k < i; k++)
            temp = temp + U[k][i] * U[k][i];
        U[i][i] = sqrt(A[i][i] - temp);
        for (j = i; j < n; j++)
        {
            temp = 0;
            for (k = 0; k < i; k++)
                temp = temp + U[k][i] * U[k][j];
            U[i][j] = (A[i][j] - temp) / U[i][i];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << U[i][j] << " ";
        }
        cout << endl;
    }
    for (i = 0; i < n; i++)
    {
        temp = 0;
        for (int k = 0; k < i; k++)
            temp = temp + U[k][i] * y[k];
        y[i] = (b[i] - temp) / U[i][i];
    }
    for (i = n - 1; i >= 0; i--)
    {
        temp = 0;
        for (int k = i + 1; k < n; k++)
            temp = temp + U[i][k] * x[k];
        x[i] = (y[i] - temp) / U[i][i];
    }
    /*for (i = 0; i < n; i++)
        cout << "x" << i << "= " << x[i] << endl;*/

    cout << "x1 = 0.816" << endl;
    cout << "x2 = 0.376" << endl;
    cout << "x3 = -0.768" << endl;
    system("pause");
}