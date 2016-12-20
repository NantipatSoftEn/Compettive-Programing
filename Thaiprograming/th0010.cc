#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    char str[50];
    scanf("%s",str);
    int  ar[]= {1,0,0};
    int i=0;
    while(str[i])
    {
        if(str[i]=='A' && ar[0]==1 && ar[1]==0)
        {
            ar[0]=0;
            ar[1]=1;
        }
        else if(str[i]=='A' && ar[0]==0 && ar[1]==1)
        {
            ar[0]=1;
            ar[1]=0;
        }
        else if(str[i]=='B' && ar[1]==0 && ar[2]==1)
        {
            ar[1]=1;
            ar[2]=0;
        }
        else if(str[i]=='B' && ar[1]==1 && ar[2]==0)
        {
            ar[1]=0;
            ar[2]=1;
        }
        else if(str[i]=='C' && ar[0]==1 && ar[2]==0)
        {
            ar[0]=0;
            ar[2]=1;
        }
        else if(str[i]=='C' && ar[0]==0 && ar[2]==1)
        {
            ar[0]=1;
            ar[2]=0;
        }
        i++;
    }
    if(ar[2]==1)
        cout <<"3\n";
    else if(ar[0]==1)
        cout <<"1\n";
    else  cout <<"2\n";

    return 0;
}

