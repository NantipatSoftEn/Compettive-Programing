#include<stdio.h>
int main()
{
      char name[100];
      double salary,sold,total,sm,i,j;
            while(scanf("%s %lf %lf",name,&salary,&sold)==3){
                         i=(sold*15)/100;
                         total=salary+i;
                         printf("TOTAL = R$ %.2lf\n",total);
            }
}
