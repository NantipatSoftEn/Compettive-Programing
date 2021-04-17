#include <bits/stdc++.h>
#include <queue>
using namespace std;
struct edge
{
    int to;
    long long w;
    edge(int a, long long b) : to(a), w(b) {}
    bool operator<(const edge &o) const
    {
        return w > o.w;
    }
};

typedef vector<vector<edge>> graph;
graph adj;
vector<bool> visited;

bool dfsConnected(int s,int d,int n)
{
    if(s == d)
        return true;
    vector<int> vec;
    visited.assign(n, false);
    visited[s] = true;
    vec.push_back(s);
	while (!vec.empty()){
	    s= vec.front();
	    vec.erase(vec.begin());
        for (auto &u : adj[s]){
            if(u.to==d) return true;
            if(!visited[u.to]){
                visited[u.to] = true;
                vec.push_back(u.to);
            }
        }
        
	}
	return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 0});
    }
    int q;
    cin >> q;
    int s,d;
    while(q--){
        cin >> s >> d;
        if (dfsConnected(s, d,m))
            cout << "yes" << endl;
	    else
		    cout << "no" << endl;
    }
    return 0;
}