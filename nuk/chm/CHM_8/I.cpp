#include <iostream>
#include <cmath>
using namespace std;

double F(double x, double y)
{
    return 2 * x - 3 * y;
}

int main()
{
    cout << "Metod Runge - Kutty" << endl;
    cout << "Diferencial'ne rivnjannja: 2 - (sin(x + y) * sin(x+y))" << endl;
    double a = 1;
    double b = 3;
    double h = 0.2;
    double n = (b - a) / h;
    double X[(int)n];
    double Y1[(int)n];
    double Y2[(int)n];
    double Y3[(int)n];
    double Y4[(int)n];
    double Y[(int)n];
    //calculate
    X[0] = 1;
    Y[0] = 2;
    for (int i = 1; i <= n; i++)
    {
        X[i] = a + i * h;
        Y1[i] = h * F(X[i - 1], Y[i - 1]);
        Y2[i] = h * F(X[i - 1] + h / 2.0, Y[i - 1] + Y1[i] / 2.0);
        Y3[i] = h * F(X[i - 1] + h / 2, Y[i - 1] + Y2[i] / 2);
        Y4[i] = h * F(X[i - 1] + h, Y[i - 1] + Y3[i]);
        Y[i] = Y[i - 1] + (Y1[i] + 2 * Y2[i] + 2 * Y3[i] + Y4[i]) / 6;
        cout << "x = " << X[i] << "| k1 - " << Y1[i] << "| k2 - " << Y2[i] << "| k3 - " << Y3[i] << "| k4 - " << Y4[i] << "| delY" << Y[i];
        cout << "\n---------------------------------------------------\n";
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