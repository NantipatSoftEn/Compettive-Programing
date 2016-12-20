#include<stdio.h>

int main()
{
    int m[9];
    int ans[9];
    int som[9];
    int i,sum,ch,keep,x;
    sum=0;


    for(i=0;i<9;i++)
    scanf("%d",&m[i]);

    for(i=0;i<9;i++)
    som[i]=m[i];

    for(i=0;i<9;i++)
    sum=sum+m[i];



    ch=sum-100;

     for(i=0;i<9;i++)
    ans[i]=0;

    for(i=0;i<8;i++)
    {
       for(x=i+1;x<9;x++)
       {
          keep=m[i]+m[x];
           if(keep==ch)
       {
           ans[i]++;
           ans[x]++;
       }
       }

    }


    for(i=0;i<9;i++)
    {
      if(ans[i]==0)
      printf("%d\n",som[i]);
      else {}
    }

}
