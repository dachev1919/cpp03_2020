#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void first(){
    cout << "-----------------Task 1------------------" << endl;
    int sum = 0, num = 0, size;
    cout << "Kolichestvo elementov: ";
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        cout << "Num " << i + 1 << ": ";
        cin >> num;
        if (num % 2 == 0)
        {
            sum += num;
        }
    }
    cout << "Sum = " << sum;
}  

void second(){
    cout << "\n-----------------Task 2------------------" << endl;
    int n, K1, K2;
    int s_k1 = 0;
    int s_k2 = 0;
    cout << "K1: ";
    cin >> K1;
    cout << "K2: ";
    cin >> K2;
    cout << "\nEnter N (0 - Exit):\n";
    do
    {
        cout << "N - ";
        cin >> n;
        if (n == 0)
            break;
        if (!(n % K1))
            s_k1++;
        if (n % K2)
            s_k2++;
    } while (true);
    cout << "\nK1: " << s_k1 << endl;
    cout << "K2: " << s_k2 << endl;
}

void third(){
    cout << "\n-----------------Task 3------------------" << endl;
    double x, drob, sum = 0, znam = 1;
    int n, i = 1, mi = 1;
    long double e;
    cout << "x, n: ";
    cin >> x >> n;
    e = exp(-x*x);
    cout.setf(ios_base::fixed);
    cout.precision(17);
    double chis = 1;
    cout << "e^((-x)^2) = " << e << endl;
    do
    {
        drob = chis / znam;
        sum = sum + mi * drob;
        mi = -mi;
        chis *= x * x;
        znam *= i;
        ++i;
    } while (drob > e);
    cout << "e^((-x)^2) = " << sum << endl;
}

int main(){
    third();
    return 0;
}