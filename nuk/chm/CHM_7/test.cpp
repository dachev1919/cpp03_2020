#include <iostream> 
using namespace std;

int main(){
    double i;
    i = (5.0 * 51.0 - (20.0 * 15.0)) / (5.0 * 114.0 - 20.0 * 20.0);
    double sY, sX, n, o;
    n = 5;
    sY = 15;
    sX = 20;
    o = (sY - i * sX) / n;
    printf("%lf", o);
    return 0;
}