#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long int  factorial(unsigned long long int n)
{

    if(n <= 1)
      return 1;
    else
     return n*factorial(n-1);
}
int main ()
{
    unsigned long long int x,y;

    while(cin>>x>>y)
    {
         cout << factorial(x)+factorial(y)<<endl;
    }

    return 0;
}
