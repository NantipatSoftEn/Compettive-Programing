#include<stdio.h>
int main()
{
      int a,b;
            while(scanf("%d %d",&a,&b)==2){
                       if(b%a==0)
                              printf("Sao Multiplos\n");
                        else
                              printf("Nao sao Multiplos\n");
            }
}
