#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t1,t2,n,F;
    cin>> t1>>t2>>n;
    if(n==1) cout << t1;
    else if(n==2) cout << t2;
    for(int i=0;i<=n;i++)
    {
        F=t1+t2*t2;
        t1=t2;
        t2=F;
    }
    cout << F;
}
