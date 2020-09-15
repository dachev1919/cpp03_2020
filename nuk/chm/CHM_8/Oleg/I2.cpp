#include <iostream>
#include <cmath>
using namespace std;

double F(double x, double y){return cos(1.5 * y + x) * cos(1.5 * y + x) + 1.4;}

int main()
{
    cout << "Metod Jejlera" << endl;
    cout << "Differencial'noe uravnenie: cos(1.5 * y + x) * cos(1.5 * y + x) + 1.4 << endl;
    double a = 1;
    double b = 2;
    double h = 0.1;
    double n = (b - a) / h;
    double X[(int)n];
    double Y[(int)n];
    X[0] = a;
    Y[1] = 0.9;
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