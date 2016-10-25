#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int ar[3];
    cin>> ar[0]>>ar[1]>>ar[2];
    sort(ar,ar+3);
    for(int i=0;i<3;i++)
        cout <<  ar[i]<<endl;
    cout << endl <<endl;
    for(int i=3;i>0;i--)
        cout <<  ar[i]<<endl;
    return 0;
}
