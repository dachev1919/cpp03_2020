#include <iostream>
#include <fstream>
using namespace std;
struct Date
{
    int day;
    char month[20];
    int year;
};

void getInfo(Date *date);
void setInfo(Date *date, int n);
void del(const char *filename);
int main()
{
    const char *filename = "f.dat";
    Date *date;
    int n;
    cout << "N: ";
    cin >> n;
    setInfo(date, n);
    getInfo(date);
    del(filename);
    return 0;
}

void del(const char *filename)
{
    FILE *f;
    FILE *temp;
    temp = fopen("temp", "wb");
    fclose(temp);
    remove(filename);
    rename("temp", filename);
}
void getInfo(Date *date)
{
    Date d;
    fstream f("f.dat", ios::in);
    int i = 1;
    do
    {
        f >> d.day;
        f >> d.month;
        f >> d.year;
        if (f.eof())
            break;
        cout << i++ << ". " << d.day << " " << d.month << " " << d.year << "\n";
    } while (!f.eof());
    f.close();
}
void setInfo(Date *date, int n)
{
    fstream f("f.dat", ios::out);
    date = new Date[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Day: ";
        cin >> date[i].day;
        cout << "Month: ";
        cin >> date[i].month;
        cout << "Year: ";
        cin >> date[i].year;
    }
    for (int i = 0; i < n; i++)
    {
        f << date[i].day;
        f << "\n";
        f << date[i].month;
        f << "\n";
        f << date[i].year;
        f << "\n";
    }
    f.close();
}