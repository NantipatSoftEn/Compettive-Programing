#include<cstdio>
#include<iostream>
using namespace std;
int is_prime(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    if(n%2==0)
        return 0;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
            return 0;
        return 1;

    }
}
int main()
{
    cout <<is_prime(999999);
    return 0;
}
