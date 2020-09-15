// Comment 
#include <iostream>

using namespace std;

int main()
{
    int score;
    cout << "Enter the number of points earned: ";
    cin >> score;
    if (score > 1000)
    {
        cout << "You scored 1000 or more. Impressive!\n\n";
    }
    else
    {
        cout << "Your scored less than 1000.\n";
    }
    return 0;
}