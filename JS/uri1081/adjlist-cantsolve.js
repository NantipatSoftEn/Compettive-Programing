const input = require('fs').readFileSync('uri1081/input.txt', 'utf8');
let lines = input.split('\n');

class Queue {
    // Array is used to implement a Queue
    constructor() {
        this.items = [];
    }
    enqueue(element) {
        this.items.push(element);
    }
    dequeue() {
        return this.isEmpty() ?
            "Underflow" : this.items.shift();
    }
    front() {
        return this.isEmpty() ? "No elements in Queue" : this.items[0];
    }
    isEmpty() {
        return this.items.length == 0;
    }
    printQueue() {
        return this.items.forEach((item, str = "") => str += item + " ");
    }
}

class Graph {
    constructor(noOfVertices) {
        this.noOfVertices = noOfVertices;
        this.AdjList = new Map();
        this.path = new Array();
        this.visitedDepth;
    }
    addVertex(vertex) {
        this.AdjList.set(vertex, []);
    }

    addEdge(vertex1, vertex2) {
        this.AdjList.get(vertex1).push(vertex2);
        //this.AdjList.get(vertex2).push(vertex1);
    }
    printGraph() {
        this.AdjList.forEach((value, key) => console.log(`${key} => ${value}`));
    }

    printPath() {
        this.path.forEach((value, key) => console.log(`${key} => ${value}`));
    }

    getAdjList() {
        return this.AdjList;
    }
    bfs(startingNode) {
        let visited = new Array(this.noOfVertices).fill(false);
        let q = new Queue();
        visited[startingNode] = true;
        q.enqueue(startingNode);

        while (!q.isEmpty()) {
            const QueueElement = q.dequeue();
            console.log(QueueElement);
            let edges = this.AdjList.get(QueueElement);
            edges.forEach(vertex => {
                if (!visited[vertex]) {
                    visited[vertex] = true;
                    q.enqueue(vertex);
                }
            })
        }
    }

    dfs(startingNode) {
        let visited = new Array(this.noOfVertices).fill(false);
        this.DFSUtil(startingNode, visited);
    }

    DFSUtil(vertex, visited) {
        visited[vertex] = true;
        this.path.push(vertex);
        let edge = this.AdjList.get(vertex);
        edge.forEach(vertex => !visited[vertex] ? this.DFSUtil(vertex, visited) : '')
    }

    setVisitedDepth(TotalOfVertices) {
        this.visitedDepth = new Array(TotalOfVertices).fill(false);
    }
    findDepthDFS(vertex, blank = '', newline = '') {
        if (!this.visitedDepth[vertex]) {
            this.visitedDepth[vertex] = true;
            let edges = this.AdjList.get(vertex);
            let VertexConnectEdge = '';
            blank += '  ';
            for (let value of edges) {
                //console.log(`value=${value}, ${this.visitedDepth[value]}`);
                
                if (this.visitedDepth[value]) {
                    VertexConnectEdge;
                } else {
                    VertexConnectEdge = ` pathR(G,${value})`
                }

        
                console.log(`${newline}${blank}${vertex}-${value}${VertexConnectEdge}`);
                this.findDepthDFS(value, blank)
            }

        }
    }
}


let Number = 0;
let TestCase = lines[Number++];
for (let i = 1; i <= TestCase; i++) {
    console.log(`Caso ${i}:`);
    const contains = lines[Number].split(' ');
    let TotalOfVertices = parseInt(contains[0]);
    const TotalOfEdge = parseInt(contains[1]);
    let graph = new Graph(TotalOfEdge);
    [...Array(TotalOfVertices)].map((_, i) => i).forEach(v => graph.addVertex(v))
    const LineStartEdge = ++Number;
    for (let index = LineStartEdge; index < TotalOfEdge + LineStartEdge; index++) {
        const vertex = lines[index].split(' ');
        graph.addEdge(parseInt(vertex[0]), parseInt(vertex[1]));
        Number++;
    }
    graph.setVisitedDepth(TotalOfVertices);
    graph.dfs(0)
    graph.findDepthDFS(0);
    /*graph.visitedDepth.forEach((value, index) => {
        if (!value) {
            graph.findDepthDFS(index, ``, `\n`)
        }
    })*/
    console.log();
    graph.printGraph()
    console.log('path');
    
    graph.printPath();
}