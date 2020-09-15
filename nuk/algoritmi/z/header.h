void DefMatrixMultiply(double *a, double *b, double *c, int size);
void Shtrassen(double *a, double *b, double *c, int size);

void PrintMatrix(double *a, int size)
{
    int i, j;
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size; ++j)
            printf("%.1lf ", a[size * i + j]);
        printf("\n");
    }
    printf("\n");
}

void RandomInit(double *a, int size)
{
    int i, j;
    for (i = 0; i < size; ++i)
        for (j = 0; j < size; ++j)
            a[size * i + j] = rand()%10;
}