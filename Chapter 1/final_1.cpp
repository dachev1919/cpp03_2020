// Сhapter finale
#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int GOLD_PIECES = 900;
    int adventurers, killed, survivors;
    string leader;
    // Get inform
    cout << "Welcome to Lost Fortune\n\n";
    cout << "Please enter the following for your personalized adventure\n";
    cout << "Enter a number: ";
    cin >> adventurers;
    cout << "Enter a number, smaller than the first: ";
    cin >> killed;
    survivors = adventurers - killed;
    cout << "Enter your last name: ";
    cin >> leader;
    // Story
    cout << "\nA brave group of " << adventurers << " set out on a quest ";
    cout << "-- in search of the lost trasure of the Ancient Dwarves. ";
    cout << "The group was led by that legendary rogue. " << leader << ".\n";
    cout << "\nAlong the way, a band of marauding orders ambushed the party. ";
    cout << "All fought bravely under the command of " << leader;
    cout << ", and the ogres were defeated, but at a cost. ";
    cout << "Of the adventurers. " << killed << " were vanquished, ";
    cout << "leaving just " << survivors << " in the group.\n";
    cout << "\nThe party was about to give up all hope. ";
    cout << "But while laying the deceased to rest, ";
    cout << "they stumbled upon the buried fortune. ";
    cout << "So the adventurers split " << GOLD_PIECES << " gold pieces. ";
    cout << leader << " help on to the extra " << (GOLD_PIECES % survivors);
    cout << " pieces to keep things fair of course.\n";
    // task
    float x, y, z;
    cout << "x: ";
    cin >> x;
    cout << "\ny: ";
    cin >> y;
    cout << "\nz: ";
    cin >> z;
    x = (x + y + z) / 3.0;
    cout << "mid = " << x;
    return 0;
}