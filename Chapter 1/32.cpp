// Comment 
#include <iostream>

using namespace std;
int main()
{
    int myScore = 1000;
    int& mikesScore = myScore;
    cout << "My ->" << myScore << endl;
    cout << "Mikes ->" << mikesScore << endl;
    myScore += 500;
    cout << "My ->" << myScore << endl;
    cout << "Mikes ->" << mikesScore << endl;
    mikesScore += 500;
    cout << "My ->" << myScore << endl;
    cout << "Mikes ->" << mikesScore << endl;
    return 0;
}