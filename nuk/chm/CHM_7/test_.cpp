/*****************************************************************************
**  РАСЧЁТ КОЭФФИЦИЕНТОВ ДЛЯ КРИВЫХ ПЕРВОЙ , ВТОРОЙ И ТРЕТЬЕЙ СТЕПЕНИ       **
**                 МЕТОДОМ НАИМЕНЬШИХ КВАДРАТОВ                             **
*****************************************************************************/
#include<conio.h>
#include<math.h>
#include<iostream>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void LinealAproks()
 {
  double a,b,x,y;
  char choice=0;
  int n=0;
  double c=0;
  double d=0;
  double e=0;
  double f=0;
  cout<<"Метод наименьших квадратов для линейной аппроксимации.\n";
  cout<<"Зависимость следующего вида: y=a+bx,\n";
  cout<<"где 'a' и 'b'- искомые коэффициенты.\n\n";
  cout<<"Введите последовательно значения 'x' и 'y'\n";
  while(choice!=27)
   {
    n++;
    cout<<"x=";cin>>x;
    cout<<"y=";cin>>y;
    cout<<"если это всё,то ESC;если нет-ENTER\n";
    c+=x;
    d+=x*x;
    e+=x*y;
    f+=y;
    b=((n*e)-(c*f))/((n*d)-(c*c));//итоговые формулы
    a=(e-(d*b))/c;
    choice=getche();
   }
  cout<<"коэффициенты получились следующие:\n";
  cout<<"a="<<a<<"\n";
  cout<<"b="<<b<<"\n\n";
  cout<<"Для выхода нажмите любую клавишу.";
  getch();
 }
void QadratAproks()
 {
  double a,aa,b,bb,c,cc,d,x,y,A,B,C,D,E;
  char choice=0;
  int n=0;
  double z=0;
  double f=0;
  double q=0;
  double k=0;
  double l=0;
  double p=0;
  double s=0;
  cout<<"Метод наименьших квадратов для квадратичной аппроксимации.\n";
  cout<<"Зависимость следующего вида: y=a+bx+сx,\n";
  cout<<"где 'a','b','c'- искомые коэффициенты.\n\n";
  cout<<"Введите последовательно значения 'x' и 'y'\n";
  while(choice!=27)
   {
    n++;
    cout<<"x=";cin>>x;
    cout<<"y=";cin>>y;
    cout<<"если это всё,то ESC;если нет-ENTER\n";
    z+=x;//обозначения сумм
    f+=x*x;
    q+=x*x*x;
    k+=x*x*x*x;
    l+=y;
    p+=y*x;
    s+=y*x*x;
    A=(n*s)-(f*l);//промежуточные вычисления
    B=(f*n)-(z*z);
    C=(p*n)-(l*z);
    D=(q*n)-(f*z);
    E=(n*k)-(f*f);
    aa=(z*f*l)+(p*n*f)+(s*n*z);
    bb=(z*z*f)+(n*f*f)+(q*n*z);
    cc=(z*f*f)+(q*n*f)+(k*n*z);
    c=((A*B)-(C*D))/((E*B)-(D*D));//итоговые формулы
    b=(C-(D*c))/B;
    a=(aa-(bb*b)-(cc*c))/(3*n*z*f);
    choice=getche();
   }
  cout<<"коэффициенты получились следующие:\n";
  cout<<"a="<<a<<"\n";
  cout<<"b="<<b<<"\n";
  cout<<"c="<<c<<"\n\n";
  cout<<"Для выхода нажмите любую клавишу.";
  getch();
 }

int main()
 {
  char choice=0;
  while(choice!=27)
   {
    printf("Выбрать:\n");
    printf("Закончить работу...................ESC\n");
    printf("Линейная аппроксимация..............1\n");
    printf("Квадратичная аппроксимация..........2\n");
    printf(">");
    choice =getche();
    switch(choice)
     {
      case '1':LinealAproks();break;
      case '2':QadratAproks();break;
     }
   }
   return 0;
 }






