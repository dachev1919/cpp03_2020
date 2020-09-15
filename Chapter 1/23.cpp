// Comment
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
    // Подготовка
    const int MAX_WRONG = 8; 
    vector<string>words; // Подборка слов для загадывания 
    words.push_back("GUESS");
    words.push_back("OLEG");
    words.push_back("YARIK");
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0]; // Слово для отгадывания
    int wrong = 0; 
    string soFar(THE_WORD.size(), '-'); // Часть слова, открытая на данный момент
    string used = ""; // Уже отгаданные буквы
    cout << "Welcome to HANGMAN. Good luck!\n";

    // Основной цикл
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\n\nYou have " << MAX_WRONG - wrong;
        cout << " incorrect guesses left.\n";
        cout << "\nYou`ve used the foollowing letters:\n" << used << endl;
        cout << "\nSo far. The word is:\n" << soFar << endl;

        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess); // Перевод в верх. регистр 

        while (used.find(guess) != string::npos)
        {
            cout << "\nYou`ve already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }
        used += guess;
        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That`s right! " << guess << " is in the word!\n";
            // Обновить переменнуб soFar, включив в неё новую угаданную букву
            for (int i = 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            cout << "Sorry, " << guess << " isn`t in the word.\n";
        }
    }
    // Конец игры
    if (wrong == MAX_WRONG)
    {
        cout << "\nYou`ve been hanged!";
    }
    else
    {
        cout << "\nYou guessed it!";
    }
    cout << "\nThe word was '" << THE_WORD << "'" << endl;
    return 0;   
}