// Comment
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int>::const_iterator iter;
    cout << "Creating a list of score.";
    
    vector<int> scores;
    scores.push_back(1531);
    scores.push_back(3591);
    scores.push_back(7512);
    cout << "\nHigh scores:\n";
    for (iter = scores.begin(); iter != scores.end(); ++iter)
    {
        cout << *iter << endl;
    }
    cout << "\nFinding a score.";
    int score;
    
    cout << "\nEnter a score to find: ";
    cin >> score;

    iter = find(scores.begin(), scores.end(), score);
    if (iter != scores.end())
    {
        cout << "Score found.\n";
    }
    else
    {
        cout << "Score not found.\n";
    }
    
    cout << "\nRandomizing score.";
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(scores.begin(), scores.end());
    cout << "\nHighScores:\n";
    for (iter = scores.begin(); iter != scores.end(); ++iter)
    {
        cout << *iter << endl;
    }

    cout << "\nSorting scores.";
    sort(scores.begin(), scores.end());
    cout << "\nHigh Scores:\n";
    for (iter = scores.begin(); iter != scores.end(); ++iter);
    {
        cout << *iter << endl;
    }    
    return 0;
}