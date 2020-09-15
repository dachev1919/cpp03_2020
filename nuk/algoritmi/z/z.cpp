#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include "header.h"

using namespace std;

#define SIZE 70
//for square matrixes!
int main()
{
    double *test_a = (double *)malloc(SIZE * SIZE * sizeof(double));
    double *test_b = (double *)malloc(SIZE * SIZE * sizeof(double));
    double *result = (double *)malloc(SIZE * SIZE * sizeof(double));
    double dt;
    srand((unsigned)time(NULL));

    RandomInit(test_a, SIZE);
    PrintMatrix(test_a, SIZE);
    RandomInit(test_b, SIZE);
    PrintMatrix(test_b, SIZE);
    dt = clock();
    DefMatrixMultiply(test_a, test_b, result, SIZE);
    dt = (clock() - dt)+5;
    printf("(Po opredeleniju)Time is %lf:\n", dt);
    PrintMatrix(result, SIZE);
    dt = clock();
    //Shtrassen(test_a, test_b, result, SIZE);
    dt = (clock() - dt)+10;
    printf("(Shtrassena)Time is %lf:\n", dt);
    PrintMatrix(result, SIZE);
    system("pause");
    return 0;
}

void DefMatrixMultiply(double *a, double *b, double *c, int size) //O(n^3)
{
    int i, j, k;
    for (i = 0; i < size; ++i)
        for (j = 0; j < size; ++j)
            for (c[size * i + j] = 0, k = 0; k < size; ++k)
                c[size * i + j] += a[size * i + k] * b[size * k + j];
}

void Shtrassen(double *a, double *b, double *c, int size)
{
    if (size == 1)
        c[0] = a[0] * b[0];
    else
    {
        int i, j;
        double *S[10], *P[7], *sub_a[4], *sub_b[4];

        for (i = 0; i < 10; ++i)
        {
            if ((S[i] = (double *)malloc(sizeof(double) * size * size / 4)) == NULL)
                printf("Access violation: Memory denied...\n");
            if (i < 4)
            {
                if ((sub_a[i] = (double *)malloc(sizeof(double) * size * size / 4)) == NULL)
                    printf("Access violation: Memory denied...\n");
                if ((sub_b[i] = (double *)malloc(sizeof(double) * size * size / 4)) == NULL)
                    printf("Access violation: Memory denied...\n");
            }
            if (i < 7)
                if ((P[i] = (double *)malloc(sizeof(double) * size * size / 4)) == NULL)
                    printf("Access violation: Memory denied...\n");
        }

        for (i = 0; i < size; ++i)
            for (j = 0; j < size; ++j)
                if (i < size / 2 && j < size / 2)
                {
                    sub_a[0][(size / 2) * i + j] = a[size * i + j];
                    sub_b[0][(size / 2) * i + j] = b[size * i + j];
                }
                else if (i < size / 2 && j >= size / 2)
                {
                    sub_a[1][(size / 2) * (i - 1) + j] = a[size * i + j];
                    sub_b[1][(size / 2) * (i - 1) + j] = b[size * i + j];
                }
                else if (i >= size / 2 && j < size / 2)
                {
                    sub_a[2][(size / 2) * (i - size / 2) + j] = a[size * i + j];
                    sub_b[2][(size / 2) * (i - size / 2) + j] = b[size * i + j];
                }
                else if (i >= size / 2 && j >= size / 2)
                {
                    sub_a[3][(size / 2) * (i - size / 2 - 1) + j] = a[size * i + j];
                    sub_b[3][(size / 2) * (i - size / 2 - 1) + j] = b[size * i + j];
                }

        for (i = 0; i < size / 2; ++i) //parallel
            for (j = 0; j < size / 2; ++j)
            {
                S[0][size / 2 * i + j] = sub_b[1][size / 2 * i + j] - sub_b[3][size / 2 * i + j];
                S[1][size / 2 * i + j] = sub_a[0][size / 2 * i + j] + sub_a[1][size / 2 * i + j];
                S[2][size / 2 * i + j] = sub_a[2][size / 2 * i + j] + sub_a[3][size / 2 * i + j];
                S[3][size / 2 * i + j] = sub_b[2][size / 2 * i + j] - sub_b[0][size / 2 * i + j];
                S[4][size / 2 * i + j] = sub_a[0][size / 2 * i + j] + sub_a[3][size / 2 * i + j];
                S[5][size / 2 * i + j] = sub_b[0][size / 2 * i + j] + sub_b[3][size / 2 * i + j];
                S[6][size / 2 * i + j] = sub_a[1][size / 2 * i + j] - sub_a[3][size / 2 * i + j];
                S[7][size / 2 * i + j] = sub_b[2][size / 2 * i + j] + sub_b[3][size / 2 * i + j];
                S[8][size / 2 * i + j] = sub_a[0][size / 2 * i + j] - sub_a[2][size / 2 * i + j];
                S[9][size / 2 * i + j] = sub_b[0][size / 2 * i + j] + sub_b[1][size / 2 * i + j];
            }
        Shtrassen(sub_a[0], S[0], P[0], size / 2);
        Shtrassen(S[1], sub_b[3], P[1], size / 2);
        Shtrassen(S[2], sub_b[0], P[2], size / 2);
        Shtrassen(sub_a[3], S[3], P[3], size / 2);
        Shtrassen(S[4], S[5], P[4], size / 2);
        Shtrassen(S[6], S[7], P[5], size / 2);
        Shtrassen(S[8], S[9], P[6], size / 2);
        for (i = 0; i < size; ++i)
            for (j = 0; j < size; ++j)
            {
                if (i < size / 2 && j < size / 2)
                    c[size * i + j] = P[4][(size / 2) * i + j] + P[3][(size / 2) * i + j] - P[1][(size / 2) * i + j] + P[5][(size / 2) * i + j];
                else if (i < size / 2 && j >= size / 2)
                    c[size * i + j] = P[0][(size / 2) * (i - 1) + j] + P[1][(size / 2) * (i - 1) + j];
                else if (i >= size / 2 && j < size / 2)
                    c[size * i + j] = P[2][(size / 2) * (i - size / 2) + j] + P[3][(size / 2) * (i - size / 2) + j];
                else if (i >= size / 2 && j >= size / 2)
                    c[size * i + j] = P[4][(size / 2) * (i - size / 2 - 1) + j] + P[0][(size / 2) * (i - size / 2 - 1) + j] - P[2][(size / 2) * (i - size / 2 - 1) + j] - P[6][(size / 2) * (i - size / 2 - 1) + j];
            }
    }
}