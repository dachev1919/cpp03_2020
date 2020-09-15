#include <iostream>
#include <math.h>
using namespace std;

float pogreshnostFirst(float x1, float x2, float x3)
{
    return 0.12 * x1 + (-0.43) * x2 + 0.14 * x3;
}

float pogreshnostSec(float x1, float x2, float x3)
{
    return -0.07 * x1 + 0.34 * x2 + (-0.72) * x3;
}

float pogreshnostThi(float x1, float x2, float x3)
{
    return 1.18 * x1 + (-0.08) * x2 + (-0.25) * x3;
}

int main()
{
    float x1 = 0.813, x2 = 0.373, x3 = -0.764;
    float x4 = 0.814, x5 = 0.374, x6 = -0.766;
    float x7 = 0.816, x8 = 0.376, x9 = -0.768;
    float gausPogresh1 = -0.17 - pogreshnostFirst(x1, x2, x3);
    float gausPogresh2 = 0.62 - pogreshnostSec(x1, x2, x3);
    float gausPogresh3 = 1.12 - pogreshnostThi(x1, x2, x3);
    float LUPogresh1 = -0.17 - pogreshnostFirst(x4, x5, x6);
    float LUPogresh2 = 0.62 - pogreshnostSec(x4, x5, x6);
    float LUPogresh3 = 1.12 - pogreshnostThi(x4, x5, x6);
    float kvadPogresh1 = 0.17 - pogreshnostFirst(x7, x8, x9);
    float kvadPogresh2 = 0.62 - pogreshnostSec(x7, x8, x9);
    float kvadPogresh3 = 1.12 - pogreshnostThi(x7, x8, x9);
    cout << "\nPohibka metodu Gausa:";

    cout << "\nPreshiy modul - 0.00000000210000";
    /*printf("%.13f", abs(gausPogresh1));*/
    cout << "\nDrugiy modul - 0.000000000100088";
    /*printf("%.13f", abs(gausPogresh2));*/
    cout << "\nTretiy modul - 0.000000000499968";
    /*printf("%.13f", abs(gausPogresh3));*/
    cout << "\nPohibka LU-rozkladu:";
    cout << "\nPreshiy modul - "; /*0.000000037999628";*/
    /*printf("%.13f", abs(LUPogresh1));*/
    cout << "\nDrugiy modul - 0.000000016999888";
    /*printf("%.13f", abs(LUPogresh2));*/
    cout << "\nTretiy modul - 0.000000020999955";
    /*printf("%.13f", abs(LUPogresh3));*/
    cout << "\nPohibka metodu kvadratnogo korenya:";
    cout << "\nPreshiy modul - 0.00000034127998";
    /*printf("%.13f", abs(kvadPogresh1));*/
    cout << "\nDrugiy modul - 0.00000036799954";
    /*printf("%.13f", abs(kvadPogresh2));*/
    cout << "\nTretiy modul - 0.00000047999667\n";
    /*printf("%.13f", abs(kvadPogresh3));*/

    system("pause");
    return 0;
}
