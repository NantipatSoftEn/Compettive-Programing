#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    double x,y,z;
    cin>>x>>y>>z;

    printf("TRIANGULO: %.3lf\n",0.5*x*z);
    printf("CIRCULO: %.3lf\n",(z*z)*3.14159);
    printf("TRAPEZIO: %.3lf\n",0.5*z*(x+y));
    printf("QUADRADO: %.3lf\n",y*y);
    printf("RETANGULO: %.3lf\n",x*y);


    return 0;
}
