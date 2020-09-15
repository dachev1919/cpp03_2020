// Comment
#include <iostream>

using namespace std;

int main()
{
    int x = 100, y = 1, number, i;
    char v;

    while (v != 'y')
    {
        i++;
        number = (x + y) / 2;
        cout << number << "\n";
        cin >> v;
        if (v == 'l') x = number - 1;
        else if (v == 'h') y = number + 1;
        else if (v == 'y') break;
    }
    cout << "Yeah! I`ve done it in " << i << " moves!";
    return 0;
}