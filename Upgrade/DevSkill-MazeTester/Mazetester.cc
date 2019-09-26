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
string result = "Impossible";
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

string dfs(int i, int j, bool visited[31][31])
{
    //printf("mat[%d][%d]=%c\n", i, j, mat[i][j]);
    if (mat[i][j] == 'G')
    {
        result = "Possible";
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
    return result;
}

int main()
{

    int tc = 0;
    freopen("input.txt", "r", stdin);
    int index = 0;
    while (scanf("%s", mat[index++]) != EOF)
    {
        result = "Impossible";
        if (index == 30)
        {
            /*for (size_t i = 0; i < 30; i++)
            {
                cout  << mat[i] << endl;
            }*/
            
            index=0;
            bool visited[31][31];
            memset(visited, false, sizeof(visited));

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
             memset(mat, 0, sizeof(mat));
        }
    }
    return 0;
}