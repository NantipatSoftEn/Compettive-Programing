const input = require('fs').readFileSync('uri1931/input.txt', 'utf8');
let lines = input.split('\n');

class PriorityQueue {
    constructor() {
        this.collection = [];
    }
    enqueue(element) {
        if (this.isEmpty()) {
            this.collection.push(element);
        } else {
            let added = false;
            for (let i = 1; i <= this.collection.length; i++) {
                if (element[1] < this.collection[i - 1][1]) {
                    this.collection.splice(i - 1, 0, element);
                    added = true;
                    break;
                }
            }
            if (!added) {
                this.collection.push(element);
            }
        }
    }

    dequeue() {
        return this.collection.shift();
    };
    isEmpty() {
        return (this.collection.length === 0)
    };
}

class Graph {
    constructor(TotalOfVertex) {
        this.nodes = [];
        this.adj = Array(TotalOfVertex).fill(TotalOfVertex).map(() =>
            Array(TotalOfVertex).fill(Infinity)
        );
        this.weight = new Array(TotalOfVertex).fill(Infinity);
        this.path = {};
        this.visited = new Array(TotalOfVertex).fill(false);
        this.total = TotalOfVertex;
        this.adjList = {};
        for (let i = 1; i < TotalOfVertex; i++) {
            this.addNode(i)
        }
    }
    addEdge(src, dist, w) {
        this.adj[src][dist] = w;
        this.adj[dist][src] = w;
    }

    dks(src, dist) {
        let pq = new PriorityQueue();
        this.weight[src] = 0;
        pq.enqueue([src, 0])
        while (!pq.isEmpty()) {
            let top = pq.dequeue();
            let currentNode = top[0];
            let currentWeight = top[1];
            if (this.weight[currentNode] > currentWeight)
                continue;
            this.calculateWeight(currentNode, currentWeight, pq);
        }
        return this.weight[dist];
    }
    calculateWeight(currentNode, currentWeight, pq) {
        this.adjList[currentNode].forEach(to => {
            if (currentWeight + to.w < this.weight[to.n]) {
                this.weight[to.n] = currentWeight + to.w;
                pq.enqueue([to.n, this.weight[to.n]]);
            }
        });



    }
    restorePath(src, dist) {
        let path = [dist];
        let lastStep = dist;
        while (lastStep !== src) {
            path.unshift(this.path[lastStep]) // add value to front 
            lastStep = this.path[lastStep]
        }
        return `Path is ${path}`
    }
    addNode(node) {
        this.adjList[node] = []
    }

    dfs(src) {
        if (!this.visited[src]) {
            this.visited[src] = true;
            for (let i = 0; i < this.adj[src].length; i++) {
                for (let j = 1; j < this.adj[i].length; j++) {
                    this.adjList[src].push({
                        n: j,
                        w: this.adj[src][i] + this.adj[i][j]
                    })
                    this.dfs(j)
                }
            }
        }
    }

}

let n = 0;
const contaner = lines[n++].split(` `);
const v = parseInt(contaner[0]);
const e = parseInt(contaner[1]);
let g = new Graph(v + 1);
for (let i = n; i <= e; i++) {
    let value = lines[n++].split(` `);
    let src = parseInt(value[0]);
    let dist = parseInt(value[1]);
    let w = parseInt(value[2]);
    g.addEdge(src, dist, w)
}
g.dfs(1)
const  result  = g.dks(1, v);
if (result !== Infinity) {
    console.log(result);
} else {
    console.log(`-1`);
    
}