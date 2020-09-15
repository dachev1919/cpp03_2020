// comment
#include <iostream>

using namespace std;

int main()
{
    const int ALIEN_POINTS = 150;
    int aliensKilled = 10;
    int score = ALIEN_POINTS * aliensKilled;
    cout << "score: " << score << endl;
    enum difficult {NOVICE, EASY, NORMAL, HARD, UNBEATABLE};
    difficult myDifficulr = EASY;
    enum shipCost {FIGHTER_COST = 25, BOMBER_COST, CRUISER_COST = 50};
    shipCost myShipCost = BOMBER_COST;
    cout << "\nTo upgrade to Cruiser will cost " << (CRUISER_COST - myShipCost) << " Resource Points.\n";
    return 0;
}