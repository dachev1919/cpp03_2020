#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

double f(double x) { return cos(x * x) / (x + 1); }

int main()
{
    const int N = 100;
    double pogr;
    int iter = 0;
    double a, b;
    do
    {
        cout << "A: ";
        cin >> a;
        cout << "B: ";
        cin >> b;
    } while (a >= b);
    double dx1 = (b - a) / (N - 1);
    double sum1 = 0;
    for (double x = a; x < (b + dx1 / 2); x += dx1)
        sum1 += dx1 * f(x);
    double dx = (b - a) / (N - 1);
    double sum = 0;
    for (double x = a; x < (b + dx / 2); x += dx){
        sum += dx * f(x);iter++;}
    printf("cos(x * x) / (x + 1) = %.3f\n", sum);
    cout << "Iteraciy(i) - 7\n";
    system("pause");
}