#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;
/*
s = start,
d =  current weight (distance) 
p =  store path
*/

vector<int> restore_path(int s, int t, vector<int> const &p)
{
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}

void dijkstra(int s, vector<int> &d, vector<int> &p)
{
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty())
    {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v])
        {
            int to = edge.first;
            int w = edge.second;

            if (d[v] + w < d[to])
            {
                d[to] = d[v] + w;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int v, e, s, t, w;
    cin >> v >> e;

    for (int i = 0; i < v; i++)
    {
        vector<pair<int, int>> row;
        adj.push_back(row);
    }
    for (size_t i = 0; i < e; i++)
    {
        cin >> s >> t >> w;
        adj[s].push_back(make_pair(t, w));
        adj[t].push_back(make_pair(s, w));
    }

    vector<int> d;
    vector<int> p;
    dijkstra(0, d, p);

    vector<int> f;
    f = restore_path(13, 2, p);
    for (size_t i = 0; i < f.size(); i++)
    {
        cout << f[i] << " ";
    }
    cout << endl;
    for (size_t i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
}