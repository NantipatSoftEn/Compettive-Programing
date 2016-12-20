#include<cstdio>

long ct=0,vi[1000000]= {0},x;
int main()

{

    scanf("%d",&x);
    for(long c=2; c<=x; c++)if(vi[c]==0)
    {
            ct++;
            for(long d=2; c*d<=x; d++)
                vi[c*d]=1;
            if(ct==10001)
                break;

    }

    printf("%ld\n",ct);
    return 0;

}
