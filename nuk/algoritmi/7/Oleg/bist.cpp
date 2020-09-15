#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

void quickSort(int *numbers, int l, int r)
{
    int pivot;    
    int l_h = l; 
    int r_h = r;
    pivot = numbers[l];
    while (l < r)
    {
        while ((numbers[r] >= pivot) && (l < r))
            r--;
        if (l != r)
        {
            numbers[l] = numbers[r];
            l++; 
        }
        while ((numbers[l] <= pivot) && (l < r))
            l++;
        if (l != r)
        {
            numbers[r] = numbers[l];
            r--;
        }
    }
    numbers[l] = pivot;
    pivot = l;
    l = l_h;
    r = r_h;
    if (l < pivot)
        quickSort(numbers, l, pivot - 1);
    if (r > pivot)
        quickSort(numbers, pivot + 1, r);
}
int main()
{
    int n = 3000;
    int a[n];
    system("cls");
    cout << "A - " << n;
    for (int i = 0; i < n; i++)
        a[i] = 1 + rand() % 15;
    srand(time(0));                    
    quickSort(a, 0, n - 1); 
    cout << "\nTime = " << clock() / 1000.0 << endl;
    getchar();
    return 0;
}