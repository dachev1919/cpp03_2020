#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

double lagr(double x, int n, double Arr_x[], double Arr_y[])
{
    if (n > 5)
        return (x <= Arr_x[n / 2]) ? lagr(x, (n + 1) / 2, Arr_x, Arr_y) : lagr(x, (n + 1) / 2, &Arr_x[n / 2], &Arr_y[n / 2]);

    double s = 0;
    for (int i = 0; i < n; ++i)
    {
        double q = 1;
        for (int j = 0; j < n; ++j)
            if (j != i)
                q *= (x - Arr_x[j]) / (Arr_x[i] - Arr_x[j]);
        s += Arr_y[i] * q;
    }
    return s;
}
double f(double x) { return (sin(x + 2) * sin(x + 2)); }
int main()
{
    double b = 5, h = 0.1;
    int n = b / h;
    double x_arr[n];
    double y_arr[n];
    int i = 0;
    cout << "F = sin(x + 2) * sin(x + 2)\nh = 0.1\nb = 5\n\n";
    cout << "____________________________________________________________________________________\n";
    cout << "|N|   X\t\t|\t    Y[X]\t|\t    L[X]\t|\t    Pohibka |\n";
    cout << "____________________________________________________________________________________\n";
    for (double x = 0; x <= b+h; x += h)
    {
        x_arr[i] = x;
        y_arr[i] = f(x);
        cout << "|" << i << "| X[" << x << "]\t|\t";
        printf("%.10f", f(x));
        cout << "      - \t";
        printf("%.10f", lagr(x, i, x_arr, y_arr));
        cout << "      = \t";
        double z = abs(f(x)-lagr(x, i, x_arr, y_arr));
        printf("%.10f|\n", z);
        i++;
    }
    cout << "_____________________________________________________________________________________\n";
    getchar();
    return 0;
}

