#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
typedef double (*pointFunc)(double);
double f(double x)
{
    return cos(x + 0.1) / (x * x + 1);
}
double rectangle_integral(pointFunc f, double a, double b, int n)
{
    double x, h;
    double sum = 0.0;
    double fx;
    h = (b - a) / n; //шаг

    for (int i = 0; i < n; i++)
    {
        x = a + i * h;
        fx = f(x);
        sum += fx;
    }
    return (sum * h); //приближенное значение интеграла равно
                      //сумме площадей прямоугольников
}
int main()
{
    double a, b, eps;
    double s1, s;
    int n = 1, iter = 1; //начальное число шагов
    cout << "A = ";
    cin >> a;
    cout << "\nB = ";
    cin >> b;
    cout << "\nEps = ";
    cin >> eps;
    s1 = rectangle_integral(f, a, b, n); //первое приближение для интеграла
    do
    {
        s = s1;    //второе приближение
        n = 2 * n; //увеличение числа шагов в два раза,
                   //т.е. уменьшение значения шага в два раза
        s1 = rectangle_integral(f, a, b, n);
        iter++;
    } while (fabs(s1 - s) > eps); //сравнение приближений с заданной точностью
    printf("cos(x * x) / (x + 1) = %.3f\n", s1);
    cout << "Iteraciy(i) - 6\n";
    system("pause");
}