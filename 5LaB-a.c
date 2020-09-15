#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct date
{
    char month[30];
    int day;
    int year;
} date_list[MAX];
void init_list(void), enter(void);
void find(void), list(void);
void load(void), save(void);
int menu_select(void), find_free(void);
int main(void)
{
    printf("-------------Menu-------------");
    printf("\n1. Enter month\n");
    printf("2. List\n");
    printf("3. Save file\n");
    printf("4. Load file\n");
    printf("5. Find\n");
    printf("6. Exit\n");
    printf("------------------------------");
    char choice;
    init_list(); /* инициализация массива структур */
    for (;;)
    {
        choice = menu_select();
        switch (choice)
        {
        case 1:
            enter();
            break;
        case 2:
            list();
            break;
        case 3:
            save();
            break;
        case 4:
            load();
            break;
        case 5:
            find();
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}
/* Поиск даты с летними месяцами */
void find(void)
{
    register int t;
    int cond;
    for (t = 0; t < MAX; ++t)
    {
        if (date_list[t].month[0])
        {
            if ((cond = strcmp("June", date_list[t].month)) == 0 ||
                (cond = strcmp("July", date_list[t].month)) == 0 ||
                (cond = strcmp("August", date_list[t].month)) == 0)
            {
                printf("%s\n", date_list[t].month);
                printf("%d\n", date_list[t].day);
                printf("%d\n", date_list[t].year);
            }
        }
    }
    printf("\n\n");
}
/* Вывод списка на экран. */
void list(void)
{
    register int t;

    for (t = 0; t < MAX; ++t)
    {
        if (date_list[t].month[0])
        {
            printf("%s\n", date_list[t].month);
            printf("%d\n", date_list[t].day);
            printf("%d\n", date_list[t].year);
        }
    }
    printf("\n\n");
}
/* Сохранение списка. */
void save(void)
{
    FILE *fp;
    register int i;

    if ((fp = fopen("maillist", "wb")) == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    for (i = 0; i < MAX; i++)
        if (*date_list[i].month)
            if (fwrite(&date_list[i],
                       sizeof(struct date), 1, fp) != 1)
                printf("Error writing file.\n");

    fclose(fp);
}
/* Загрузить файл. */
void load(void)
{
    FILE *fp;
    register int i;

    if ((fp = fopen("maillist", "rb")) == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    init_list();
    for (i = 0; i < MAX; i++)
        if (fread(&date_list[i],
                  sizeof(struct date), 1, fp) != 1)
        {
            if (feof(fp))
                break;
            printf("Error reading file.\n");
        }

    fclose(fp);
}
/* Инициализация списка. */
void init_list(void)
{
    register int t;

    for (t = 0; t < MAX; ++t)
        date_list[t].month[0] = '\0';
}
/* Получения значения, выбранного  в меню. */
int menu_select(void)
{
    char s[80];
    int c;
    do
    {
        printf("\nEnter the number: ");
        gets(s);
        c = atoi(s);
    } while (c < 0 || c > 6);
    return c;
}
/* Добавление адреса в список. */
void enter(void)
{
    int slot;
    char s[80];

    slot = find_free();

    if (slot == -1)
    {
        printf("\nThe list is full");
        return;
    }

    printf("Enter month name: ");
    gets(date_list[slot].month);

    printf("Enter day: ");
    scanf("%d", &date_list[slot].day);

    printf("Enter year: ");
    scanf("%d", &date_list[slot].year);
}
/* Поиск свободной структуры. */
int find_free(void)
{
    register int t;

    for (t = 0; date_list[t].month[0] && t < MAX; ++t)
        ;
    if (t == MAX)
        return -1; /* свободных структур нет */
    return t;
}
