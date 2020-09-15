#include <iostream>
#include <math.h>
using namespace std;
double f(double x) { return cos(x * x) / (x + 1); }
double I(double a, double b, int n, double y) { return ((b - a) / (2 * n) * y); }
int main()
{
    int n;
    double a, b, y, dy, In;
    cout << "A:";
    cin >> a;
    cout << "B:";
    cin >> b;
    cout << "n:";
    cin >> n;
    if (n > 1)
    {
        dy = (b - a) / n;
        y += f(a) + f(b);
        for (int i = 1; i < n; i++)
        {
            y += 2 * (f(a + dy * i));
        }
        In = I(a, b, n, y);
        printf("cos(x * x) / (x + 1) = %.3f\n", In);
    }
    else
    {
        cout << "Wrong data";
    }
    cout << "Iteraciy(i) - 12\n";
    system("pause");
}