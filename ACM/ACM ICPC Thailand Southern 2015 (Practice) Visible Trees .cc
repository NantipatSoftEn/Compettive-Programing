#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
	short N,T,number,K=1;
	cin >> N;	
	while(N--)
	{
		vector<int > x;
		cin >> T;
		while(T--)
		{
			cin >>  number;
			x.push_back(number);
		}
	short S=x.size()-1,n=1,count=1,i=x.size()-1,t=0 ;
	while(t<i)
	{
		if(x[S] < x[S-n])
		{
			S=S-n;
			n=0;
			count++;
		}
		else if(x[S] == x[S-n] && S>0 )
		{
			t--;
			n++;
			if(n>S)
				break;
		}		
		else {
			n++;
			if(n>S)
				break;
		}
		t++;
	}
	printf("Case %d: %d\n",K,count);
	K++;
	}

	
}	
