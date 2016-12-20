#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int median(int ar[],int start,int ends)
{
    int length=ends-start+1;
    int media=0;
    if(length%2!=0)
        media=ar[start+length/2];
    else
        media=(ar[start+length/2-1]+ar[start+length/2])/2;

    return media;
}
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++) cin>>ar[i];
    sort(ar,ar+n);
    printf("%d\n",median(ar, 0, n / 2 - 1));
    printf("%d\n",median(ar, 0, n - 1));
    if (n % 2 == 0)
        printf("%d\n",median(ar, n / 2, n - 1));
    else
        printf("%d\n",median(ar, n / 2 + 1, n - 1));
}
