
#include<stdio.h>
#include<iostream>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{

   if (n == 0 || W == 0)
       return 0;
   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1)
                  );
}

// Driver program to test above function
int main()
{
    while(1)
    {
        int N;
        cin>>N;
        if(N==0) break;
        int W;
        cin>>W;
        int val[N],wt[N];
        for(int i=0;i<N;i++)
        {
            cin>>val[i];
            cin>>wt[i];
        }
        int n = sizeof(val)/sizeof(val[0]);
        printf("%d min.\n", knapSack(W, wt, val, n));
    }

    return 0;
}
