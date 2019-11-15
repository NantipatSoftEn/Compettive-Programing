#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long inf = 1000000000;
char mat[255][255];
int n, m;
vector<bool> visited;
int sheeps = 0;
int wolve = 0;
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
    return mat[x][y] == 'v' || mat[x][y] == '.' || mat[x][y] == 'k';
}

void dfs(int i, int j, bool visited[255][255])
{
    //printf("mat[%d][%d]=%c\n", i, j, mat[i][j]);
    visited[i][j] = true;
    if (mat[i][j] == 'k')
        sheeps++;

    if (mat[i][j] == 'v')
        wolve++;

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
}

int main()
{
    freopen("input.txt", "r", stdin);
    bool visited[255][255];
    memset(visited, false, sizeof(visited));
    cin >> n >> m;
    int sumSheep = 0;
    int sumWolve = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'k')
                sumSheep++;
            if (mat[i][j] == 'v')
                sumWolve++;
        }
    }
    //debug(sumSheep);
    //debug(sumWolve);
    /*for (size_t i = 0; i < n; i++)
    {
        cout << mat[i] << endl;
    }*/

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (mat[i][j] == 'k' && !visited[i][j])
            {
                sheeps = 0;
                wolve = 0;
                dfs(i, j, visited);
                //printf("k=%d v=%d\n",sheeps,wolve);
                if (sheeps <= wolve)
                    sumSheep -= sheeps;
                else if (sheeps > wolve)
                    sumWolve -= wolve;
            }
        }
    }
    printf("%d %d\n", sumSheep, sumWolve);
}
