const input = require('fs').readFileSync('uri1076/input.txt', 'utf8');
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
        return this.isEmpty() ? "Underflow" : this.items.shift();
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
    }
    addVertex(vertex) {
        this.AdjList.set(vertex, []);
    }

    addEdge(vertex1, vertex2) {
        this.AdjList.get(vertex1).push(vertex2);
        this.AdjList.get(vertex2).push(vertex1);
    }
    printGraph() {
        this.AdjList.forEach((value, key) => console.log(`${key} => ${value}`));
    }

    printPath() {
        this.path.forEach((value, key) => console.log(`${key} => ${value}`));
    }
    getPathLength() {
        return (this.path.length - 1) * 2
    }
    bfs(startingNode) {
        let visited = new Array(this.noOfVertices).fill(false);
        let q = new Queue();
        visited[startingNode] = true;
        q.enqueue(startingNode);

        while (!q.isEmpty()) {
            const QueueElement = q.dequeue();
            this.path.push(QueueElement);
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
        var visited = new Array(this.noOfVertices).fill(false);
        this.DFSUtil(startingNode, visited.fill(false));
    }

    DFSUtil(vertex, visited) {
        visited[vertex] = true;
        this.path.push(vertex);
        let edge = this.AdjList.get(vertex);
        edge.forEach(vertex =>
            !visited[vertex] ? this.DFSUtil(vertex, visited) : ''
        )
    }
}


let Number = 0;
let TestCase = parseInt(lines[Number++]);
for (let t = 1; t <= TestCase; t++) {
    let StartVertex = parseInt(lines[Number++])
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
    graph.dfs(StartVertex)
    console.log(`${graph.getPathLength()}`);
}