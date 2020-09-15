#include <conio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;
 
 
class lu
{
 
private:
    int n;
    double A[4][4];
    double B[4];
    double L[4][4], U[4][4], X[4], Y[4];
    public:
        void mm();
        void rozklad();
        void pryam();
        void zvorot();
        void vuvid();
};
void lu::mm()
{
    int n=4;
    double A[4][4]={{8.3, 2.62, 4.1, 1.9}, {3.92, 8.45, 7.78, 2.46}, {3.77, 7.21, 8.04, 2.28}, {2.21, 3.65, 1.69, 6.69}};
    double B[4]={-10.65, 12.21, 15.45, -8.35};
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        { L[i][j]=0; U[i][j]=0;}
}
void lu::rozklad()
{
//Сам метод
        for (int k=0; k<n; k++)
        {
            U[k][k]=1;
            for (int i=k; i<n; i++)
            {
                for (int m=0; m<=k-1; m++)
                    L[i][k]+=L[i][m]*U[m][k];
                L[i][k]=A[i][k]-L[i][k];
            }
            for (int j=k+1; j<n; j++)
            {
                for (int m=0; m<=k-1; m++)
                    U[k][j]+=L[k][m]*U[m][j];
                U[k][j]=(A[k][j]-U[k][j])/L[k][k];
            }
        }
}
void lu::pryam()
{
//Прямой ход
        for (int i=0; i<n; i++)
            Y[i]=0;
        Y[0]=B[0]/L[0][0];
        for (int i=1; i<n; i++)
        {
            for (int m=0; m<=i-1; m++)
                Y[i]+=L[i][m]*Y[m];
            Y[i]=(B[i]-Y[i])/L[i][i];
        }
}
void lu::zvorot()
{
//обратный ход
        for (int i=0; i<n; i++)
            X[i]=0;
        X[n-1]=Y[n-1];
        for (int i=n-2; i>=0; i--)
        {
            for (int m=i+1; m<n; m++)
                X[i]+=U[i][m]*X[m];
            X[i]=Y[i]-X[i];}
}       
void lu::vuvid()
{
//вывод результата
        for(int i=0; i<n; i++)
            cout<< "1" << X[i]<<endl;
        
}
 
int main()
{ lu F;
F.mm();
F.rozklad();
F.pryam();
F.zvorot();
F.vuvid();
getch();
return 0;
}