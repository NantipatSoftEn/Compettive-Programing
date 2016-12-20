#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
void IterativeDFSusingStack(vector<pair<int, int> >edges[],int V)
{
	stack<int> s;
	bool visited[V]={0};
	s.push(0); //start vertex
	
	while(!s.empty())
	{
		//cout <<"TOP="<<s.top()<<endl;
		int current_vertex=s.top(); //current_vertex=0,3,5
		
		s.pop(); 
		if(!visited[current_vertex]) // visited[0]
									 // visited[3]
									 // visited[5]
									 // visited[2]
									 // visited[1]
									 // visited[3]
									 // visited[2]
									 // visited[4]
									 //  all  true
			visited[current_vertex]=true; // visited[0]=true
										  // visited[3]=true
										  // visited[5]=true
										  // visited[2]=true
										  // visited[1]=true
										  // visited[4]=true
		else continue;
		
		cout << current_vertex << " "; // 0,3,5,2,1,4
		for(int i=0;i<edges[current_vertex].size();i++)  //edges[0]
		{												 //edges[3]
														 //edges[5]
														 //edges[2]
														 //edges[1]
														 //edges[4]
			int adjacent_vertex=edges[current_vertex][i].first; //adjacent_vertex=edges[0][0].first=1
			s.push(adjacent_vertex);							//adjacent_vertex=edges[0][1].first=3
																	//adjacent_vertex=edges[3][0].first=2
																	//adjacent_vertex=edges[3][1].first=4	
																	//adjacent_vertex=edges[3][2].first=5
																		//adjacent_vertex=edges[5][0].first=2
																			//adjacent_vertex=edges[2][0].first=1
																				//adjacent_vertex=edges[1][0].first=2
																				//adjacent_vertex=edges[1][1].first=3
																					//adjacent_vertex=edges[4][0].first=2
		}
	}
	/*
		s={1,3}
			s={1}
				s={1,2,4,5}
					s={1,2,4,1}
						s={1,2,4,2,3}
							s={1,2,4,2}
								s={1,2,4}
									s={1,2,}
										s={1}
											s={}
	*/
}
void inputIterativeDFSusingStack()
{
	int V, E;
  	cin >> V;
  	vector<pair<int, int> > edges[V];
  	for (int v = 0; v < V; v++)
  	{
   	 	cin >> E;
    	 for (int e = 0; e < E; e++)
   		 {
     		int k;
      		cin >> k;
			edges[v].push_back(make_pair(k, 0));
    	}
    }
    IterativeDFSusingStack(edges,V);
    /*
    6    		edges[6]
	E=2   1 3	edges[0][0].push_back(make_pair(1, 0));
				edges[0][1].push_back(make_pair(3, 0));
				
	E=2   2 3	edges[1][0].push_back(make_pair(2, 0));
				edges[1][1].push_back(make_pair(3, 0));
				
	E=1   1		edges[2][0].push_back(make_pair(2, 0));
	
	E=3   2 4 5	edges[3][0].push_back(make_pair(2, 0));
				edges[3][1].push_back(make_pair(4, 0));
				edges[3][2].push_back(make_pair(5, 0));
				
	E=1   2		edges[4][0].push_back(make_pair(2, 0));
	E=1   2		edges[5][0].push_back(make_pair(2, 0));
	*/

}	
void RecursiveDFS(vector<vector<int> > edges,	vector<bool> &visited, int current)
{
	if (!visited[current])
	{
	
		visited[current]=true;
		cout << current<<" [";
		for (int adj = 0; adj < int(edges[current].size()); adj++)
			RecursiveDFS(edges, visited, edges[current][adj]);
		cout <<"] ";
	}
}
void InputRecursiveDFS()
{	
	int V,E;
	cin >> V;
	vector<vector<int> > edges;
	vector<bool> visited;
	
	edges.assign(V,vector<int>());
	visited.assign(V,false);
	for(int v=0;v<V;v++)
	{
		cin >>E;
		for(int e=0;e<E;e++)
		{
			int k;
			cin >>k;
			edges[v].push_back(k);
		}
	}
	cout <<"Traversal Order:";
	RecursiveDFS(edges,visited,0);
	cout <<"\n";
}
void BFS()
{
	int V, E;
	cin >> V >> E;
	vector<int> edges[V];
	for (int e = 0; e < E; e++)
  	{
   		int k, m;
    	cin >> k >> m;
    	edges[k].push_back(m);
    	edges[m].push_back(k);
  	}
  	cout << "\nTraversal Order: ";
  	queue<int> q;
  	 bool visited[V] = { 0 };

  	int start;
  	cin >> start;

  	q.push(start); // starting vertex
  	
  while (!q.empty())
  {
  	int current_vertex = q.front();
  	
  	q.pop();
  	
  	if (visited[current_vertex])
	  continue;

      visited[current_vertex] = true;
  	
  	cout << current_vertex << " ";
  	
  	for (size_t i = 0; i < edges[current_vertex].size(); i++)
  	{
  	  int adjacent_vertex = edges[current_vertex][i];
  	  
  	  q.push(adjacent_vertex);
  	}
  }
}
		

int main()
{
	
	BFS();
	//InputRecursiveDFS();
	//inputIterativeDFSusingStack();
	/*input :
	7
	2 1 2
	2 3 4
	2 5 6
	0 
	0
	0
	0
	output : 0 2 6 5 1 4 3
							input :
							8 
							6 2 3 4 5 6 7
							2 2 7
							3 0 1 3
							3 0 2 4
							3 0 3 5
							3 0 4 6
							3 0 5 7
							3 0 1 6
							output : 0 7 6 5 4 3 2 1
											input:
											14
											2 1 10
											2 2 9
											2 3 6
											2 4 5
											0
											0
											2 7 8
											0
											0
											0
											2 11 12
											0
											1 13
											0
											output : 0 10 12 13 11 1 9 2 6 8 7 3 5 4
	*/
}
