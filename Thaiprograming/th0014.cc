#include <cstdio>
#include<iostream>
using namespace std;
int  gcdr ( int a, int b )
{
  if ( a==0 )
  	return b;
  return gcdr ( b%a, a );
}
int main()
{
    int a,b;
    cin >> a >> b;
    cout << gcdr(a,b)<<endl;

    return 0;
}
