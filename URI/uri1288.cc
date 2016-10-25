#include <bits/stdc++.h>
using namespace std;

int main() {
    int teste, N, W, R, val[55], wt[55], memo[55][105];

	scanf( "%d", &teste );
	while( teste-- ) {
		scanf( "%d", &N );
		for( int i = 1; i <= N; i++ )
			scanf( "%d%d", &val[i], &wt[i] );
		scanf( "%d%d", &W, &R );
	
		for( int W_i = 0; W_i <= W; W_i++ ) {
			memo[0][W_i] = 0;
			for( int i = 1; i <= N; i++ ) {
				if( wt[i] > W_i )
					memo[i][W_i] = memo[i-1][W_i];
				else
					memo[i][W_i] = max( memo[i-1][W_i], memo[i-1][ W_i - wt[i] ] + val[i] );
			}
		}
		printf( "%s\n", memo[N][W] >= R ? "Missao completada com sucesso" : "Falha na missao" );
	}

    return 0;
}
