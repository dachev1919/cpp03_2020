#include <iostream>
#include <math.h>
#include <time.h>
#include <stdio.h>
using namespace std;
//Функция, определяющая левую часть уравнения f (x) = 0.
double f(double x)
{
    return (x*x+4*sin(x));
}
//Функция, реализующая метод половинного деления.
int Pol_podil(double a, double b, double *c, double eps)
{
    int k = 0;
    do
    {
        *c = (a + b) / 2;
        if (f(*c) * f(a) < 0)
            b = *c;
        else
            a = *c;
        k++;
    } while (fabs(a - b) >= eps);
    return k;
}
//Функция, реализующая метод хорд.
int Chord(double a, double b, double *c, double eps)
{
    int k = 0;
    do
    {
        *c = a - (f(a) * (b - a)) / (f(b) - f(a));
        if (f(*c) * f(a) > 0)
            a = *c;
        else
            b = *c;
        k++;
    } while (fabs(f(*c)) >= eps);
    return k;
}
double f1(double x) //Первая производная функции f (x).
{
    return (2 * x + 4 * cos(x));
}
double f2(double x) //Вторая производная функции f (x).
{
    return (2 - 4 * sin(x));
}
//Функция, реализующая метод Ньютона.
int Newtone(double a, double b, double *c, double eps)
{
    int k = 0;
    if (f(a) * f2(a) > 0)
        *c = a;
    else
        *c = b;
    do
    {
        *c = *c - f(*c) / f1(*c);
        k++;
    } while (fabs(f(*c)) >= eps);
    return k;
}
double fi(double x, double L) //Функция, заданная выражением 4.4 .
{
    return (x + L * f(x));
}
//Функция, реализующая метод простой итерации.
int Iteration(double *x, double L, double eps)
{
    int k = 0;
    double x0;
    do
    {
        x0 = *x;
        *x = fi(x0, L);
        k++;
    } while (fabs(x0 - *x) >= eps);
    return k;
}
int main()
{
    double A, B, X, P;
    double A1, B1, X1, P1;
    double ep = 0.00001; //Точность вычислений.
    int K;
    cout << "\tVariant zavdannya:\nx * x + 4 * sin(x) = 0. \n" << endl;
    cout << "Zadayte interval izolyacii.\nS = ";
    cin >> A; //Интервал изоляции корня.
    A1 = A;
    cout << "E = ";
    cin >> B;
    B1 = B;
    K = Pol_podil(A1, B1, &X1, ep);
    //Алгоритм метода половиного поділу.
    clock_t start = clock();
    int t = 1;
    cout << endl;
    do
    {
        X = (A + B) / 2;
        if (f(X) * f(A) < 0)
            B = X;
        else
            A = X;
        cout << "[" << t << "]=" << X << endl;
    } while (fabs(A - B) >= ep);
    system("cls");
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Method polovinnogo podilu:" << endl;
    cout << "X = " << X;
    cout << ", iteraciy I = " << K << ", chas = ";
    printf("%f seconds\n", seconds);
    system("Pause");
    K = Chord(A1, B1, &X1, ep);
    // Алгоритм метода хорд
    start = clock();
    do
    {
        X = A - f(A) / (f(B) - f(A)) * (B - A);
        if (f(X) * f(A) > 0)
            A = X;
        else
            B = X;
        cout << "[" << t << "]=" << X << endl;
    } while (fabs(f(X)) >= ep);
    system("cls");
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Method hord:" << endl;
    cout << "X = " << X;
    cout << ", iteraciy I = " << K << ", chas = ";
    printf("%f seconds\n", seconds);
    system("Pause");
    K = Newtone(A1, B1, &X1, ep);
    // Алгоритм метода Ньютона
    start = clock();
    if (f(A) * f2(A) > 0)
        X = A;
    else
        X = B;
    do
    {
        X = X - f(X) / f1(X);
        cout << "[" << t << "]=" << X << endl;
    } while (fabs(f(X)) >= ep);
    system("cls");
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Method Newtone:" << endl;
    cout << "X = " << X;
    cout << ", iteraciy I = " << K << ", chas = ";
    printf("%f seconds\n", seconds);
    system("Pause");
    // Алгоритм метода простої ітерації
    cout << "L = ";
    cin >> P;
    X1 = A1;
    double x0;
    K = Iteration(&X1, P, ep);
    start = clock();
    do
    {
        x0 = X;
        X = fi(x0, P);
        cout << "[" << t << "]=" << X << endl;
    } while (fabs(x0 - X) >= ep);
    system("cls");
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Method prostoi iteracii:" << endl;
    cout << "X = " << X;
    cout << ", iteraciy I = " << K << ", chas = ";
    printf("%f seconds\n", seconds);
    system("pause");
    return 0;
}