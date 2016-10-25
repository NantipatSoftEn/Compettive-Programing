#include<stdio.h>
#include<math.h>
int main()
{
            int r;
            double pi=3.14159,a,b,c;
            while( scanf("%d",&r)==1){
                  a=4/3.0;
                  b=pow(r,3);
                  c=a*b*pi;
                  printf("VOLUME = %.3lf\n",c);

            }
}
