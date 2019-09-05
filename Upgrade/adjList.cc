#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long inf = 1000000000;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    for (size_t v = 0; v < n; v++)
    {
        for (auto &u : g[v])
        {
            printf("start=%d dest=%d, w=%d\n",v,u.to,u.w);
        }
    }


}
