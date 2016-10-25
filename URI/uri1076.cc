#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
int c=0;
void IterativeDFSusingStack(vector<int>edges[],int V,int start)
{
    stack<int> s;
    bool visited[V];
    for(int i=0; i<V; i++)
        visited[i]=false;
    s.push(start); //start vertex

    while(!s.empty())
    {
        //cout <<"TOP="<<s.top()<<endl;
        int current_vertex=s.top();

        s.pop();
        if(!visited[current_vertex])
            visited[current_vertex]=true;

        else continue;

        cout << current_vertex << " ";
        c++;
        for(int i=0; i<edges[current_vertex].size(); i++)
        {
            int adjacent_vertex=edges[current_vertex][i];
            s.push(adjacent_vertex);
        }
    }
}
void inputIterativeDFSusingStack()
{
    int start,V,E;
    cin >>start>> E>>V;
    vector<int> edges[V*2];
    for (int v = 0; v < V; v++)
    {
        int e,k;
        cin >>e>> k;
        edges[e].push_back(k);
        edges[k].push_back(e);
    }
    IterativeDFSusingStack(edges,V,start);
    cout <<"fuck="<<c-1*2;
}
int main()
{

    inputIterativeDFSusingStack();

}
