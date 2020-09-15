//#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>

using namespace std;

struct BinTree{
    int value;
    BinTree* left;
    BinTree* right;
};

void newBinTree(int val, BinTree** Tree){
    if ((*Tree) == NULL)
    {
        (*Tree) = new BinTree; // выделить память
        (*Tree)->value = val; // Поместить в выделенное место аргумент
        (*Tree)->left = (*Tree)->right = NULL;
        return;
    }
    if (val > (*Tree)->value) newBinTree(val, &(*Tree)->right); // Если аргумент больше чем текущий элемент
    else newBinTree(val, &(*Tree)->left); // Иначе поместить его влево
}

// Для печати дерева
void Print(BinTree**Tree, int l)
{
    int i;
    
    if (*Tree != NULL)
    {
        Print(&((**Tree).right), l + 1);
        for (i = 1; i < l; i++) cout << "  ";
        cout << (**Tree).value << endl;
        Print(&((**Tree).left), l + 1);
    }
}
// Прямой обход дерева
void TreeTraversalAndPrint(BinTree *Root)
{
    if (Root != NULL)
    {
        cout << Root->value << endl;
        TreeTraversalAndPrint(Root->left);
        TreeTraversalAndPrint(Root->right);
    }
}

// Обратный обход дерева
/*void TreeTraversalAndPrint2(BinTree *Root)
{
    if (Root != NULL)
    {
        TreeTraversalAndPrint2(Root->left);
        TreeTraversalAndPrint2(Root->right);
        cout << Root->value << endl;
    }
}
// Cимметричный обход дерева
void TreeTraversalAndPrint3(BinTree *Root)
{
    if (Root != NULL)
    {
        TreeTraversalAndPrint2(Root->left);
        cout << Root->value << endl;
        TreeTraversalAndPrint2(Root->right);
    }
}*/

// left < right, соответственно для нахождения элемента
// идем от корня по правым веткам до упора
BinTree* MaxValue(BinTree*Tree, int sum)
{
    if (Tree->right != NULL){
        sum += Tree->value;
        return MaxValue(Tree->right, sum);}
    else{
        cout << endl << "Sum do max elementa -> ";
        cout << sum << endl;
        return Tree;}
}

void MenuProg() {
    BinTree* Tree = NULL;
    char variant;
    int val;
    cout << "Sozdanie dereva" << endl;
    while (_getch() != 27)
    {
        cout << "Vvedite znachenie(ESC dlya zaversheniya): ";
        cin >> val;
        newBinTree(val, &Tree);
    }
    cout << "Obhod dereva ->" << endl;
    TreeTraversalAndPrint(Tree);
    
    int sum;
    BinTree* max = MaxValue(Tree, sum);
    cout << endl << "Max element dereva -> ";
    cout << max->value << endl;
}

int main(int argc, char const *argv[])
{
    MenuProg();
    system("pause");
    return 0;
}
