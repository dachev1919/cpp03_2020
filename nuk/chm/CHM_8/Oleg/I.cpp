#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

double Function(double x, double y){return x*x-y;}

int main()
{
    SetConsoleCP(866);
    SetConsoleOutputCP(866);
    cout << "Metod Runge-Kutty" << endl;
    cout << "Differencial'noe uravnenie: cos(1.5 * y + x) * cos(1.5 * y + x) + 1.4" << endl;
    double a = 1;
    double b = 3;
    double h = 0.5;
    double n = (b - a) / h;
    double X[(int)n];
    double K1[(int)n];
    double K2[(int)n];
    double K3[(int)n];
    double K4[(int)n];
    double Y[(int)n];
    X[0] = 2;
    Y[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        X[i] = a + i * h;
        K1[i] = h * Function(X[i - 1], Y[i - 1]);
        K2[i] = h * Function(X[i - 1] + h / 2.0, Y[i - 1] + K1[i] / 2.0);
        K3[i] = h * Function(X[i - 1] + h / 2, Y[i - 1] + K2[i] / 2);
        K4[i] = h * Function(X[i - 1] + h, Y[i - 1] + K3[i]);
        Y[i] = Y[i - 1] + (K1[i] + 2 * K2[i] + 2 * K3[i] + K4[i]) / 6;
        cout << "x = " << X[i] << "| k1 - " << K1[i] << "| k2 - " << K2[i] << "| k3 - " << K3[i] << "| k4 - " << K4[i] << "| delY" << Y[i];
        cout << "\n---------------------------------------------------\n";
    }
    for (int i = 1; i <= n; i++)
        cout << "X[" << i << "] = " << X[i] << " "
             << "\tY[" << i << "]=" << Y[i] << " " << endl;
    system("pause");
    return 0;
}