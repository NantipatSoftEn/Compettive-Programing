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
    
    dks(src, dist) {
        let pq = new PriorityQueue();
        this.weight[src] = 0;
        pq.enqueue([src, 0])
        while (!pq.isEmpty()) {
            let top = pq.dequeue();
            let currentNode = top[0];
            let currentWeight = top[1];
            this.calculateWeight(currentNode,currentWeight,pq);
        }
        return this.weight[dist];
    }
    calculateWeight(currentNode,currentWeight,pq){
        for (let i = 0; i < this.total; i++) {
            if(currentWeight + this.adj[currentNode][i] < this.weight[i] ){
                this.weight[i] = currentWeight + this.adj[currentNode][i];
                this.path[i] = currentNode
                pq.enqueue([i, this.weight[i]])
            }
        }
    }
    restorePath(src, dist){
        let path = [dist];
        let lastStep = dist;
        while (lastStep !== src) {
            path.unshift(this.path[lastStep]) // add value to front 
            lastStep = this.path[lastStep]
        }
        return `Path is ${path}`
    }
}


let g = new Graph(4);
g.addEdge(0, 1, 2)
g.addEdge(1, 2, 2)
g.addEdge(0, 3, 8)
g.addEdge(2, 3, 1)
//console.table(g.adj);
console.log(g.dks(0,3));
console.log(g.restorePath(0,3));