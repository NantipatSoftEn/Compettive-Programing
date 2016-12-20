
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int N;
   cin>>N;
   int ar[N];
   for(int i=0;i<N;i++)
        cin>>ar[i];
   sort(ar,ar+N);
   cout << ar[0]<<endl;
   cout << ar[N-1]<<endl;
   return 0;
}
