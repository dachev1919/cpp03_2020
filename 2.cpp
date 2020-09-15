// Comment 
#include <iostream>

using namespace std;

void badSwap(int x, int y);
void goodSwap(int* const pX, int* const pY);

int main()
{
    int myScore = 1000;
    int yourScore = 1200;
    cout << "Original values\n";
    cout << "myScore: " << myScore << "\n";
    cout << "yourScore: " << yourScore << "\n";
    cout << "Calling badSwap()\n";
    badSwap(myScore, yourScore);
    cout << "myScore: " << myScore << "\n";
    cout << "yourScore: " << yourScore << "\n";
    cout << "Calling goodSwap()\n";
    goodSwap(&myScore, &yourScore);
    cout << "myScore: " << myScore << "\n";
    cout << "yourScore: " << yourScore << "\n";
    return 0;
}

void badSwap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void goodSwap(int* const pX, int* const pY)
{
    // Сохраняем наше значение, на которое указывает pX
    int temp = *pX;
    // Сохраняем значение, на которое указывал pY
    // по адресу, на который указывает pX
    *pX = *pY;
    // Сохраняем значение, на которое изначально указывал pX
    // по адресу, на который указывает pY
    *pY = temp;
}