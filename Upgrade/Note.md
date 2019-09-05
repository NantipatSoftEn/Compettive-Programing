# Practices

## Base

```c++
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x " = " << (x) << endl

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    return 0;
}

```

## Vector

### 1d

```c++
 vector<int> c;
 for (size_t i = 0; i < 5; i++)
    c.push_back(i);
for (size_t i = 0; i < 5; i++)
    cout <<  c[i] << ", ";

```

### 2d version1

```c++
vector<vector<int>> c;
 for (size_t i = 0; i < 5; i++)
    {
        vector<int> row;
        c.push_back(row);
    }

 for (size_t i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            c[i].push_back(j);

for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
            cout << c[i][j] << ", ";
        cout << endl;
    }
```
