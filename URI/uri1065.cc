#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int ar[6],c=0;
    for(int i=1;i<=5;i++)
    {
        cin>>ar[i];
        if(ar[i]%2==0)
            c++;
    }
    cout << c <<" valores pares"<<endl;
    return 0;
}
