// Демонстрирует работу со статическими членами данных и функциями-членами
#include <iostream>
using namespace std;

class Critter
{
    public:
        static int s_Total; // объявление статической переменной-числа
        // Общее количество существующих объектов Critter
        Critter(int hunger = 0);
        static int GetTotal(); // прототип статической функции-члена
    private:
        int m_Hunger;
};

int Critter::s_Total = 0; // инициализация статической переменной-числа
Critter::Critter(int hunger):
m_Hunger(hunger)
{
    cout << "A critter has been born!" << endl;
    ++s_Total;
}

int Critter::GetTotal()
{
    return s_Total;
}

int main()
{
    cout << "The total number of critters is: ";
    cout << Critter::s_Total << "\n\n";
    Critter ctit1, crit2, crit3;
    cout << "\nThe total number of critters is: ";
    cout << Critter::GetTotal() << endl;
    return 0;
}