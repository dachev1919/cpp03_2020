#include <iostream>
#include <cmath>
using namespace std;

double F(double x, double y)
{
    return 2 * x - 3 * y;
}

int main()
{
    cout << "Metod Jejlera" << endl;
    cout << "Diferencial'ne rivnjannja: 2 - (sin(x + y) * sin(x+y))" << endl;
    double a = 1;
    double b = 3;
    double h = 0.2;
    double n = (b - a) / h;
    double X[(int)n];
    double Y[(int)n];
    X[0] = 1;
    Y[0] = 2;
    for (int i = 1; i <= n; i++)
    {
        X[i] = a + i * h;
        Y[i] = Y[i - 1] + h * F(X[i - 1], Y[i - 1]);
    }
    //print results
    for (int i = 1; i <= n; i++)
    {
        cout << "X[" << i << "] = " << X[i] << " ";
        cout << "\tY[" << i << "]=" << Y[i] << " " << endl;
    }
    system("pause");
    return 0;
}