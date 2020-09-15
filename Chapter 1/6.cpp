// Comment
#include <iostream>

using namespace std;

int main()
{
    int score;

    if (true)
    {
        cout << "This is always displayed.\n\n";
    }
    if (false)
    {
        cout << "This is never displayed.\n\n";
    }
    
    cout << "Enter the number of points earned: ";
    cin >> score;

    if (score)
    {
        cout << "At least you didn`t score zero.\n\n";
    }
    if (score >= 250)
    {
        cout << "You scored 250 or more. Nice\n\n";
    }
    if (score >= 500)
    {
        cout << "You scored 500 or more. Nice\n\n";
        if (score >= 1000)
        {
            cout << "You scored 1000 or more.Impressive!\n\n";
        }
    }   
    return 0;
}