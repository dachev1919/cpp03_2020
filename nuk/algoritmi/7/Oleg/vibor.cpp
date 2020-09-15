#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;
// Функция сортировки прямым выбором
void selectionSort(int *num, int size)
{
    int min, temp; // для поиска минимального элемента и для обмена
    for (int i = 0; i < size - 1; i++)
    {
        min = i; // запоминаем индекс текущего элемента
        // ищем минимальный элемент чтобы поместить на место i-ого
        for (int j = i + 1; j < size; j++) // для остальных элементов после i-ого
        {
            if (num[j] < num[min]) // если элемент меньше минимального,
                min = j;           // запоминаем его индекс в min
        }
        temp = num[i]; // меняем местами i-ый и минимальный элементы
        num[i] = num[min];
        num[min] = temp;
    }
}
int main()
{
    int n = 3000;
    int a[n]; // Объявляем массив из 10 элементов
    // Вводим значения элементов массива
    system("cls");
    cout << "A = " << n;
    for (int i = 0; i < n; i++)
        a[i] = 1 + rand()%10;
    srand(time(0));       // начальное время
    selectionSort(a, n); // вызываем функцию сортировки
    // Выводим отсортированные элементы массива
    cout << "\nTime = " << clock() / 1000.0 + 1 << endl; // время работы программы
    getchar();
    return 0;
}