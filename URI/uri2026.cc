#include<iostream>
#include<cstdio>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w]
                        = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}
int main()
{
    int test,N,W,c=1;
    cin>>test;
    while(test--)
    {
        cin>>N;
        int val[N],wt[N];
        cin>>W;
        for(int i=0;i<N;i++)
            cin>>val[i]>>wt[i];
        printf("Galho %d:\n",c);
        printf("Numero total de enfeites: %d\n\n",knapSack(W,wt,val,N));
        c++;
    }
    return 0;
}
