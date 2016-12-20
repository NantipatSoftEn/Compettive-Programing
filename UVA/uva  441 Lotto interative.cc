#include <cstdio>
using namespace std;
int main() {
	int k, S[12], count = 0;
	while (scanf("%d", &k), k)
	 {
		if (count++)
			printf("\n");
			
		for (int i = 0; i < k; i++)
			scanf("%d", &S[i]);
			
		for (int a = 0; a < k - 5; a++)
			for (int b = a + 1; b < k - 4; b++)
				for (int c = b + 1; c < k - 3; c++)
					for (int d = c + 1; d < k - 2; d++)
						for (int e = d + 1; e < k - 1; e++)
							for (int f = e + 1; f < k; f++)
								printf("%d %d %d %d %d %d\n", S[a], S[b], S[c],
										S[d], S[e], S[f]);
	}
}					
					/* s=7 ,k=6 ={0,1,2,3,4,5} : k-5=1  
					a=0 k=1  1 2 3 4 5 6
					b=1 k=2  1 2 3 4 5 
					c=2 k=3
					d=3 k=4
					e=4 k=5
					f=5 k=6
					*/
