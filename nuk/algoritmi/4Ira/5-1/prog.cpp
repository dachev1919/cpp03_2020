#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define MAXWORD 100

using namespace std;

struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *p, char *w){
    int cond;
    if (p == NULL){
        p = (struct tnode*)malloc(sizeof(struct tnode));
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
    {
        p->left = addtree(p->left, w);
    }
    else
    {
        p->right = addtree(p->right, w);
    }
    return p;
}
// обхід дерева в симетричному порядку
void firsttreeprint(struct tnode *p)
{
    if (p != NULL)
    {
        firsttreeprint(p->left);
        printf("%d %s\n", p->count, p->word);
        firsttreeprint(p->right);
    }
}

// вивід елементів, які повторюються 2 чи більше разів
void secondtreeprint(struct tnode *p){
    if (p != NULL)
    {
        secondtreeprint(p->left);
        if((p->count) > 1)
            printf("%d %s\n", p->count, p->word);
        secondtreeprint(p->right);
    } 
}

int main(int argc, char const *argv[])
{
    cout << "Vvedit pochatkove derevo(0 dlya zakinchennya vvodu):\n";
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    do
    {
        scanf("%s", word);
        if (isalpha(word[0]))
        {
            root = addtree(root, word);
        }
    } while (word[0]!='0');
    cout << "Obhid dereva v symetrichnomu poryadku:\n";
    firsttreeprint(root);
    cout << "Zavdannya za variantom:\n";
    secondtreeprint(root);
    system("pause");
    return 0;
}

