#include <iostream>
using namespace std;

void addCols(int **&arr, const int n, const int m, const int k)
{
    int **arrM = new int *[n];
    for (int i = 0; i < n + 1; i++)
        arrM[i] = new int[m + 1];
    const int M = m + 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (j < k)
                arrM[i][j] = arr[i][j];
            else if (j == k)
                arrM[i][j] = rand() % 30;
            else
                arrM[i][j] = arr[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    arr = arrM;
}

void fifth()
{
    int rows, cols, k;
    cout << "Rows and cols - ";
    cin >> rows >> cols;
    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new int [cols];
    
    /*заполняем*/
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            arr[i][j] = rand() % 30;
    }
    /*вывод*/
    for (int i = 0; i < rows; i++)
    {
        cout << endl;
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << '\t';
    }
    cout << "\nK - ";
    cin >> k;
    if (k > cols + 1)
        cout << "Error";
    addCols(arr, rows, cols, k-1); 
    for (int i = 0; i < rows; i++)
    {
        cout << endl;
        for (int j = 0; j < cols + 1; j++)
            cout << arr[i][j] << '\t';
    }
}

void fourth()
{
    int arr[10], m, n;
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand()%30-5;
        cout << "arr[" << i << ']' << arr[i] << '\n';
    }
    for (n = 0; n < 10; n++)
    {
        if (arr[n] < 0)
            break;
    }
    if (n>=10)
        cout << "\nNo negative numbers";
    else
        cout << "Index: " << n << "\nNumber: " << arr[n];  
}

void third()
{   
    int arr[10], m, n, tmp;
    for (int i = 0; i < 10; i++){
        arr[i] = rand()%30;
        cout << arr[i] << ' ';}
    cout << "\nM - ";
    cin >> m;
    n = 10;
    for (int i = 0; i < m; i++)
    {
        for (int j = n - 1 ; j >= 0; j--)
        {
            if (j == n-1)
                tmp = arr[n-1];
            else
                arr[j+1]=arr[j];
        }
        arr[0] = tmp;
    }
    cout << "Result - ";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << ' ';
}

void second_push_back(int *&arr, int &n, const int k)
{
    int *newArr = new int [n + k];
    cout << "\nResult Arr[n+k] - ";
    for (int i = 0; i < n; i++){
        newArr[i] = arr[i];
        cout << newArr[i] << " | ";}

    for (int i = 0; i < k; i++){
        n += 1;
        newArr[n] = rand()%30;
        cout << newArr[n] << " | ";}
    delete[] arr;
    arr = newArr;
}

void second()
{
    int n, k;
    cout << "Enter n, k: ";
    cin >> n >> k;
    int *arr = new int[n];
    cout << "Arr[n] - ";
    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand()%30;
        cout << arr[i] << " | ";
    }
    second_push_back(arr, n, k);
}

int main()
{
    fifth();
    return 0;
}
