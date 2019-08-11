### description
recursive deph-searching in nodes of a graph, using backtracking

```javascript
dfs_runner(ToTalOfVertex)
```
loop totol of vertex  start with 0 

```javascript
dfs_runner(vertex) {
        let start = 0;
        while (true) {
            this.dfs(start, vertex, '  ') ? console.log() : '';
            start = -1
            for (let i = 0; i < vertex; i++) {
                if (!this.visited[i]) {
                    start = i;
                    break;
                }
            }
            if (start === -1) break;
        }
    }
```
loop  col in array AdjMetrix if found  that index  is  1 (0 is not connect edge) after that  check visited[i] 
```javascript
   dfs(vertex1, vertex2, s) {
        let path = false;
        this.visited[vertex1] = true;
        for (let i = 0; i < vertex2; i++) {
            if (this.AdjMetrix[vertex1][i] === 1) {
                path = true;
                if (!this.visited[i]) {

                    console.log(`${s}${vertex1}-${i} pathR(G,${i})`);
                    this.dfs(i, vertex2, s + '  ');
                } else {

                    console.log(`${s}${vertex1}-${i}`);
                }
            }
        }
        return path
    }

```