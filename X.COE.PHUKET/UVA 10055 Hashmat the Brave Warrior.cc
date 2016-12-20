#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned long long a,b;
    while(scanf("%llu %llu",&a,&b) != EOF){
        if(a>b)
            printf("%llu\n",a-b);
        else
            printf("%llu\n",b-a);
    }
    exit(EXIT_SUCCESS);
}