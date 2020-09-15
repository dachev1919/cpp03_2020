// OOP
// Демонстрирует работу конструктора в классах
#include <iostream>
using namespace std;

class Critter
{
private:
    /* data */
public:
    int m_Hunger;
    Critter(int hunger = 0); // прототип конструктора
    void Greet();
};

Critter::Critter(int hunger) // определение конструктора 
{
    cout << "A new critter has been born!" << endl;
    m_Hunger = hunger;
}

void Critter::Greet()
{
    cout << "Hi. I`m a critter. My hunger level is " << m_Hunger << ".\n\n";
}

int main()
{
    Critter crit(7);
    crit.Greet();
    return 0;
}