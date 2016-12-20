#include<iostream>
using namespace std;
int main()
{
	int N;

	while(1)
	{
		cin >> N;
		if(N==0)
			break;
		int ar[N];
		for(int i=0;i<N;i++)
			cin >> ar[i];
			
		int maxend=0,maxfar=0;
		for(int i=0;i<N;i++)
		{
			maxend+=ar[i];
			if(maxend<0)
				maxend=0;
			if(maxfar<maxend)
				maxfar=maxend;
		}
		if(maxfar<=0)
			cout <<"Losing streak."<<endl;
		else cout <<"The maximum winning streak is "<<maxfar<<"."<<endl;
	}
}