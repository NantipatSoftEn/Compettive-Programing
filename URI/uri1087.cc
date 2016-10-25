#include <iostream>
#include <cstdio>
using namespace std;
int ar[9][9];
void fuck(int i,int j)
{
    ar[i][j]=2;
    for(int x=0; x<=8; x++)
    {
        if(ar[i+x][j]==0 && i+x<=8)
            ar[i+x][j]++;
        if(ar[i-x][j]==0 && i-x>=0)
            ar[i-x][j]++;
        if(ar[i][j-x]==0 && j-x>0)
            ar[i][j-x]++;
        if(ar[i][j+x]==0 && j+x<=8)
            ar[i][j+x]++;
        if(ar[i+x][j+x]==0 && i+x<=8 && j+x<=8)
            ar[i+x][j+x]++;
        if(ar[i-x][j+x]==0 && i-x>=0 && j+x<=8)
            ar[i-x][j+x]++;
        if(ar[i-x][j-x]==0 && i-x>=0 && j-x>=0)
            ar[i-x][j-x]++;
        if(ar[i+x][j-x]==0 && i-x>=0 && j-x>=0)
            ar[i+x][j-x]++;
    }
}
int main ()
{
    int x_1,y_1,x_2,y_2;
    while(1)
    {
        cin>>x_1>>y_1>>x_2>>y_2;
        for(int i=1; i<=8; i++)
            for(int j=1; j<=8; j++)
                ar[i][j]=0;
        if(x_1==0 && y_1==0 && x_2==0 && y_2==0)
            break;
        fuck(1,1);
        if(ar[x_2][y_2]==2)
            cout <<"0"<<endl;
        else if(ar[x_2][y_2]==1)
            cout << "1"<<endl;
        else
            cout <<"2"<<endl;
    }

    return 0;
}
