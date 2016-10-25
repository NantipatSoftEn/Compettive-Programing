#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int a[2],b[2];
    double c[2];
    cin>>a[0]>>b[0]>>c[0];
    cin>>a[1]>>b[1]>>c[1];
    printf("VALOR A PAGAR: R$ %.2lf\n",(b[0]*c[0])+(b[1]*c[1]));

    return 0;
}
