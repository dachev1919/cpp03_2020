// Comment
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    unsigned int variable = 0, i = 0;
    vector<string> myVector;
    vector<string>::const_iterator myIter;

    while (variable != 4)
    {
        cout << "You can:\n\t1 - Add book\n\t2 - Delete book";
        cout << "\n\t3 - Display all books\n\t4 - Exit";
        cout << "\nEnter your choice: ";
        cin >> variable;
        if (variable == 1)
        {
            string name;
            cin >> name;
            myVector.push_back(name);
        }
        else if (variable == 2)
        {
            cout << "\n\n\t"
                 << "--Book List--\n";
            for (myIter = myVector.begin(); myIter != myVector.end(); ++myIter)
            {
                ++i;
                cout << i << " - " << *myIter << "." << endl;
            }
            i = 0;
            cout << "\nEnter the book number to delete: ";
            cin >> i;
            myVector.erase(myVector.begin() + i-=1);
            i = 0;
            cout << "Successfully!\n";
        }
        else if (variable == 3)
        {
            cout << "\n\n\t" << "--Book List--\n";
            for (myIter = myVector.begin(); myIter != myVector.end(); ++myIter)
            {
                ++i;
                cout << i << " - " << *myIter << "." <<endl;
            }
            cout << "\n";
            i = 0;
        }
    }
    return 0;
}
