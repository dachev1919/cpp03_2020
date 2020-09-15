// Comment
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//возвращает ссылку на строку
string& refToElement(vector<string>& vec, int i);

int main()
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");
    
    // отображается строка, на которую указывает возвращенная сслыка
    cout << "Sending the returned reference to cout:\n";
    cout << refToElement(inventory, 0) << "\n\n";
    
    // присваивает одну ссылку другой - малозатратная операция присваивания
    cout << "Assigning the returned reference to another reference.\n";
    string& rStr = refToElement(inventory, 1);
    cout << "Sending the new reference to cout:\n";
    cout << rStr << "\n\n";

    // копирует строковый объект - затратная операция присваивания
    cout << "Assigning the returned reference to a string object.\n";
    string str = refToElement(inventory, 2);
    cout << "Sending the new string object to cout:\n";
    cout << str << "\n\n";

    // изменения строкового объекта посредством возвращения ссылки
    cout << "Altering an object through a returned reference.\n";
    rStr = "Healing Potion";
    cout << "Sending the altered object to cout:\n";
    cout << inventory[1] << endl;

    return 0;
}

string& refToElement(vector<string>& vec, int i)
{
    return vec[i];
}