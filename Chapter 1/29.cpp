// Comment
#include <iostream>
#include <string>

using namespace std;

int triple(int numb);
string triple(string text);

int main()
{
    cout << "Test 1(int = 5) -> " << triple(5) << "\n\n";
    cout << "Test 2(str = Oleg) -> " << triple("Oleg");
    return 0;
}

int triple(int numb)
{
    return (numb * 3);
}

string triple(string text)
{
    return (text + text + text);
}