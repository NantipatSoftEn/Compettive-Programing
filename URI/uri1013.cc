#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

   int x[3];
   cin>>x[0]>>x[1]>>x[2];
   sort(x,x+3);
   printf("%d eh o maior\n",x[2]);

}
