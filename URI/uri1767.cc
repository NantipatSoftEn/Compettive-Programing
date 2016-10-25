#include <bits/stdc++.h>
using namespace std;

int m[105][55];

int main() {
	int n, pac, qt[105], p[105], peso, usados;

	scanf( "%d", &n );
	while( n-- ) {
		scanf( "%d", &pac );
		for( int i=1; i<=pac; i++ )
			scanf( "%d%d", &qt[i], &p[i] );

		for( int i=1; i<=50; i++ ) {
			m[0][i] = 0;
			for( int j=1; j<=pac; j++ ) {
				if( i-p[j] < 0 )
					m[j][i] = m[j-1][i];
				else
					m[j][i] = max( m[j-1][i], m[j-1][ i-p[j] ] + qt[j] );
			}
		}
		usados = peso = 0;
		int i = 50;
		for( int j=pac; j>=1; j-- )
			if( m[j][i] != m[j-1][i] )
				usados++, peso += p[j], i -= p[j];

		printf( "%d brinquedos\nPeso: %d kg\nsobra(m) %d pacote(s)\n\n", m[pac][50], peso, pac-usados );
	}

	return 0;
}
