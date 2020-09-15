// Comment
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));  // посев генератора случайных чисел 
    int randomNumber;
    int die; 
    
    while (true)
    {
        int randomNumber = rand();
        int die = (randomNumber % 6) + 1;       // получаем число между 1 и 6
        cout << "You rolled a " << die << endl;
        if (die == 6)
        {
            break;
        }
    }
    return 0;
}