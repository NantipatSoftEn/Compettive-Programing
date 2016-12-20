
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int ar[m][n];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>ar[i][j];
        }
    }
    int ar2[m][n];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>ar2[i][j];
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << ar[i][j]+ar2[i][j] <<" ";
        }
        cout <<endl;
    }

    return 0;
}
