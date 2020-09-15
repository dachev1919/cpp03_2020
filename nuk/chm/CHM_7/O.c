#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **getDataLinear(int n)
{
    double **f = (double **)malloc(2 * sizeof(double *));
    f[0] = (double *)malloc(n * sizeof(double));
    f[1] = (double *)malloc(n * sizeof(double));
    printf("\n-------------\nENTER X AND Y\n-------------\n");
    for (int i = 0; i < n; i++)
    {
        float t1, t2;
        printf("X[%i] -  ", i + 1);
        scanf("%f", &t1);
        printf("Y[%i] -  ", i + 1);
        scanf("%f", &t2);
        f[0][i] = (double)t1;
        f[1][i] = (double)t2;
    }
    return f;
}

double **getDataLogarithmic(int n)
{
    double **f = (double **)malloc(2 * sizeof(double *));
    f[0] = (double *)malloc(n * sizeof(double));
    f[1] = (double *)malloc(n * sizeof(double));
    printf("\n-------------\nENTER X AND Y\n-------------\n");
    for (int i = 0; i < n; i++)
    {
        float t1, t2;
        printf("X[%i] -  ", i + 1);
        scanf("%f", &t1);
        printf("Y[%i] -  ", i + 1);
        scanf("%f", &t2);
        f[0][i] = log((double)t1);
        f[1][i] = (double)t2;
    }
    return f;
}

// Линейная
double **linear(int n, double **x, double a, double b)
{
    double **f = (double **)malloc(2 * sizeof(double *));
    f[0] = (double *)malloc(n * sizeof(double));
    f[1] = (double *)malloc(n * sizeof(double));
    printf("------LINEAR-------\n");
    for (int i = 0; i < n; i++)
    {
        float t1, t2;
        f[0][i] = x[0][i];
        f[1][i] = b + a * f[0][i];
    }
    double delt, sumDelt = 0;
    printf("      X\t      Y\t      del`taKvadrat\n");
    for (int i = 0; i < n; i++){
        delt = x[1][i] - f[1][i];
        sumDelt += pow(fabs(delt), 2);
        printf("%i)  %lf  %lf  %lf\n", i + 1, x[0][i], f[1][i], pow(delt, 2));
    }
    printf("\n\nSumDeltKvad = %.6lf\n", sumDelt);
    return f;
}

// Логарифмическая
double **logarithmic(int n, double **x, double a, double b)
{
    double **f = (double **)malloc(2 * sizeof(double *));
    f[0] = (double *)malloc(n * sizeof(double));
    f[1] = (double *)malloc(n * sizeof(double));
    printf("------LOGARITHMIC-------\n");
    for (int i = 0; i < n; i++)
    {
        f[0][i] = x[0][i];
        f[1][i] = b + a * f[0][i];
    }
    double delt, sumDelt = 0;
    printf("      X\t      Y\t      del`taKvadrat\n");
    for (int i = 0; i < n; i++)
    {
        delt = f[1][i] - x[1][i];
        sumDelt += pow(fabs(delt), 2);
        printf("%i)  %lf  %lf  %lf\n", i + 1, x[0][i], f[1][i], pow(delt, 2));
    }
    printf("SumDeltKvad = %.6lf\n", sumDelt);
    return f;
}
// Метод наименьших квадратов для линейной аппроксимации
void approx(double **x, double *a, double *b, int n)
{
    double sX = 0;
    double sY = 0;
    double sX2 = 0;
    double sXY = 0;
    for (int i = 0; i < n; i++)
    {
        sX += x[0][i];
        sY += x[1][i];
        sX2 += x[0][i] * x[0][i];
        sXY += x[0][i] * x[1][i];
    }
    printf("sX - %lf, sY - %lf, sX2 - %lf, sXY - %lf", sX, sY, sX2, sXY);
    *a = (n * sXY - (sX * sY)) / (n * sX2 - sX * sX);
    *b = (sY - *a * sX) / n;
    return;
}
// Метод наименьших квадратов для квадратичной аппроксимации
void QadratAproks(double **x, int NN, double *_A, double *_B, double *_C)
{
    double a, aa, b, bb, c, cc, d, A, B, C, D, E;
    int n = 0;
    double z = 0;
    double f = 0;
    double q = 0;
    double k = 0;
    double l = 0;
    double p = 0;
    double s = 0;
    double delt, sumDelt = 0;
    printf("------QUADRATIC-------\n");
    printf("      X\t      Y\t      del`taKvadrat\n");
    for (int i = 0; i < NN; i++)
    {
        n++;
        z += x[0][i]; //обозначения сумм
        f += x[0][i] * x[0][i];
        q += x[0][i] * x[0][i] * x[0][i];
        k += x[0][i] * x[0][i] * x[0][i] * x[0][i];
        l += x[1][i];
        p += x[1][i] * x[0][i];
        s += x[1][i] * x[0][i] * x[0][i];
        A = (n * s) - (f * l); //промежуточные вычисления
        B = (f * n) - (z * z);
        C = (p * n) - (l * z);
        D = (q * n) - (f * z);
        E = (n * k) - (f * f);
        aa = (z * f * l) + (p * n * f) + (s * n * z);
        bb = (z * z * f) + (n * f * f) + (q * n * z);
        cc = (z * f * f) + (q * n * f) + (k * n * z);
        c = ((A * B) - (C * D)) / ((E * B) - (D * D)); //итоговые формулы
        b = (C - (D * c)) / B;
        a = (aa - (bb * b) - (cc * c)) / (3 * n * z * f);
    }
    double test;
    for (int i = 0; i < n; i++)
    {
        test = (c * (x[0][i] * x[0][i])) + (b * (x[0][i])) + a;
        delt = test - x[1][i];
        sumDelt += pow(fabs(delt), 2);
        printf("%i)  %lf  %lf  %lf\n", i + 1, x[0][i], test, pow(delt, 2));
    }
    printf("A1 = %lf\nA2 = %lf\nA3 = %lf\n", c, b, a);
    printf("\nSumDeltKvad = %.6lf", sumDelt);
}

int main()
{
    double **x, **x2, **xLinear, **xQquadratic, **xLogarithmic, a, b, c;
    int n;
    system("cls");
    printf("Enter quantity x and y: ");
    scanf("%d", &n);

    x = getDataLinear(n);
    printf("      X\t     Y\n");
    for (int i = 0; i < n; i++)
        printf("%i) %5.1lf  %7.3lf\n", i + 1, x[0][i], x[1][i]);
    approx(x, &a, &b, n);
    x2 = linear(n, x, a, b);
    
    printf("A1 = %lf\nA2 = %lf", b, a);
    printf("\n------------------------\n");

    x = getDataLogarithmic(n);
    printf("      X\t     Y\n");
    for (int i = 0; i < n; i++)
        printf("%i) %5.1lf  %7.3lf\n", i + 1, x[0][i], x[1][i]);
    approx(x, &a, &b, n);
    x2 = logarithmic(n, x, a, b);
    approx(x2, &a, &b, n);

    
    printf("A1 = %lf\nA2 = %lf", b, a);
    printf("\n-----------------------------\n");
    
    x = getDataLinear(n);
    for (int i = 0; i < n; i++)
        printf("%i) %5.1lf  %7.3lf\n", i + 1, x[0][i], x[1][i]);
    QadratAproks(x, n, &a, &b, &c);
    printf("\n-----------------------------\n");
    system("pause");
    return 0;
}