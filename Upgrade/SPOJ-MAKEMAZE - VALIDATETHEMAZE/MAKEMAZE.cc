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

bool isDot(int i, int j)
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
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        memset(mat, 0, sizeof(mat));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        int countEntry = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (n > 1 && m > 1)
            {
                if (isDot(0, i))
                    countEntry++;
                if (isDot(i, 0))
                    countEntry++;
                if (isDot(i, m - 1))
                    countEntry++;
                if (isDot(n - 1, i))
                    countEntry++;
            }
            else if(n==1 && m==1){
                countEntry=0;
            }
            else
            {
                if (isDot(0, i))
                    countEntry++;
                if (isDot(i, 0))
                    countEntry++;
            }
        }
        //debug(countEntry);
        if (countEntry == 2)
        {
            cout << "valid" << endl;
        }
        else
        {
            cout << "invalid" << endl;
        }
    }

    return 0;
}

/*
valid
valid
invalid
valid
invalid
invalid
*/