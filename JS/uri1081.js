const input = require('fs').readFileSync('input.txt', 'utf8');
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
    }
    addVertex(vertex) {
        this.AdjList.set(vertex, []);
    }

    addEdge(vertex1, vertex2) {
        this.AdjList.get(vertex1).push(vertex2);
        this.AdjList.get(vertex2).push(vertex1);
    }
    printGraph() {
        this.AdjList.forEach((value, key) =>
            console.log(`${key} => ${value}`)
        );
    }
    getAdjList(){
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
        var visited = new Array(this.noOfVertices).fill(false);
        this.DFSUtil(startingNode, visited.fill(false));
    }

    DFSUtil(vertex, visited) {
        visited[vertex] = true;
        console.log(vertex);
        let edge = this.AdjList.get(vertex);
        edge.forEach(vertex =>
            !visited[vertex] ? this.DFSUtil(vertex, visited) : ''
        )
    }
}

//var g = new Graph(6);
const contains = lines[0].split(' ');

let TotalOfVertices = parseInt(contains[0]);
let graph = new Graph(TotalOfVertices);
const TotalOfEdge = parseInt(contains[1]);
[...Array(TotalOfVertices)].map((_, i) => i).forEach(v => graph.addVertex(v))

for (let index = 1; index <= TotalOfEdge + 1; index++) {
    const vertex = lines[index].split(' ');
    graph.addEdge(parseInt(vertex[0]), parseInt(vertex[1]));
}


//graph.dfs(0)
//graph.printGraph();
console.table(graph.getAdjList(),graph.dfs(0));
