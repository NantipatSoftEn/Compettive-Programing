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
        this.adjacencyList = {};
        this.weight = {};
        this.path = {};
    }

    addNode(node) {
        this.nodes.push(node);
        this.adjacencyList[node] = [];
    }

    addEdge(node1, node2, weight) {
        this.adjacencyList[node1].push({
            node: node2,
            weight: weight
        });
        this.adjacencyList[node2].push({
            node: node1,
            weight: weight
        });
    }
    findPathWithDijkstra(startNode, endNode) {
        let pq = new PriorityQueue();
        this.weight[startNode] = 0;
        this.nodes.forEach(node => {
            if (node !== startNode) {
                this.weight[node] = Infinity
            }
        });
        pq.enqueue([startNode, 0]);
        while (!pq.isEmpty()) {
            let shortestStep = pq.dequeue();
            let currentNode = shortestStep[0];
            this.adjacencyList[currentNode].forEach(edge => {
                let sumWeight = this.weight[currentNode] + edge.weight;
                if (sumWeight < this.weight[edge.node]) {
                    this.weight[edge.node] = sumWeight; //replace weight
                    this.path[edge.node] = currentNode; //  backtrace connection
                    pq.enqueue([edge.node, sumWeight]);
                }
            });
        }
        console.log(`W=${this.weight[endNode]}`);
        return this.restorePath(startNode, endNode, this.path)
    }

    restorePath(start, end, ) {
        let path = [end];
        let lastStep = end;
        while (lastStep !== start) {
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
g.addEdge(0, 1, 5)
g.addEdge(1, 2, 10)
g.addEdge(0, 2, 8)


console.log(g.findPathWithDijkstra(0, 2));