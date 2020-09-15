#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "math.h"
#include <vector>
#include <string>
#include <cctype>
using namespace std;
// функція запису з файла в строку
int *WriteArrayFromFile(int *n, char *name)
{
    int i, s;
    ifstream File(name);
    if (!File)
    {
        cout << "Cannot find a file\n";
        exit(0);
    }
    File >> *n;
    string *A = new string[*n];
    for (i = 0; i < *n; i++)
    {
        File >> A[i];
    }
    File.close();
    // видалення знаків
    for (int i = 0; i != n; ++i)
        if (ispunct(*i))
            *i = ' ';
    return A;
}

using namespace std;
// створення списку
class Node
{
    friend class HashTable;
    Node *next;
    string key;
    int size;

public:
    Node()
    {
    }
    Node(string k, int s, Node *n)
    {
        key = k;
        size = s;
        next = n;
    }
    ~Node()
    {
    }
};
class HashTable
{
public:
    int size;
    vector<Node *> *Nodes;
    HashTable(int tableSize)
    {
        size = tableSize;
        Nodes = new vector<Node *>(size);
    }
    ~HashTable()
    {
    }
    // вставити множенням
    void insertByMultiplication(string key, int size)
    {
        int index = getHashByMultiplication(key, size);
        if (Nodes->at(index) == NULL)
        {
            Nodes->at(index) = new Node(key, size, NULL);
            return;
        }
        Node *p = Nodes->at(getHashByMultiplication(key));
        while (p != NULL)
        {
            if (p->next == NULL)
            {
                p->next = new Node(key, size, NULL);
                break;
            }
            p = p->next;
        }
    }
    void insertByDivision(string key, int size)
    {
        int index = getHashByDivision(key);
        if (Nodes->at(index) == NULL)
        {
            Nodes->at(index) = new Node(key, size, NULL);
            return;
        }
        Node *p = Nodes->at(getHashByDivision(key));
        ;
        while (p != NULL)
        {
            if (p->next == NULL)
            {
                p->next = new Node(key, size, NULL);
                break;
            }
            p = p->next;
        }
    }
    // видалення елементу
    void popFromHeshTable(string key){
        int index = getHashByDivision(key);
        Node *p = Nodes->at(getHashByDivision(key));
        int *search = this->searchKeyByDivision(key, size);
        if (search)
        {
            cout << "Element not found!" << endl;
            return;
        }
        p->remove(key);        
    }
    // пошук
    int searchKeyByDivision(string key, int size)
    {
        for (Node *pos = Nodes->at(getHashByDivision(key)); pos; pos = pos->next)
        {
            if (pos->key == key)
                return 1;
        }
        return 0;
    }
    int searchKeyByMultiplication(string key)
    {
        for (Node *pos = Nodes->at(getHashByMultiplication(key)); pos; pos = pos->next)
        {
            if (pos->key == key)
                return 1;
        }
        return 0;
    }
    int getSize()
    {
        return size;
    }
    int getHashByDivision(string key)
    {
        return abs(key % getSize());
    }
    // функція множення за варіантом
    int getHashByMultiplication(string key)
    {
        float A = 0.517;
        int hashCode = getSize() * fmod(key * A, 1);
        return hashCode;
    }
    // вивід на екран
    void print(int start)
    {
        int lineCount = 0;
        for (int i = start; i < (Nodes->size()); i++)
        {
            cout << i << "\t";
            Node *p = Nodes->at(i);
            while (p != NULL)
            {
                cout << i << ". Key - " << p->key << "size - " << p->size << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
};

int main(int argc, char *argv[])
{
    int n, s, i, j, k, y, counter, choose = 1;

    argv[1] = "file.txt";

    int *A = ReadArrayFromFile(&n, argv[1]);

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (A[i] == A[j])
            {
                for (k = j; k < n; k++)
                {
                    A[j] = A[j + 1];
                }
                n--;
            }
        }
    }

    HashTable *hash = new HashTable(n * 2 + 1);

    switch (choose)
    {
    case 1:
    {
        for (int i = 0; i < n; i++)
        {
            hash->insertByMultiplication(A[i]);
        }
        hash->print(0);
        system("pause");
        for (i = 0; i < s; i++)
        {
            counter = 0;
            for (j = 0; j < n; j++)
            {
                y = S[i] - A[j];
                if (hash->searchKeyByMultiplication(y) == 1)
                {
                    cout << endl
                         << A[j] << " " << y;
                    counter++;
                    break;
                }
            }
            if (counter == 0)
                cout << endl
                     << 0 << " " << 0;
        }
        cout << endl;
    }
    case 2:
    {
        for (int i = 0; i < n; i++)
        {
            hash->insertByDivision(A[i]);
        }
        hash->print(0);
        system("pause");
        for (i = 0; i < s; i++)
        {
            counter = 0;
            for (j = 0; j < n; j++)
            {
                y = S[i] - A[j];
                if (hash->searchKeyByDivision(y) == 1)
                {
                    cout << endl
                         << A[j] << " " << y;
                    counter++;
                    break;
                }
            }
            if (counter == 0)
                cout << endl
                     << 0 << " " << 0;
        }
        cout << endl;
    }
    }

    system("pause");
    return 0;
}