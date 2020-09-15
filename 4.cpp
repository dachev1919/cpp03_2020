// OOP 
// Демонстрирует создание нового типа
#include <iostream>

using namespace std;

class Critter // определение нового класса
{
public:
    int m_Hunger; // член данных
    void Greet(); // прототип члена функции 
};

void Critter::Greet() // определение члена функции
{
    cout << "Hi. I`m a critter. My hunger level is " << m_Hunger << ".\n";
}

int main()
{
    Critter crit1;
    Critter crit2;
    crit1.m_Hunger = 9;
    cout << "Critl`s hunger level is " << crit1.m_Hunger << ".\n";
    crit2.m_Hunger = 3;
    cout << "Critl`s hunger level is " << crit2.m_Hunger << ".\n\n";
    crit1.Greet();
    crit2.Greet();
    return 0;
}