// Comment
#include <iostream>

using namespace std;

int main()
{
    char again = 'y';
    while (again != 'n')
    {
        cout << "\n**Played an exiting game**";
        cout << "\nDo you want to play again? (y/n)";
        cin >> again;
    }
    cout << "\nOkey, bye:L";
    return 0;
}