// Comment
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Запуск генератора случайных чисел
    int secretNumber = rand() % 100 + 1; // Случайное число в диапазоне от 0 до 100
    int tries = 0; // Число попыток
    int guess;
    cout << "\tWelcome to Guess My Number\n";
    do
    {
        cout << "Enter a guess: ";
        cin >> guess;
        ++tries;
        if (guess > secretNumber)
        {
            cout << "Too high!\n\n";
        }
        else if (guess < secretNumber)
        {
            cout << "Too low!\n\n";
        }
        else
        {
            cout << "\nThat`s it! You got it in " << tries << " guess!\n";
        }
    } while (guess != secretNumber);
    return 0;
}