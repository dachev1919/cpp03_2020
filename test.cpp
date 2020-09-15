#include <iostream>

using namespace std;


void TranspMatrix()
{
    cout << "\n\n+++++++++++++++++\n\n5. Transponuvannya matruci :\n";
    int n, m;
    cout << "Vvedit rozmir arr - ";
    cin >> n >> m;
    cout << "Matrica - \n";
    int Matrix[n][m];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Matrix[i][j] = rand() % 10;
            cout << Matrix[i][j] << "    ";
        }
        cout << endl;
    }
    int tMatrix[m][n];

    cout << "Result - \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tMatrix[i][j] = Matrix[j][i];
            cout << tMatrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\n+++++++++++++++++\n\n";
}

int main(){
    TranspMatrix();
    return 0;
}