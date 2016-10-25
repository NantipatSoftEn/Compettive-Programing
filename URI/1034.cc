#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int n, m, bloco[30], rg[1000005];

int main() {
    int t;

    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d%d", &n, &m );
        for( int i = 0; i < n; i++ )
            scanf( "%d", &bloco[i] );


        rg[0] = 0;

        for( int i = 1; i <= m; i++ ) {
            rg[i] = INF;
            for( int j = 0; j < n; j++ )
                rg[i] = min( rg[i], 1 + ( i - bloco[j] < 0 ? INF : rg[ i - bloco[j] ] ) );
        }

        printf( "%d\n", rg[m] );
        for( int i = 0; i <= m; i++ )
        {
            cout <<"m="<< i<<" ";
            for( int j = 0; j < n; j++ )
            {
                cout << rg[j]<<" ";
            }
            cout <<endl;
        }
    }




    return 0;
}
