#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define MAXWORD 100

using namespace std;

struct treeNode
{
    char *word;
    int count;
    char *pos;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode *addtree(struct treeNode *tree, char *w, char *str)
{
    int cond;
    if (tree == NULL)
    {
        tree = (struct treeNode *)malloc(sizeof(struct treeNode));
        tree->word = strdup(w);
        tree->count = 1;
        tree->pos = strdup(str);
        tree->left = tree->right = NULL;
    }
    else if ((cond = strcmp(w, tree->word)) == 0)
        tree->count++;
    else if (cond < 0)
    {
        char str[] = "\t[Left]";
        tree->left = addtree(tree->left, w, str);
    }
    else
    {
        char str[] = "\t[Right]";
        tree->right = addtree(tree->right, w, str);
    }
    return tree;
}
// обхід дерева в зворотньому порядку
void treeprint(treeNode *tree)
{
    if (tree != NULL)
    {                           //Пока не встретится пустой узел
        treeprint(tree->left);  //Рекурсивная функция для левого поддерева
        treeprint(tree->right); //Рекурсивная функция для правого поддерева
        printf("%s %s\n", tree->word, tree->pos); //Отображаем корень дерева
    }
}

// завдання згідно варіанту
void secondtreeprint(treeNode *tree)
{
    if (tree != NULL)
    {                           //Пока не встретится пустой узел
        secondtreeprint(tree->left); //Рекурсивная функция для левого поддерева
        secondtreeprint(tree->right); //Рекурсивная функция для правого поддерева
        if(tree->left == NULL && tree->right == NULL)
            printf("%s %s\n", tree->word, tree->pos); //Отображаем корень дерева
    }
}

int main(int argc, char const *argv[])
{
    cout << "Pochatkove derevo('0' dlya zakinchennya vvodu):\n";
    struct treeNode *root;
    char word[MAXWORD];
    root = NULL;
    char t[] = "\t[Main]";
    do
    {
        scanf("%s", word);
        if (isalpha(word[0]))
        {
            root = addtree(root, word, t);
        }
    } while (word[0] != '0');
    cout << "Obhid dereva v zvorotnomu poryadku:\n";
    treeprint(root);
    cout << "Zavdannya:\n";
    secondtreeprint(root);
    system("pause");
    return 0;
}
