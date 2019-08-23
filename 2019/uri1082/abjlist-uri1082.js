const input = require('fs').readFileSync('uri1082/input.txt', 'utf8');
let lines = input.split('\n');
class Graph {
    constructor(noOfVertices) {
        this.noOfVertices = noOfVertices;
        this.AbjList = new Map();
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
    addVertex(v) {
        this.AbjList.set(v, [])
    }
    addEdge(v1, v2) {
        this.AbjList.get(v1).push(v2)
        this.AbjList.get(v2).push(v1)
    }
    printAbjMetrix() {
        console.table(this.AdjMetrix);
    }

    printPath() {
        this.path.forEach((value, key) => console.log(`${key} => ${this.getCharBy(value)}`));
    }

    dfs(vertex) {
        this.connect.push(this.getCharBy(vertex))
        this.visited[vertex] = true;
        const edge = this.AbjList.get(vertex)
        edge.forEach(e => {
            if(!this.visited[e]){
                this.dfs(e);
            }
        })
    }

    startBy(TotalOfVertex){
        let count = 0;
        for (let index = 0; index < TotalOfVertex; index++) {
            this.connect = new Array();
            if(!this.visited[index]){
                this.dfs(index)
                console.log(`${this.connect.sort()},`);
                count++;
            }           
        }
        console.log(`${count} connected components`);
    }
}
let Number = 0
let Testcaee = lines[Number++];
for (let t = 1; t <= Testcaee; t++) {
    console.log(`Case #${t}:`);
    let contaners = lines[Number].split(` `);
    let TotalOfVertex = parseInt(contaners[0])
    let TotalOfEdge = parseInt(contaners[1])
    var g = new Graph(TotalOfVertex);
    [...Array(g.noOfVertices)].map((_, i) => i).forEach(v => g.addVertex(v))
    const start = ++Number
    for (let i = start; i < TotalOfEdge + start; i++) {
        const vertex = lines[i].split(' ');
        let v1 = vertex[0].toString().replace(/\n|\r/g, "")
        let v2 = vertex[1].toString().replace(/\n|\r/g, "")
        g.addEdge(g.getIndexBy(v1), g.getIndexBy(v2))
        Number++;
    }
    g.startBy(g.noOfVertices);
    console.log('');
    
}