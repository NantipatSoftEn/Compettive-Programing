const input = require('fs').readFileSync('uri1082/input.txt', 'utf8');
let lines = input.split('\n');
class Graph {
    constructor(noOfVertices) {
        this.noOfVertices = noOfVertices;
        this.AdjMetrix = Array(noOfVertices).fill(null).map(() => Array(noOfVertices).fill(0));
        this.path = new Array();
        this.visited = new Array(noOfVertices).fill(false);
        this.connect = new Array();
    }
    getIndexBy(char) {
        return char.charCodeAt(0) - 97;
    }

    getCharBy(int) {
        return String.fromCharCode(int + 97);
    }

    printVisited() {
        console.table(this.visited);
    }

    addEdge(v1, v2) {
        this.AdjMetrix[v1][v2] = 1
        this.AdjMetrix[v2][v1] = 1
    }
    printAbjMetrix() {
        console.table(this.AdjMetrix);
    }

    printPath() {
        this.path.forEach((value, key) => console.log(`${key} => ${this.getCharBy(value)}`));
    }

    dfs(vertex1) {
        this.connect.push(this.getCharBy(vertex1));
        this.path.push(vertex1)
        this.visited[vertex1] = true
        for (let i = 0; i < this.noOfVertices; i++) {
            if (!this.visited[i]) {
                if (this.AdjMetrix[vertex1][i] === 1) {
                    this.dfs(i)
                }
            }
        }
    }

    dfs_runner(TotalOfVertex) {
        let countConnect = 0;
        for (let v = 0; v < TotalOfVertex; v++) {
            if (!this.visited[v]) {
                this.connect = new Array();
                countConnect++
                this.dfs(v);
                console.log(`${this.connect.sort()},`);
            }
        }
        console.log(`${countConnect} connected components\n`);
    }
}



let Number = 0
let Testcaee = lines[Number++];
for(let t =1;t<=Testcaee;t++){
    console.log(`Case #${t}:`);
    let contaners = lines[Number].split(` `);
    let TotalOfVertex = parseInt(contaners[0])
    let TotalOfEdge = parseInt(contaners[1])
    var g = new Graph(TotalOfVertex);
    const start = ++Number
    for (let i = start; i < TotalOfEdge + start; i++) {
        const vertex = lines[i].split(' ');
        let v1 = vertex[0].toString().replace(/\n|\r/g, "")
        let v2 = vertex[1].toString().replace(/\n|\r/g, "")
        g.addEdge(g.getIndexBy(v1), g.getIndexBy(v2))
        Number++;
    }
    g.dfs_runner(TotalOfVertex)
}
