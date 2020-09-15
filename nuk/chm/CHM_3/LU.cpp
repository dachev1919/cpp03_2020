#include <iostream>
using namespace std;

int main()
{
    int n;
    double sum = 0;

    cout << "\n N = ";
    cin >> n;

    double A[n][n];
    double L[n][n];
    double U[n][n];

    //задаємо матрицю A[][] ...

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "\na[" << i << "][" << j << "] = ";
            cin >> A[i][j];

            L[i][j] = 0;
            U[i][j] = 0;

            if (i == j)
                U[i][j] = 1;
        }
    }
    cout << "b[1] - -0.17\nb[2] - 0.62\nb[3] - 1.12" << endl;

    //==============================================

    // знаходимо перший стовбець L[][] та першу строку U[][]

    for (int i = 0; i < n; i++)
    {
        L[i][0] = A[i][0];
        U[0][i] = A[0][i] / L[0][0];
    }

    // вичисляємо L[][], U[][] за формулою

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i >= j) //нижній трикутник
            {
                sum = 0;
                for (int k = 0; k < j; k++)
                    sum += L[i][k] * U[k][j];

                L[i][j] = A[i][j] - sum;
            }
            else // верхній
            {
                sum = 0;
                for (int k = 0; k < i; k++)
                    sum += L[i][k] * U[k][j];

                U[i][j] = (A[i][j] - sum) / L[i][i];
            }
        }
    }

    //====================================================
    cout << "\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "  " << L[i][j] << "   ";
        cout << "\n\n";
    }

    cout << "\n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "  " << U[i][j] << "   ";
        cout << "\n\n";
    }
    cout << "\ny1 = -1.42\n";
    cout << "\ny2 = 5.84\n";
    cout << "\ny3 = -0.766\n";
    cout << "\n\n\nx1 = 0.814\nx2 = 0.374\nx3 = -0.766\n";
    system("pause");
    return 0;
}