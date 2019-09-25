#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#define debug(x) cout << #x " = " << (x) << endl
using namespace std;
char mat[31][31];
int n = 30, m = 30;
bool IsRangeX(int x, int y)
{
    return (x < n && x >= 0);
}

bool IsRangeY(int x, int y)
{
    return (y < m && y >= 0);
}

bool IsStepOnly(int x, int y)
{
    return mat[x][y] == '.' || mat[x][y] == 'G';
}

bool dfs(int i, int j, bool visited[31][31])
{
    printf("mat[%d][%d]=%c\n", i, j, mat[i][j]);
    if (mat[i][j] == 'G')
    {
        cout << "possible" << endl;
        return true;
    }

    int x, y;
    x = i - 1; //   up
    y = j;
    if (IsRangeX(x, y) && IsStepOnly(x, y) && !visited[x][y])
    {
        visited[x][y] = true;
        dfs(x, y, visited);
    }

    x = i; //   right
    y = j + 1;
    if (IsRangeY(x, y) && IsStepOnly(x, y) && !visited[x][y])
    {
        visited[x][y] = true;
        dfs(x, y, visited);
    }

    x = i + 1; // down
    y = j;
    if (IsRangeX(x, y) && IsStepOnly(x, y) && !visited[x][y])
    {
        visited[x][y] = true;
        dfs(x, y, visited);
    }

    x = i; // left
    y = j - 1;

    if (IsRangeY(x, y) && IsStepOnly(x, y) && !visited[x][y])
    {
        visited[x][y] = true;
        dfs(x, y, visited);
    }

    return false;
}

int main()
{

    int tc = 0;
    freopen("input.txt", "r", stdin);
    bool visited[31][31];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
        scanf("%s", mat[i]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'P')
            {

                cout << dfs(i, j, visited) << endl;
            }
        }
    }
    return 0;
}