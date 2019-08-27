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
    }
    addEdge(src, dist, w) {
        this.adj[src][dist] = w;
        this.adj[dist][src] = w;
    }

    dks(src, dist, adj2) {
        let pq = new PriorityQueue();
        this.weight[src] = 0;
        pq.enqueue([src, 0])
        while (!pq.isEmpty()) {
            let top = pq.dequeue();
            let currentNode = top[0];
            let currentWeight = top[1];
            if (this.weight[currentNode] > currentWeight)
                continue;
            this.calculateWeight(currentNode, currentWeight, pq, adj2);
        }
        return this.weight[dist];
    }
    calculateWeight(currentNode, currentWeight, pq, adj2) {
        adj2[currentNode].forEach(element => {
            if (currentWeight + element.w < this.weight[element.n]) {
                this.weight[element.n] = currentWeight + element.w;
                pq.enqueue([element.n,  this.weight[element.n]]);
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


}
const dfs = (adj1, adj2, visited, src) => {
    if (!visited[src]) {
        visited[src] = true;
        for (let i = 1; i < adj1[src].length; i++) {
            for (let j = 1; j < adj1[i].length; j++) {
                adj2[src].push({
                    n: j,
                    w: adj1[src][i] + adj1[i][j]
                })
                dfs(adj1, adj2, visited, j)
            }
        }
    }
}

const addNode = (adj2, node) => {
    adj2[node] = []
}
let g = new Graph(5);
g.addEdge(1, 2, 2)
g.addEdge(2, 3, 1)
g.addEdge(2, 4, 10)
g.addEdge(3, 4, 6)

let adj2 = {}
for (let i = 1; i <= 5; i++) {
    addNode(adj2, i)
}
let visited = new Array(5).fill(false);
dfs(g.adj, adj2, visited, 1)
console.log(g.dks(1, 4, adj2));