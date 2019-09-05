#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int maxtrix[n][n];
    memset(maxtrix, 0, sizeof(maxtrix));
    for (size_t i = 0; i < m; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;
        maxtrix[v][u] = w;
        maxtrix[u][v] = w;
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf("%d ", maxtrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}