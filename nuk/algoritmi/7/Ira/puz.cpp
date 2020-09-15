#include <iostream>
#include <time.h>
using namespace std;
#define n 5000
int main()
{
    
    /* Заполним массив значениями */
    int mass[n];
    cout << "Rozmir masivu - " << n << endl;
    cout << "Stvorjuju ta zapovnjuju masiv..." << endl;
    for (int i = 0; i < n; ++i)
        mass[i] = 1 + rand() % 15;
    /* Отсортируем массив */
    cout << "Sortuju masiv...";
    srand(time(0)); // начальное время
    for (int i = 1; i < n; ++i)
    {
        for (int r = 0; r < n - i; r++)
        {
            if (mass[r] > mass[r + 1])
            {
                // Обмен местами
                int temp = mass[r];
                mass[r] = mass[r + 1];
                mass[r + 1] = temp;
            }
        }
    }
    double runtime =  clock() / 1000.0; // время работы программы
    cout << "\nRuntime = " << runtime << endl; // время работы программы
    system("pause");
    return 0;
}