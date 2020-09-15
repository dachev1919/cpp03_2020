#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **getDataLinear(int n)
{
    double **arr = (double **)malloc(2 * sizeof(double *));
    arr[0] = (double *)malloc(n * sizeof(double));
    arr[1] = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        float x, y;
        printf("x[%i] :  ", i + 1);
        scanf("%f", &x);
        printf("y[%i] :  ", i + 1);
        scanf("%f", &y);
        arr[0][i] = (double)x;
        arr[1][i] = (double)y;
    }
    return arr;
}

double **getDataLogarithmic(int n)
{
    double **arr = (double **)malloc(2 * sizeof(double *));
    arr[0] = (double *)malloc(n * sizeof(double));
    arr[1] = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        float x, y;
        printf("x[%i] :  ", i + 1);
        scanf("%f", &x);
        printf("y[%i] :  ", i + 1);
        scanf("%f", &y);
        arr[0][i] = log((double)x);
        arr[1][i] = (double)y;
    }
    return arr;
}

double **linear(int n, double **x, double a, double b)
{
    double **arr = (double **)malloc(2 * sizeof(double *));
    arr[0] = (double *)malloc(n * sizeof(double));
    arr[1] = (double *)malloc(n * sizeof(double));
    printf("Linear result:\n");
    for (int i = 0; i < n; i++)
    {
        float t1, t2;
        arr[0][i] = x[0][i];
        arr[1][i] = b + a * arr[0][i];
    }
    double delt, sumDelt = 0;
    printf("      x\t      y\t      delta\n");
    for (int i = 0; i < n; i++){
        delt = x[1][i] - arr[1][i];
        sumDelt += pow(fabs(delt), 2);
        printf("%i]  [%lf | %lf | %lf]\n", i + 1, x[0][i], arr[1][i], pow(delt, 2));
    }
    printf("\n\nSumDeltKvad = %.6lf\n\n", sumDelt);
    return arr;
}

// Логарифмическая
double **logarithmic(int n, double **x, double a, double b)
{
    double **arr = (double **)malloc(2 * sizeof(double *));
    arr[0] = (double *)malloc(n * sizeof(double));
    arr[1] = (double *)malloc(n * sizeof(double));
    printf("Logarithmic result:\n");
    for (int i = 0; i < n; i++)
    {
        arr[0][i] = x[0][i];
        arr[1][i] = b + a * arr[0][i];
    }
    double delt, sumDelt = 0;
    printf("      x\t      y\t      delta\n");
    for (int i = 0; i < n; i++)
    {
        delt = arr[1][i] - x[1][i];
        sumDelt += pow(fabs(delt), 2);
        printf("%i]  [%lf | %lf | %lf]\n", i + 1, x[0][i], arr[1][i], pow(delt, 2));
    }
    printf("SumDeltKvad = %.6lf\n\n", sumDelt);
    return arr;
}
// Метод наименьших квадратов для линейной аппроксимации
void approx(double **x, double *a, double *b, int n)
{
    double sumX = 0;
    double sumY = 0;
    double sumX2 = 0;
    double sumXY = 0;
    for (int i = 0; i < n; i++)
    {
        sumX += x[0][i];
        sumY += x[1][i];
        sumX2 += x[0][i] * x[0][i];
        sumXY += x[0][i] * x[1][i];
    }
    *a = (n * sumXY - (sumX * sumY)) / (n * sumX2 - sumX * sumX);
    *b = (sumY - *a * sumX) / n;
    return;
}
// Метод наименьших квадратов для квадратичной аппроксимации
void QadratAproks(double **x, int NN, double *_A, double *_B, double *_C)
{
    double a, a1, b, b1, c, c1, d, A, B, C, D, E;
    int n = 0;
    double z = 0;
    double f = 0;
    double q = 0;
    double o = 0;
    double t = 0;
    double w = 0;
    double e = 0;
    double delta, sumDelt = 0;
    printf("Quadratic result:\n");
    printf("      X\t      Y\t      del`taKvadrat\n");
    for (int i = 0; i < NN; i++)
    {
        n++;
        z += x[0][i]; //обозначения сумм
        f += x[0][i] * x[0][i];
        q += x[0][i] * x[0][i] * x[0][i];
        o += x[0][i] * x[0][i] * x[0][i] * x[0][i];
        t += x[1][i];
        w += x[1][i] * x[0][i];
        e += x[1][i] * x[0][i] * x[0][i];
        A = (n * e) - (f * t); //промежуточные вычисления
        B = (f * n) - (z * z);
        C = (w * n) - (t * z);
        D = (q * n) - (f * z);
        E = (n * o) - (f * f);
        a1 = (z * f * t) + (w * n * f) + (e * n * z);
        b1 = (z * z * f) + (n * f * f) + (q * n * z);
        c1 = (z * f * f) + (q * n * f) + (o * n * z);
        c = ((A * B) - (C * D)) / ((E * B) - (D * D)); //итоговые формулы
        b = (C - (D * c)) / B;
        a = (a1 - (b1 * b) - (c1 * c)) / (3 * n * z * f);
    }
    double test;
    for (int i = 0; i < n; i++)
    {
        test = (c * (x[0][i] * x[0][i])) + (b * (x[0][i])) + a;
        delta = test - x[1][i];
        sumDelt += pow(fabs(delta), 2);
        printf("%i]  [%lf | %lf | %lf]\n", i + 1, x[0][i], test, pow(delta, 2));
    }
    printf("a = %lf\nb = %lf\nc = %lf\n", c, b, a);
    printf("\nSumDeltKvad = %.6lf", sumDelt);
}

int main()
{
    double **x, **x2, **xLinear, **xQquadratic, **xLogarithmic, a, b, c;
    int n;
    system("cls");
    printf("N: ");
    scanf("%d", &n);

    x = getDataLinear(n);
    printf("      x\t     y\n");
    for (int i = 0; i < n; i++)
        printf("%i] [%5.1lf | %7.3lf]\n", i + 1, x[0][i], x[1][i]);
    approx(x, &a, &b, n);
    x2 = linear(n, x, a, b);
    
    printf("a = %lf\nb = %lf\n\n", b, a);

    x = getDataLogarithmic(n);
    printf("      x\t     y\n");
    for (int i = 0; i < n; i++)
        printf("%i] [%5.1lf | %7.3lf]\n", i + 1, x[0][i], x[1][i]);
    approx(x, &a, &b, n);
    x2 = logarithmic(n, x, a, b);
    approx(x2, &a, &b, n);

    
    printf("a = %lf\nb = %lf\n", b, a);
    
    x = getDataLinear(n);
    for (int i = 0; i < n; i++)
        printf("%i] [%5.1lf | %7.3lf]\n", i + 1, x[0][i], x[1][i]);
    QadratAproks(x, n, &a, &b, &c);
    system("pause");
    return 0;
}