const input = require('fs').readFileSync('uri1081/input.txt', 'utf8');
let lines = input.split('\n');

class Graph {
    constructor(TotalOfVertex) {
        this.TotalOfVertex = TotalOfVertex;
        this.AdjMetrix = Array(TotalOfVertex).fill(null).map(() => Array(TotalOfVertex).fill(0));
        this.visited = new Array(TotalOfVertex).fill(false);
    }

    printAbjMetrix() {
        console.table(this.AdjMetrix);
    }

    addEdge(v1, v2) {
        this.AdjMetrix[v1][v2] = 1
    }
    dfs(vertex, n, s) {
        this.visited[vertex] = true;
        let sumSpace = '';
        for (let i = 0; i < n; i++) {
            if (this.AdjMetrix[vertex][i] === 1) {
                if (!this.visited[i]) {
             
                    console.log(`${s}${vertex}-${i} pathR(G,${i})`);
                    this.dfs(i, n, s + 'bb');
                } else {
                  
                    console.log(`${s}${vertex}-${i}`);
                }
            }
        }
    }
    dfs_runner(vertex) {
        let start = 0;
        while (true) {
            this.dfs(start, vertex, 'bb')
            start = -1

            for (let i = 0; i < vertex; i++) {
                if (!this.visited[i]) {
                    start = i;
                    break;
                }
            }
            if (start === -1)
                break;
        }
    }
}

let Number = 0
let contaners = lines[++Number].split(` `);
let TotalOfVertex = parseInt(contaners[0])
let TotalOfEdge = parseInt(contaners[1])
console.log(`${TotalOfVertex} , ${TotalOfEdge}`);

let g = new Graph(TotalOfVertex);
let start = ++Number
for (let i = start; i < TotalOfEdge + start; i++) {
    const vertex = lines[i].split(' ');
    g.addEdge(parseInt(vertex[0]), parseInt(vertex[1]))
    Number++;
}

g.dfs_runner(TotalOfVertex)