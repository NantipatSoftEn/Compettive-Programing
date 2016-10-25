#include<stdio.h>
#include<math.h>
int main()
{
    int  N;
    scanf("%d",&N);
    for(int i=2;i<=N;i+=2)
    {
        printf("%d^2 = %llu\n",i,(long long  unsigned int)pow(i,2));
    }
    return 0;
}
