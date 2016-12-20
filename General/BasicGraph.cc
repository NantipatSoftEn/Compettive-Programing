#include<iostream>
#include <vector>
#include <map>
#include <utility>


using namespace std;
void  AdjacencyMat()
{
	int V;
	cin >>V;
	int weight[V][V];
	for(unsigned int m=0;m<V;m++)
			for(unsigned int k=0;k<V;k++)
			{
				cout << "m="<<m<<" k="<<k<<" weight=";
				cin >> weight[m][k];
			}
			/*
			3
			weight[0][0]=10
			weight[0][1]=11
			weight[0][2]=12
			
			weight[i][j]=n i>0,j>0 
			*/			
}
void  AdjacencyMatV2()
{
	int V, E;
  	cin >> V >> E;  // Read a number of vertices and edges
 	int weight[V][V];
  	for (unsigned int e = 0; e < E; e++)
  	{
    	int i, k, w;
   	 	cin >> i >> k >> w;
    	weight[i][k] = w;
	}
	/*
	2 3
	0 1 2
	0 2 3
	1 2 5
	*/
	
}
void AdjacencyList()
{
	int V, E;
  	cin >> V;
	vector<pair<int, int> > edges[V]; 
	for (int v = 0; v < V; v++)
  	{
    	cin >> E;	
    	for (int e = 0; e < E; e++)
    	{
      		int k, w;
     	 	cin >> k >> w;
     		edges[v].push_back(make_pair(k, w));
    	}
  	}
  	/*
  	0:(1,10),(2,10)
  	1:(0,10).(2,30)
  	2:(0,30),(1,20)
  	
  	vector<pair<int, int> >  can't use so long
  	*/
}
void AdjacencyListV2()
{
	int V, E;
  	cin >> V >> E;
	map<int, int> edges;
	 for (int v = 0; v < V; v++)
  	{	
    	cin >> E;
    	for (int e = 0; e < E; e++)
    	{
     	 int k, w;
	     cin >> k >> w;
		 //edges[v][k] = w;
    	}
  	}
  /*
	  STL Map takes  O( N log N)   faster
*/
}
void AdjacencyListV3()
{
	int V, E;
  	cin >> V >> E;
  	vector<int> edges[V]; // Un-weighted Adjacency List

  	for (int v = 0; v < V; v++)
  	{
  	  	cin >> E;
   	 	for (int e = 0; e < E; e++)
    	{
      		int k;
      		cin >> k;
      		edges[v].push_back(k);
	  	}
  	}
  	/*
  		3 3 
  		2 1 2
  		2 0 2
  		2 0 1
	*/
}
void EdgeList()
{
	int E;
	cin >>E;
	vector<pair<int,int> > edge;
	for (int e = 0; e < (E*2); e++)
	{
		int a,b;
		cin >>a>>b;
		edge.push_back(make_pair(a,b));
	}
	/*
	3
	0:0 1
	1:0 2 
	2:1 0
	3:1 2
	4:2 1
	5:2 0
	*/
}
int main()
{
	;
}

