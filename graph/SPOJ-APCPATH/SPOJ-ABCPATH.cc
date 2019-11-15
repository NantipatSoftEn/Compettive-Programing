#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;
char mat[51][51];
int n, m, dis[51][51];

bool IsRange(int x, int y)
{
    return (x < n && y < m && x >= 0 && y >= 0);
}

bool OnMove(int x, int y, int i, int j)
{
    return mat[x][y] == mat[i][j] + 1;
}

bool OnDist(int x, int y, int i, int j)
{
    return dis[x][y] < dis[i][y] +1;
}

void dfs(int i, int j, int dist)
{
    int x, y;
    dis[i][j] = dist + 1;

    x = i - 1;
    y = j - 1;
    if (IsRange(x, y) && OnMove(x, y, i, j) && OnDist(x, y, i, j))
    {
        dfs(x, y, dis[i][j]);
    }

    x = i - 1;
    y = j;
    if (IsRange(x, y) && OnMove(x, y, i, j) && OnDist(x, y, i, j))
    {
        dfs(x, y, dis[i][j]);
    }

    x = i - 1;
    y = j + 1;
    if (IsRange(x, y) && OnMove(x, y, i, j) && OnDist(x, y, i, j))
    {
        dfs(x, y, dis[i][j]);
    }

    x = i;
    y = j - 1;
    if (IsRange(x, y) && OnMove(x, y, i, j) && OnDist(x, y, i, j))
    {
        dfs(x, y, dis[i][j]);
    }

    x = i;
    y = j + 1;
    if (IsRange(x, y) && OnMove(x, y, i, j) && OnDist(x, y, i, j))
    {
        dfs(x, y, dis[i][j]);
    }

    x = i + 1;
    y = j - 1;
    if (IsRange(x, y) && OnMove(x, y, i, j) && OnDist(x, y, i, j))
    {
        dfs(x, y, dis[i][j]);
    }

    x = i + 1;
    y = j;
    if (IsRange(x, y) && OnMove(x, y, i, j) && dis[x][y] < dis[i][j] + 1)
    {
        dfs(x, y, dis[i][j]);
    }

    x = i + 1;
    y = j + 1;
    if (IsRange(x, y) && OnMove(x, y, i, j) && dis[x][y] < dis[i][j] + 1)
    {
        dfs(x, y, dis[i][j]);
    }
}

int main()
{

    int max, tc = 0;
    freopen("input.txt", "r", stdin);
    while (true)
    {
        scanf("%d%d", &n, &m);
        if (!n && !m)
            break;
        tc++;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", mat[i]);
            for (int j = 0; j < m; j++)
                dis[i][j] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'A' && dis[i][j] == 0)
                    dfs(i, j, 0);
            }
        }
        max = dis[0][0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (max < dis[i][j])
                    max = dis[i][j];
        }
        printf("Case %d: %d\n", tc, max);
    }
    return 0;
}