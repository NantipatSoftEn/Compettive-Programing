#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long inf = 1000000000;
int n, m;
int adj[51][51];
int dist[51][51];
int ax[] = {-1,0,1,1,1,0,-1,-1} , ay[] = {-1,-1,-1,0,1,1,1,0} ;
bool IsRange(int x, int y)
{
    return (x < n) && (x >= 0) && (y < m) && (y >= 0);
}
void floodFill(int x, int y, int countDist)
{
    debug(adj[x][y]);
    int movex, movey;
    dist[x][y] = countDist + 1;
    movex = x - 1;
    movey = y - 1;
    if (IsRange(movex, movey) && adj[movex][movex] == adj[x][y] + 1 && dist[movex][movex] < dist[x][y] + 1)
        floodFill(movex, movey, dist[x][y]);
    movex = x - 1;
    movey = y;
    if (IsRange(movex, movey) && adj[movex][movey] == adj[x][y] + 1 && dist[movex][movey] < dist[x][y] + 1)
        floodFill(movex, movey, dist[x][y]);

    movex = x - 1;
    movey = y + 1;
    if (IsRange(movex, movey) && adj[movex][movey] == adj[x][y] + 1 && dist[movex][movey] < dist[x][y] + 1)
        floodFill(movex, movey, dist[x][y]);

    movex = x;
    movey = y - 1;
    if (IsRange(movex, movey) && adj[movex][movey] == adj[x][y] + 1 && dist[movex][movey] < dist[x][y] + 1)
        floodFill(movex, movey, dist[x][y]);

    movex = x;
    movey = y + 1;
    if (IsRange(movex, movey) && adj[movex][movey] == adj[x][y] + 1 && dist[movex][movey] < dist[x][y] + 1)
        floodFill(movex, movey, dist[x][y]);

    movex = x + 1;
    movey = y - 1;
    if (IsRange(movex, movey) && adj[movex][movey] == adj[x][y] + 1 && dist[movex][movey] < dist[x][y] + 1)
        floodFill(movex, movey, dist[x][y]);

    movex = x + 1;
    movey = y;
    if (IsRange(movex, movey) && adj[movex][movey] == adj[x][y] + 1 && dist[movex][movey] < dist[x][y] + 1)
        floodFill(movex, movey, dist[x][y]);

    movex = x + 1;
    movey = y + 1;
    if (IsRange(movex, movey) && adj[movex][movey] == adj[x][y] + 1 && dist[movex][movey] < dist[x][y] + 1)
        floodFill(movex, movey, dist[x][y]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int tc = 1;
    int max;
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        memset(adj, 0, sizeof(adj));
        memset(dist, 0, sizeof(dist));

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                char c;
                cin >> c;
                adj[i][j] = (int)c - 64;
            }
        }
        max = dist[0][0];
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++)
                if (adj[i][j] == 1 && dist[i][j] == 0)
                    floodFill(i, j, 0);

        printf("Case %d: %d\n", tc, max);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                if (max < dist[i][j])
                    max = dist[i][j];
            }
        }
        printf("Case %d: %d\n", tc, max);
        tc++;
    }
}
