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
#define p cout
#define s cin
#define pi 2*acos(0.0)
#define fuck INT_MAX
using namespace std;
void ch(int i,int j,int a[100][100],int N)
{
 if(a[i-2][j+1]==fuck && i-2>=1 && j+1<=N)
    a[i-2][j+1]=a[i][j]+1;

 if(a[i-2][j-1]==fuck && i-2>=1 && j-1>=1)
    a[i-2][j-1]=a[i][j]+1;

 if(a[i+2][j+1]==fuck && i+2<=N && j+1<=N)
    a[i+2][j+1]=a[i][j]+1;

if(a[i+2][j-1]==fuck && i+2<=N && j-1>=1)
     a[i+2][j-1]=a[i][j]+1;

 if(a[i-1][j+2]==fuck && i-1>=1 && j+2<=N)
   a[i-1][j+2]=a[i][j]+1;

 if(a[i-1][j-2]==fuck && i-1>=1 && j-2>=1)
    a[i-1][j-2]=a[i][j]+1;

 if(a[i+1][j+2]==fuck && i+1<=N && j+2<=N)
    a[i+1][j+2]=a[i][j]+1;

 if(a[i+1][j-2]==fuck && i+1<=N && j-2>=1)
    a[i+1][j-2]=a[i][j]+1;

}
int main()
{
	int N,M,P;
	short number1,number2;
	
	while(1)
	{
		s >> N >> M >> P;
		if(N==0 && M==0 && P==0)
			break;
		int a[100][100];
		
		vector<pair<int,int> > v ;
		v.push_back(make_pair(0,0));
		
		vector<pair<int,int> > v1 ;
		v1.push_back(make_pair(0,0));
		
		for(short i=0;i<=M;i++)
		{
			s >> number1 >> number2;
			v.push_back(make_pair(number1,number2));
		}
	
		for(short i=0;i<P;i++)
		{
			s >> number1 >> number2;
			v1.push_back(make_pair(number1,number2));
		}
	
		for(short i=1;i<=N;i++)
		{
			for(short j=1;j<=N;j++)
			{
				if(v[1].first==i && v[1].second==j)
						a[i][j]=0;
				else  a[i][j]=fuck;
			}
		}
		
		
		for(int k=0;k<=N;k++) 
		{                
    		for(int i=1;i<=N;i++)   
			{
     			for(int j=1;j<=N;j++) 
     			{
					if(a[i][j]==k)
						ch(i,j,a,N);
   				}
    		}
		}
		for(int i=1;i<=M;i++)  
			a[v[i].first][v[i].second]=-1;
			
    	for(int i=1;i<v1.size();i++)
    	{
        		cout << a[v1[i].first][v1[i].second]<<endl;
    	}
		
	}

	


}