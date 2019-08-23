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

var g = new Graph(6);
var vertices = ['A', 'B', 'C', 'D', 'E', 'F'];
vertices.forEach(v => g.addVertex(v))
g.addEdge('A', 'B');
g.addEdge('A', 'D');
g.addEdge('A', 'E');
g.addEdge('B', 'C');
g.addEdge('D', 'E');
g.addEdge('E', 'F');
g.addEdge('E', 'C');
g.addEdge('C', 'F');
console.log("DFS");
g.dfs('B')
//g.printGraph();
//https://www.geeksforgeeks.org/implementation-graph-javascript/