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
        let value = this.collection.shift();
        return value;
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
        let times = {};
        let backtrace = {};
        let pq = new PriorityQueue();

        times[startNode] = 0;

        this.nodes.forEach(node => {
            if (node !== startNode) {
                times[node] = Infinity
            }
        });

        pq.enqueue([startNode, 0]);

        while (!pq.isEmpty()) {
            let shortestStep = pq.dequeue();
            let currentNode = shortestStep[0];
            this.adjacencyList[currentNode].forEach(neighbor => {
                let time = times[currentNode] + neighbor.weight;
                if (time < times[neighbor.node]) {
                    times[neighbor.node] = time;
                    backtrace[neighbor.node] = currentNode;
                    pq.enqueue([neighbor.node, time]);
                }
            });
        }
        let path = [endNode];
        let lastStep = endNode;
        while (lastStep !== startNode) {
            path.unshift(backtrace[lastStep])
            lastStep = backtrace[lastStep]
        }
        return `Path is ${path} and time is ${times[endNode]}`
    }
}

let map = new Graph();
map.addNode(0);
map.addNode(1);
map.addNode(2);
map.addNode(3);
map.addNode(4);
map.addNode(5);

map.addEdge(5,2,1)
map.addEdge(2,1,10)
map.addEdge(1,0,1)
map.addEdge(3,0,2)
map.addEdge(3,4,2)
map.addEdge(3,5,3)
map.addEdge(5,4,2)



console.log(map.findPathWithDijkstra(0,5));

