// Comment -- демонстрация работы c областями видимости
#include <iostream>

using namespace std;

void func();

int main()
{
    int var = 5; // лок. перем. в main()
    cout << "var in main() -> " << var << "\n\n";
    func();
    cout << "Back main() var is ->" << var << "\n\n";
    {
        cout << "In main() in a new scope var ->" << var << "\n\n";
        cout << "Created new var in a new scope.\n";
        int var = 10; // переменная в новой обл видим.
                      // скрывает другую переменную, с именем var
        cout << "In main() in a new scope var -> " << var << "\n\n";
    }
    cout << "At end of main() var created in new scope no longer exists.\n";
    cout << "At end of main() var -> " << var;
    return 0;
}

void func()
{
    int var = -5; // loc перем. в фунуции func()
    cout << "In func() var -> " << var << "\n\n";
}