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
    constructor() {
        this.nodes = [];
        this.adj = {};
        this.weight = {};
        this.path = {};
    }

    addNode(node) {
        this.nodes.push(node);
        this.adj[node] = [];
    }

    addEdge(src, dist, weight) {
        this.adj[src].push({
            node: dist,
            weight: weight
        });
    }

    setWeight(src){
        this.nodes.forEach(node => {
            if (node !== src) {
                this.weight[node] = Infinity
            }
        });
    }

    getWeight(dist){
        return this.weight[dist];
    }
    calculateWeight(node,pq){
        this.adj[node].forEach(e => {
            if ( this.weight[node] + e.weight < this.weight[e.node]) {
                this.weight[e.node] =  this.weight[node] + e.weight; //replace weight
                this.path[e.node] = node; //  backtrace connection
                pq.enqueue([e.node,  this.weight[node] + e.weight]);
            }
        });
    }

    Dks(src, dist) {
        let pq = new PriorityQueue();
        this.weight[src] = 0;
        this.setWeight(src);

        pq.enqueue([src, 0]);
        while (!pq.isEmpty()) {
            let top = pq.dequeue();
            let currentNode = top[0]; // top[1] is weight of node 
            this.calculateWeight(currentNode,pq);
        }
        return this.restorePath(src, dist)
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
let g = new Graph();
g.addNode(0);
g.addNode(1);
g.addNode(2);
g.addNode(3);
g.addNode(4);
g.addEdge(0, 1, 2)
g.addEdge(1, 2, 2)
g.addEdge(0, 3, 8)
g.addEdge(2, 3, 1)



console.log(g.Dks(0, 3));
console.log(g.getWeight(3));
