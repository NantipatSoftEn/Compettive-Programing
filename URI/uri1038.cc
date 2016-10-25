#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int x,y,c;
    cin>>x >>y;
    if(x==1)
        c=4.00;
    else if(x==2)
        c=4.50;
    else if(x==3)
        c=5.00;
    else if(x==4)
        c=2.00;
    else if(x==5)
        c=1.50;
    printf("Total: R$ %.2f\n",(float)c*y);

    return 0;
}
