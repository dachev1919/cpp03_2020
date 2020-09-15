#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>

using namespace std;

struct BinTree{
    float value;
    BinTree* left;
    BinTree* right;
};

void newBinTree(float val, BinTree** Tree){
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
/*void TreeTraversalAndPrint(BinTree *Root)
{
    if (Root != NULL)
    {
        cout << Root->value << endl;
        TreeTraversalAndPrint(Root->left);
        TreeTraversalAndPrint(Root->right);
    }
}*/

//Обратный обход дерева
void TreeTraversalAndPrint(BinTree *Root)
{
    if (Root != NULL)
    {
        TreeTraversalAndPrint(Root->left);
        TreeTraversalAndPrint(Root->right);
        printf("%.1f\n", Root->value);
    }
}
// Cимметричный обход дерева
/*void TreeTraversalAndPrint3(BinTree *Root)
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
BinTree* MaxValue(BinTree*Tree)
{
    if (Tree->right != NULL){
        printf("%.1f\n", Tree->value);
        return MaxValue(Tree->right);}
    else
        return Tree;
}

void MenuProg() {
    BinTree* Tree = NULL;
    char variant;
    float val;
    cout << "Create TREE" << endl;
    while (_getch() != 27)
    {
        cout << "Enter val(ESC for close): ";
        cin >> val;
        newBinTree(val, &Tree);
    }
    cout << "Obratniy obhod dereva ->" << endl;
    TreeTraversalAndPrint(Tree);
    cout << "Zavdannya za variantom:" << endl;
    BinTree* max = MaxValue(Tree);
    cout << endl << "Max element -> ";
    printf("%.1f\n", max->value);
}

int main(int argc, char const *argv[])
{
    MenuProg();
    system("pause");
    return 0;
}
