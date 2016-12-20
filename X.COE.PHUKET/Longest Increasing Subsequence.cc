#include<iostream>	
#include<algorithm>
using namespace std;
int main()
{
	int ar[1000],i=0;
	while(1)
	{
		cin >> ar[i];
		if(ar[i]==0)
			break;
		i++;
	}
	int count=0;
	sort(ar,ar+i);
	for(int j=0;j<i;j++)
	{
		if(ar[j]!=ar[j+1] )
			count++;
	}
	cout << count;
		
}
