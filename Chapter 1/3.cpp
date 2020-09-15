// comment
#include <iostream>

using namespace std;

int main()
{
    int score;
    double distance;
    char playAgain;
    bool shieldsUp;
    short lives, alliensKilled;

    score = 0;
    distance = 1200.76;
    playAgain = 'y';
    shieldsUp = true;
    lives = 3;
    alliensKilled = 10;
    double engineTemp = 6572.89;
    
    cout << "\nscore: " << score << endl;
    cout << "distance: " << distance << endl;
    cout << "playAgain: " << playAgain << endl;
    // Пропускаем shieldsUp, поскольку булевы значения
    // как правило, не выводятся
    cout << "lives: " << lives << endl;
    cout << "alliensKilled: " << alliensKilled << endl;
    cout << "engineTemp: " << engineTemp << endl;
    int fuel;
    cout << "\nHow much fuel: ";
    cin >> fuel;
    cout << "fuel: " << fuel << endl;
    typedef unsigned short int ushort;
    ushort bonus = 10;
    cout << "\nbonus: " << bonus << endl;
    return 0;
}