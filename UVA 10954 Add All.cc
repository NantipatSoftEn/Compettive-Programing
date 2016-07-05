#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N,x;
	 while(1)
	 { 
	 	priority_queue<int,vector<int>,greater<int> > q;
	 	int sumcost=0;
		cin >> N;
		if(N==0)
			break;
	 	for(int i=0;i<N;i++)
	 	{
	 		cin >> x;
	 		q.push(x);
		}
		for(int i=0;i<N-1;i++)
	 	{
	 		int temp=q.top();
	 	
	 		q.pop();
	 		int temp2=q.top();
	 
	 		q.pop();
	 		int cost=temp+temp2;
	 	
	 		q.push(cost);
	 		sumcost=sumcost+cost;
	 	
	 
		}
		cout << sumcost << endl;
		
	 }
    exit(EXIT_SUCCESS);
}