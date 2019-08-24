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
        let weight = {};
        let backtrace = {};
        let pq = new PriorityQueue();
        weight[startNode] = 0;
        this.nodes.forEach(node => {
            if (node !== startNode) {
                weight[node] = Infinity
            }
        });
        pq.enqueue([startNode, 0]);
        while (!pq.isEmpty()) {
            let shortestStep = pq.dequeue();
            let currentNode = shortestStep[0];
            this.adjacencyList[currentNode].forEach(edge => {
                let sumWeight = weight[currentNode] + edge.weight;
                if (sumWeight < weight[edge.node]) {
                    weight[edge.node] = sumWeight; //replace weight
                    backtrace[edge.node] = currentNode; //  backtrace connection
                    pq.enqueue([edge.node, sumWeight]);
                }
            });
        }
        return this.restorePath(startNode,endNode,backtrace)
    }

    restorePath(start, end, backtrace) {
        let path = [end];
        let lastStep = end;
        while (lastStep !== start) {
            path.unshift(backtrace[lastStep]) // add value to front 
            lastStep = backtrace[lastStep]
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

g.addEdge(0 ,1 ,2)
g.addEdge(1 ,4 ,5)
g.addEdge(1 ,2 ,4)
g.addEdge(0 ,3, 1)
g.addEdge(3 ,2 ,3)
g.addEdge(2, 4, 1)
console.log(g.findPathWithDijkstra(0, 4));