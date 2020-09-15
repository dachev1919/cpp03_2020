#include <math.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <time.h>

using namespace std;

#define e 0.00001;

double Func(double x){
    return x * x + 4 * sin(x);
}

double Fp(double x, double E){
    return (Func(x+E/2)+Func(x-E/2))/E;  //производная
}

int main(){
    double a, b, X, E;
    int ii;
    printf("-x^2+4*sin(x)\na=");
    scanf("%lf", &a);
    printf("b=");
    scanf("%lf", &b);
    printf("e=");
    scanf("%lf", &E);
    printf("Metod resheniya?\n\t\t1)metod polovinnogo deleniya\n\t\t2)metod Newtona\n\t\t3)Prostih iteracyi\n");
    scanf("%i", &ii);
    system("cls");
    X = a;
    double Xt;
    int count = 0;
    clock_t start = clock();
    do
    {
        count++;
        Xt=X;
        if (ii==1) {
            X=(b+a)/2;
        } 
        else {
            if (ii==2) {
                X=-Func(X)/Fp(X,E)+X;
            } 
            else {
                if (ii==3) {
                    X=Func(X);
                    }
            } 
        }
        cout << "[" << count << "]=" << X << endl;
        if(Func(X) * Func(a) > 0) a = X;
        else b = X;
    } while(fabs(X - Xt) >= E);
    clock_t end = clock();
    cout << "X=" << X;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nRun time - " << seconds << endl;
    system("Pause");
    return 0;
}