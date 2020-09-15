#include <stdio.h>
#include <stdlib.h>
struct date
{
    int day;
    char *month;
    int year;
};
int save(char *filename, struct date *d, int n);
int load(char *filename);
int find(char *filename);
void print(struct date *d, int n);
void del(char *filename);
int main(void)
{
    char *filename = "date.dat";
    struct date date[] = {30, "July", 1999,
                          7, "December", 1999,
                          17, "November", 2006,
                          12, "August", 2012};
    int n = sizeof(date) / sizeof(date[0]);
    save(filename, date, n);
    load(filename);
    find(filename);
    del(filename);
    return 0;
}
void del(char *filename)
{
    FILE *f;
    FILE *temp;
    temp = fopen("temp", "wb");
    fclose(temp);
    remove(filename);
    rename("temp", filename);
}
void print(struct date *d, int n)
{
    for (int i = 0; i < n; i++)
        printf("%-5d %5d %-20s %5d\n", i + 1, d[i].day, d[i].month, d[i].year);
}
int save(char *filename, struct date *da, int n)
{
    FILE *fd;
    char *c;
    // число записываемых байтов
    int size = n * sizeof(struct date);
    if ((fd = fopen(filename, "wb")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    // запись количества структур
    c = (char *)&n;
    for (int i = 0; i < sizeof(int); i++)
        putc(*c++, fd);
    // посимвольно записываем в файл все структуры
    c = (char *)da;
    for (int i = 0; i < size; i++)
    {
        putc(*c, fd);
        c++;
    }
    fclose(fd);
    return 0;
}
int load(char *filename)
{
    FILE *fd;
    char *c;
    int m = sizeof(int);
    int n, i;
    // выделяем память для количества данных
    int *pti = (int *)malloc(m);
    if ((fd = fopen(filename, "r")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    // считываем количество структур
    c = (char *)pti;
    while (m > 0)
    {
        i = getc(fd);
        if (i == EOF)
            break;
        *c = i;
        c++;
        m--;
    }
    // получаем число элементов
    n = *pti;
    // выделяем память для считанного массива структур
    struct date *ptr = (struct date *)malloc(n * sizeof(struct date));
    c = (char *)ptr;
    // поле записи считываем посимвольно из файла
    while ((i = getc(fd)) != EOF)
    {
        *c = i;
        c++;
    }
    // перебор загруженных элементов и вывод на консоль
    printf("\n%d date in the file stored\n\n", n);
    for (int i = 0; i < n; i++)
        printf("%-5d %5d %-20s %5d\n", i + 1, (ptr + i)->day, (ptr + i)->month, (ptr + i)->year);
    free(pti);
    free(ptr);
    fclose(fd);
    return 0;
}

int find(char *filename)
{
    FILE *fd;
    char *c;
    int m = sizeof(int);
    int n, i;
    // выделяем память для количества данных
    int *pti = (int *)malloc(m);
    if ((fd = fopen(filename, "r")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    // считываем количество структур
    c = (char *)pti;
    while (m > 0)
    {
        i = getc(fd);
        if (i == EOF)
            break;
        *c = i;
        c++;
        m--;
    }
    // получаем число элементов
    n = *pti;
    // выделяем память для считанного массива структур
    struct date *ptr = (struct date *)malloc(n * sizeof(struct date));
    c = (char *)ptr;
    // поле записи считываем посимвольно из файла
    while ((i = getc(fd)) != EOF)
    {
        *c = i;
        c++;
    }
    printf("-----Search and display date with summer month----\n");
    for (int i = 0, j = 1; i < n; i++)
        if (((ptr + i)->month) == "June" || ((ptr + i)->month) == "July" || ((ptr + i)->month) == "August")
            printf("%-5d %5d %-20s %5d\n", j++, (ptr + i)->day, (ptr + i)->month, (ptr + i)->year);
    free(pti);
    free(ptr);
    fclose(fd);
    return 0;
}
