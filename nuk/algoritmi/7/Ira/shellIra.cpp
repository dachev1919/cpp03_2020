#include <iostream>
#include <time.h>
using namespace std;
int i, j, n, d, count;
void Shell(int A[], int n) //сортировка Шелла
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
    int n = 5000;
    cout << "Rozmir masivu - " << n << endl;
    cout << "Stvorjuju ta zapovnjuju masiv..." << endl;
    int *A = new int[n]; //объявление динамического массива
    for (int i = 0; i < n; i++) //ввод массива
        A[i] = 1 + rand() % 10;
    cout << "Sortuju masiv...";
    srand(time(0)); // начальное время
    Shell(A, n);
    delete[] A;                                    //освобождение памяти
    cout << "\nRuntime = " << clock() / 1000.0 << endl; // время работы программы
    system("pause");
    return 0;
}