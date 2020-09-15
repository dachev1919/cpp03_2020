#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <math.h>

using namespace std;
double **resultatLR(double **a, double **b, int row1, int col1, int col2);
double **transponuvannya(double **a, int n, int m);

int main(){
    int row, row2, col, col2;
    double **arr, **arr2;

    cout << "Matrica 1\nRow - ";
    cin >> row;
    cout << "Col - ";
    cin >> col;
    row2 = col;
    cout << "Matrica 2\nRow = " << row2 << endl;
    cout << "Col -";
    cin >> col2;

    arr = new double *[row];
    arr2 = new double *[row2];
    cout << "\nMatrica 1\n";
    for (int i = 0; i < row; i++){
        arr[i] = new double[col];
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 10;
            cout << arr[i][j] << "    ";
        }
        cout << endl;
    }

    cout << "\nMatrica 2\n";
    for (int i = 0; i < row2; i++){
        arr2[i] = new double[col2];
        for (int j = 0; j < col2; j++)
        {
            arr2[i][j] = rand() % 10;
            cout << arr2[i][j] << "    ";
        }
        cout << endl;
    }

    cout << "\nTransponovana matrica 1\n";

    double **transArr, **transArr2;
    transArr = transponuvannya(arr, row, col);
    /*transArr2 = transponuvannya(arr2, row2, col2);*/
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << transArr[i][j] << "    ";
        cout << endl;
    }
    /*cout << "\nTransponovana matrica 2\n";
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
            cout << transArr2[i][j] << "    ";
        cout << endl;
    }*/
    cout << "\nResultat:\n";
    double **resultLR;
    resultLR = resultatLR(transArr, arr2, row, col, col2);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << resultLR[i][j] << "    ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}

double **resultatLR(double **a, double **b, int row, int col, int col2)
{
    double **mass;
    mass = new double *[row];
    for (int i = 0; i < row; i++)
    {
        mass[i] = new double[col2];
        for (int j = 0; j < col2; j++)
        {
            mass[i][j] = 0;
            for (int k = 0; k < col; k++)
                mass[i][j] += a[i][k] * b[k][j];
        }
    }
    return mass;
}

double **transponuvannya(double **a, int n, int m)
{
    int i, j;
    double **mass;
    mass = new double *[n];
    for (i = 0; i < n; i++)
        mass[i] = new double[m];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            mass[j][i] = a[i][j];
    return mass;
}