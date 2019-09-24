#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long inf = 1000000000;
int n, m;
int adj[100][100];
vector<int> visited(27, false);
int start = 1;
void floodFill(int adj[100][100], int x, int y)
{
    if ((x < n) && (x >= 0) && (y < m) && (y >= 0) && !(visited[adj[x][y]]))
    {
        if (adj[x][y] == start)
        {
            start++;
            //cout << adj[x][y] << " ";
            visited[adj[x][y]] = true;
            floodFill(adj, x - 1, y - 1);
            floodFill(adj, x - 1, y);
            floodFill(adj, x - 1, y + 1);
            floodFill(adj, x, y - 1);
            floodFill(adj, x, y + 1);
            floodFill(adj, x + 1, y - 1);
            floodFill(adj, x + 1, y);
            floodFill(adj, x + 1, y + 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int tc = 1;
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        memset(adj, 0, sizeof(adj));    
        visited.assign(27,false);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                char c;
                cin >> c;
                adj[i][j] = (int)c - 64;
            }
        }
        int result = 0;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                if (adj[i][j] == 1)
                {
                    floodFill(adj, i, j);
                    //cout << "start" << start - 1 << endl;
                }

                if (result < start)
                {
                    result = start;
                    start = 1;
                }
            }
        }
    
        printf("Case %d: %d\n",tc,--result);
        tc++;
    }
}

/*for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }*/