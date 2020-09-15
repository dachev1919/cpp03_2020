// Comment
#include <iostream>

using namespace std;

int main()
{
    int score;

    cout << "Enter your score: ";
    cin >> score;
    if (score >= 1000)
    {
        cout << "Your score 1000 or more. Impressive!" << endl;
    }
    else if (score >= 500)
    {
        cout << "Your score 500 or more. Nice." << endl;
    }
    else if (score >= 250)
    {
        cout << "Your score 250 or more. Decent." << endl;
    }
    else
    {
        cout << "Your score less than 250. Nothing to brag about." << endl;
    }
    return 0;
}