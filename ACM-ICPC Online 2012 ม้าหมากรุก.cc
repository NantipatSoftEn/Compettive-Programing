#include<iostream>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<string>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<climits>
#include <utility> 
#define ll long long
#define pf cout
#define s cin
#define e endl
#define q <<
#define p >>
#define pi 2*acos(0.0)
#define fuck INT_MAX
using namespace std;
int ch(int i,int j,int a[100][100],short maxi,short maxj)
{
	int count=0;
	if(a[i-1][j]==0 && i-1>=0 )
	{
		count++;
	
	}
	if(a[i+1][j]==0  && i+1<=maxi )
	{
		count++;
	
	}
	if(a[i][j-1]==0  && j-1>=0 )
	{
		count++;

	}
	if(a[i][j+1]==0  && i-1<=maxj )
	{
		count++;

	}
	
	return count;
		
}
short ch1(int i,int j,int a[100][100],short maxi,short maxj)
{
	int count=0;
	if(a[i-1][j]==1 && i-1>=0 )
	{
		count++;
	
	}
	if(a[i+1][j]==1  && i+1<=maxi )
	{
		count++;
	
	}
	if(a[i][j-1]==1  && j-1>=0 )
	{
		count++;

	}
	if(a[i][j+1]==1  && i-1<=maxj )
	{
		count++;
	}

	if(count==4)
		return  1;
	else return 0;
	
}
int main()
{	
	while(1)
	{
		short N,M;
		cin >> N >> M;
		if(N==0 && M==0)
			break;
		int a[100][100];
		char mes;
		for(short i=0;i<N;i++)
		{
			for(short j=0;j<M;j++)
			{
				cin >> mes;
				if(mes=='H')
					a[i][j]=1;
				else if(mes='.')
					a[i][j]=0;
					
			}
		}
		int sum=0;
		for(short i=0;i<N;i++)
		{
			for(short j=0;j<M;j++)
			{
				if(a[i][j]==1)
					sum=sum+ch(i,j,a,N,M);
			}
		}
		short sum1=0;
		for(short i=0;i<5;i++)
		{
			for(short j=0;j<5;j++)
			{
				if(a[i][j]==0)
					sum1=sum1+ch1(i,j,a,N,M);
			}	
		}
		cout << sum-(sum1*4)<<endl;
	}
}
