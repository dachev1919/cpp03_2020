// Comment
#include <iostream>

using namespace std;

int main()
{
    char again;
    do
    {
        cout << "\n**Played an exiting game**";
        cout << "\nDo you want to play again? (y/n) ";
        cin >> again;
    } while (again != 'n');
    cout << "\nOkey, bye:L";
    return 0;
}