#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int r=a+b+c;
    if(r>=80 && r<=100)
        cout <<"A\n";
    else if(r>=75 && r<=79)
        cout <<"B+\n";
    else if(r>=70 && r<=74)
        cout <<"B\n";
    else if(r>=65 && r<=69)
        cout <<"C+\n";
    else if(r>=60 && r<=64)
        cout <<"C\n";
    else if(r>=55 && r<=59)
        cout <<"D+\n";
    else if(r>=50 && r<=54)
        cout <<"D\n";
    else if(r>=0 && r<=49)
        cout <<"F\n";
    return 0;
}
