#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    float x[2],y[2];
    cin>>x[0]>>y[0]>>x[1]>>y[1];
    printf("%.4f\n",sqrt((x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0])));

}
