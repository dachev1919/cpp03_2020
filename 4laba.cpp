#include <iostream>
#include <ctime>
using namespace std;

int *first(int &s){
    const int MAX_SIZE = 100;
    cout << "Enter size array: ";
    cin >> s;
    int *temp = new int[MAX_SIZE];
    for (int i = 0; i < s; i++)
        temp[i] = rand()%30;
    return temp;
}

int dell(int size, int *&arr)
{
    int chet = 0, k = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]%2==0)
            chet++;
    }
    int *arrM = new int [size-chet];    
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
            continue;
        else
        {
            arrM[k] = arr[i];
            k++;
        }
    }
    delete [] arr;
    arr = arrM;
    return size-chet;
}

void sort(int size, int *arr)
{
    for (int i = 0; i < size; i++)
    {
        int temp = arr[0];
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void print(int a[], int size){
    for (int i = 0; i < size; i++)
        cout << a[i] << " | ";
    cout << endl;
}

void dellFirst(int n, int *&arr){
    int *arrN = new int[n-1];
    int index;
    for (int  i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            index = i;
            break;
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (i == index)
            continue;
        else if (i > index)
            arrN[i-1] = arr[i];
        else{
            arrN[i] = arr[i];
        }
    }
    delete [] arr;
    arr = arrN;
}

void third(){
    int n;
    cout << "n - ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%10-2;
        cout << arr[i] << " | ";
    }
    dellFirst(n, arr);  
    cout << endl;
    for (int i = 0; i < n-1; i++)
    {
        cout << arr[i] << " | ";
    }
}

void flip_column(int **&ptrarray, int row, int column)
{
    int swap, n;
    for (int i = 0; i < column; i++)
    {
        if (!(i%2))
        {
            n = row-1;
            for (int j = 0; j < row/2; j++)
            {
                swap = ptrarray[j][i];
                ptrarray[j][i] = ptrarray[n][i];
                ptrarray[n][i] = swap;
                n--;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << ptrarray[i][j] << "\t";
        cout << "\n";
    }
}

void fourth(){
    int row, column;
    srand(time(0));
    cout << "Enter row, column -> ";
    cin >> row >> column;
    int **ptrarray = new int*[row];
    for (int i = 0; i < row; i++)
        ptrarray[i] = new int[column];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            ptrarray[i][j] = rand()% 10 + 1;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << ptrarray[i][j] << "\t";
        cout << "\n";
    }
    cout << "-----Result-----"<< "\n";
    flip_column(ptrarray, row, column);    
}

int main()
{
    fourth();
    /*int *arr;
    int size;
    arr = first(size);
    sort(size, arr);
    print(arr, size);
    size = dell(size, arr);
    cout << "Result - ";
    print(arr, size);
    return 0;*/
}
