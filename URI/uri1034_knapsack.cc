#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int memo[10000][10000];
int main() {

    int test,N,W;
    cin>>test;
    while(test--)
    {
        cin>>N>>W;
        int wt[N+1],val[N+1];
        for(int i=1;i<=N;i++)
        {
            cin>>val[i];
            wt[i]=val[i];
        }
        for(int i=1;i<=W;i++)
        {
            memo[0][i]=0;
            for( int j=1; j<=N; j++ )
                if( i-wt[j] < 0 )
					memo[j][i] = memo[j-1][i];
				else
					memo[j][i] = max( memo[j-1][i], memo[j-1][ i-wt[j] ] + val[j] );
        }
        cout <<"Fuck="<<memo[N][W];
        int  cont=0;
        int wt_count = 0;
		for( int j=N; j>=1; j-- )
			if( memo[j][W] != memo[j-1][W] )
            {
                cont++;
                wt_count  += wt[j];
                W -= wt[j];
            }


		printf("peso=%d",cont);
    }
	return 0;
}
