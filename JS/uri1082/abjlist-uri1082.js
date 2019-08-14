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
    addVertex(v){
        this.AbjList.set(v,[])
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

    dfs(vertex1) {
        this.connect.push(this.getCharBy(vertex1));
        this.path.push(vertex1)
        this.visited[vertex1] = true
        let edge = this.AbjList.get(vertex1);
        edge.forEach((e)=>{
            if(!this.visited[e]){
                console.log(`${e}`);
                
            }
        })
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
    g.addVertex()
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
