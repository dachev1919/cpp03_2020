// Comment
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string username;
    string password;
    bool success;

    cout << !success;
    cout << "\tGame Designer's Network\n";
    do
    {
        cout << "\nUsername: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        if (username == "Dachev" && password == "Oleg1999")
        {
            cout << "\nQQ, Oleg.";
            success = true;
        }
        else if (username == "Yarik" && password == "Yarik2000")
        {
            cout << "\nQQ, Yarik.";
            success = true;
        }
        else if (username == "Olya" && password == "Olya2006")
        {
            cout << "\nQQ, Olya.";
            success = true;
        }
        else if (username == "Salman" && password == "Salman2000")
        {
            cout << "\nQQ, Salman.";
            success = true;
        }
        else if (username == "guest" || password == "guest")
        {
            cout << "\nQQ, Guest.";
            success = true;
        }
        else
        {
            cout << "\nYour login or password failed. Try again.";
            success = false;
        }
    } while (!success);
    return 0;
}