#include <stdio.h>
#include <math.h>
int main(){
double a, b, c;

scanf("%lf %lf",&a,&b);
c = pow((a*a+b*b),0.5);

printf("%.6lf",c);

return 0;
}
