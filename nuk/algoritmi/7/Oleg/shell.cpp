#include <iostream>
#include <time.h>
using namespace std;
int i, j, n, d, count;
void Shell(int A[], int n)
{
    d = n;
    d = d / 2;
    while (d > 0)
    {
        for (i = 0; i < n - d; i++)
        {
            j = i;
            while (j >= 0 && A[j] > A[j + d])
            {
                count = A[j];
                A[j] = A[j + d];
                A[j + d] = count;
                j--;
            }
        }
        d = d / 2;
    }
}
//главная функция
int main()
{
    int n = 3000;
    int *A = new int[n];
    system("cls");
    cout << "A = " << n;
    for (int i = 0; i < n; i++)
        A[i] = 1 + rand()%10;
    srand(time(0));
    Shell(A, n);
    delete[] A;
    cout << "\nTime = " << clock() / 1000.0 << endl;
    getchar();
    return 0;
}