#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long inf = 1000000000;
#define MAX 10000001
typedef vector<vector<int>> graph;
graph adj;
vector<bool> visited;
int n, m;
int cats[MAX];
int result = 0;
void printGraph(int n)
{
    for (size_t v = 0; v < n; v++)
    {
        for (auto &u : adj[v])
        {
            printf("start=%d dest=%d\n", v, u);
        }
    }
}
void dfs(int v, int sumCat)
{
    int sum = 0;
    visited[v] = true;
    if (sumCat > m)
        return;
    bool ok = false;
    for (auto u : adj[v])
    {
        if (!visited[u])
        {
            if (cats[u])
                sum = sumCat + 1;
            else
                sum = 0;
            dfs(u, sum);
            ok = true;
        }
    }
    if (!ok)
        result++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    adj.resize(n + 1);
    for (size_t i = 1; i < n + 1; i++)
    {
        cin >> cats[i];
    }

    visited.assign(n + 1, false);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(1, cats[1]);
    cout << result << endl;
    //printGraph(n);
    return 0;
}