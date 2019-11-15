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
graph adj;
vector<bool> visited;
int component = 0;
void dfs(int v)
{
    if (visited[v])
        return;
    visited[v] = true;
    for (auto u : adj[v])
        dfs(u.to);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    visited.assign(n, false);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
   // นับว่าต้องเริ่ม dfs ใหม่ทั้งหมดกี่ครั้ง
    for (int u = 0; u < n; ++u)
    {
        if (!visited[u])
        {
            ++component;
            dfs(u); // dfs เพื่อมาร์คทุก node ใน component ว่าเคยเจอแล้ว
        }
    }
    cout << "component=" << component << endl;
    return 0;
}

void printGraph(int n)
{
    for (size_t v = 0; v < n; v++)
    {
        for (auto &u : adj[v])
        {
            printf("start=%d dest=%d, w=%d\n", v, u.to, u.w);
        }
    }
}