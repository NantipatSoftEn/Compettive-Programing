#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int  x,y;
	cin>> x>>y;
	int  ar[x+1]={0},a,b,temp,sumall=0;
	char c;
	while(y--)
	{
		
		cin >>c>>a>>b;
		if(c=='P')
		{
			temp=ar[b];
			ar[b]=a;
			if(temp>ar[b])
				ar[b]=temp;
		}

	}
		for(int i=0;i<=x;i++)
		{
			cout <<ar[i]<<" ";
		}

}
