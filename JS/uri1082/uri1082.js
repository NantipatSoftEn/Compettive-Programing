const input = require('fs').readFileSync('uri1082/input.txt', 'utf8');
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
        this.visited = {}
        this.map = ['a', 'b', 'c', 'd', 'e', 'f',
            'g', 'h', 'i', 'j', 'k', 'l',
            'm', 'n', 'o', 'p', 'q', 'r',
            's', 't', 'u', 'v', 'w',
            'x', 'y', 'z'
        ]
    }
    setVisited(vertex1, vertex2) {
        this.visited[vertex1] = false
        this.visited[vertex2] = false
    }

    printVisited() {
        for (let i = 0; i < this.noOfVertices; i++)
            console.log(`${this.map[i]} => ${this.visited[this.map[i]]}`);
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
        let visited = new Map();
        this.DFSUtil(startingNode, visited.fill(false));
    }

    DFSUtil(vertex, visited) {
        visited[vertex] = true;
        this.path.push(vertex);
        let edge = this.AdjList.get(vertex);

        /*edge.forEach(vertex =>
            !visited[vertex] ? this.DFSUtil(vertex, visited) : ''
        )*/
    }
}

let Number = 0
let Testcaee = lines[Number++];
let contaners = lines[Number].split(` `);
let TotalOfVertex = parseInt(contaners[0])
let TotalOfEdge = parseInt(contaners[1])
var g = new Graph(TotalOfVertex);

for (let i = 0; i < TotalOfVertex; i++) {
    g.addVertex(g.map[i])
}

const start = ++Number
for (let i = start; i < TotalOfEdge + start; i++) {
    const vertex = lines[i].split(' ');
    let v1 = vertex[0].toString().replace(/\n|\r/g, "")
    let v2 = vertex[1].toString().replace(/\n|\r/g, "")
    g.setVisited(v1, v2)
    g.addEdge(v1, v2)
    Number++;
}

g.printGraph();
g.printVisited();