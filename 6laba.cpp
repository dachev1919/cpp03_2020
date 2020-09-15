#include <iostream>
using namespace std;

void find(const int * array, int count)
{
    int max = 0;
    for (int ix = 0; ix < count; ix++)
        if (array[ix] > max)
            max = array[ix];
    cout << max << endl;
}

void find(const double * array, int count)
{
    double max = 0;
    for (int ix = 0; ix < count; ix++)
        if (array[ix] > max)
            max = array[ix];
    cout << max << endl;
}

void find(const float * array, int count)
{
    float max = 0;
    for (int ix = 0; ix < count; ix++)
        if (array[ix] > max)
            max = array[ix];
    cout << max << endl;
}

int main()
{
    // размеры массивов
    const int iSize = 5,
              dSize = 7,
              fSize = 4;
    // массивы разных типов
    int     iArray[iSize] = {2, 13, 19, 20, 22};
    double  dArray[dSize] = {1.2345, 2.234, 3.57, 4.67876, 5.346, 6.1545, 7.7682};
    float   fArray[fSize] = { 1.34, 2.37, 3.23, 4.8};
    cout << "\nInt max: "; find(iArray, iSize);
    cout << "\nDouble max: "; find(dArray, dSize);
    cout << "\nFloat max: "; find(fArray, fSize);
    return 0;
}
