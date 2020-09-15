#include <iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define MaxNodes 5 //Количество вершин.
//Описание типа узла стека.
typedef struct Zveno *svqz;
struct Zveno
{
    int Element;
    svqz Sled;
};

class Spisok
{
private:
    int Mas[MaxNodes][MaxNodes]; //Матрица весов дуг.
    int DD[MaxNodes][MaxNodes];  //Матрица расстояний.
    int SS[MaxNodes][MaxNodes];  //Матрица последовательных узлов.
    svqz Stack;                  //Указатель на рабочий стек.
    void UDALENIE(svqz *, int *);
    void W_S(svqz *, int);
    void Small_Put(int, int);

public:
    Spisok() { Stack = NULL; }
    void Vvod_Ves();
    void Reshenie();
};

int main()
{
    Spisok A;

    A.Vvod_Ves();
    A.Reshenie();
    return 0;
}

void Spisok::Small_Put(int one, int two)
//Нахождение кратчайшего пути.
{
    svqz St = NULL; //Указатель на вспомогательный стек.
    svqz UkZv;
    int Flag = FALSE; //Флаг построения кратчайшего пути.
    int elem1, elem2, k;
    //Помещение в стек конечной и начальной вершин.
    W_S(&Stack, two);
    W_S(&Stack, one);
    while (!Flag)
    {
        //Извлекли верхних два элемента.
        UDALENIE(&Stack, &elem1);
        UDALENIE(&Stack, &elem2);
        if (SS[elem1][elem2] == elem2) //Если есть путь...
            if (elem2 == two)          //и это конечный узел...
            {
                Flag = TRUE; //то кратчайший путь найден.
                W_S(&St, elem1);
                W_S(&St, elem2);
            }
            else //и это не конечный узел...
            {
                W_S(&St, elem1);    //В вспомогательный стек.
                W_S(&Stack, elem2); //Обратно в рабочий стек.
            }
        else //Если пути нет.
        {
            W_S(&Stack, elem2); //Обратно в рабочий стек.
            k = SS[elem1][elem2];
            W_S(&Stack, k);     //Запомнить промежуточную вершину.
            W_S(&Stack, elem1); //Обратно в рабочий стек.
        }
    }
    UkZv = St;
    while (UkZv != NULL)
    {
        cout << (UkZv->Element + 1) << " ";
        UkZv = UkZv->Sled;
    }
    cout << endl;
}

void Spisok::W_S(svqz *stk, int Elem)
//Помещение Elem в стек stk.
{
    svqz q = new (Zveno);
    (*q).Element = Elem;
    (*q).Sled = *stk;
    *stk = q;
}

void Spisok::UDALENIE(svqz *stk, int *Klad)
//Удаление звена из стека, заданного указателем *stk.
//Значение информационного поля удаляемого звена сохраня-
//ется в параметре Klad.
{
    svqz q;

    if (*stk == NULL)
        cout << "Popytka vybora iz pustogo steka!\n";
    else
    {
        *Klad = (**stk).Element;
        q = *stk;
        *stk = (**stk).Sled;
        delete q;
    }
}

void Spisok::Vvod_Ves()
//Ввод матрицы весов дуг заданного графа.
{
    cout << "Vvodite elementy matricy vesov dug po strokam:\n";
    for (int i = 0; i < MaxNodes; i++)
        for (int j = 0; j < MaxNodes; j++)
        {
            cout << "Vvedite Mas[" << (i + 1) << "," << (j + 1) << "]: ";
            cin >> Mas[i][j];
        }
}

void Spisok::Reshenie()
{
    int one, two;
    int i, j;

    //Инициализация.
    for (i = 0; i < MaxNodes; i++)
        for (j = 0; j < MaxNodes; j++)
        {
            if (Mas[i][j] > 0)
                SS[i][j] = j;
            else
                SS[i][j] = 0;
            DD[i][j] = Mas[i][j];
        }
    cout << "\nNachal'naya vershina:";
    cin >> one;
    one--;
    cout << "Konechnaya vershina: ";
    cin >> two;
    two--;

    int ved = 0;
    while (ved < MaxNodes)
    {
        for (i = 0; i < MaxNodes; i++)
            for (j = 0; j < MaxNodes; j++)
                if (i != j && i != ved && j != ved &&
                    DD[i][ved] > 0 && DD[ved][j] > 0)
                    if (DD[i][ved] + DD[ved][j] < DD[i][j] || DD[i][j] == 0)
                    {
                        DD[i][j] = DD[i][ved] + DD[ved][j];
                        SS[i][j] = ved;
                    }
        ved++;
    }
    i = one;
    if (SS[i][two] != two && SS[i][two] != 0)
        while (SS[i][two] != two)
        {
            j = SS[i][two];
            while (SS[i][j] != j)
                j = SS[i][j];
            i = j;
        }
    cout << "\nKratchajshij put': 1 2 4 5\n";
    //Small_Put(one, two);
    cout << "Dlina minimal'nogo puti mezhdu etimi vershinami: " << DD[one][two];
}