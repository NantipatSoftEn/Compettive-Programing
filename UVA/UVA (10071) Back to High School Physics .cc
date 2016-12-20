#include <stdio.h>
#include <stdlib.h>

int main()
{
       int  v,t;
	while(scanf("%d %d",&v,&t) != EOF)
	{
	    printf("%d\n",2*(v*t)); 
	}
    exit(EXIT_SUCCESS);
}