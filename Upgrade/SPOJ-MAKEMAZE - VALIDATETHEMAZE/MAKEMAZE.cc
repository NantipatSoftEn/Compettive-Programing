#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl
int n, m;
char mat[20][20];
bool visited[20][20];

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

bool isInValid(int i, int j)
{
    return mat[i][j] == '.';
}

void dfs(int v)
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    int countEntry = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (isInValid(i, m))
        {
            countEntry++;
        }
    }

    for (size_t i = 0; i < m; i++)
    {
        if (isInValid(n, i))
        {
            countEntry++;
        }
    }

    for (size_t i = 0; i < m; i++)
    {
        if (isInValid(n, i))
        {
            countEntry++;
        }
    }

    debug(countEntry);
    if (countEntry <= 1 && countEntry > 2)
    {
        cout << "invalid" << endl;
    }
    else
    {
        cout << "valid" << endl;
    }
    return 0;
}