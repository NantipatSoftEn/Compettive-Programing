var lines = readline().split('\n');
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
                //console.log(`c=${currentNode},node=${edge.node},w=${edge.weight}`);

                if (sumWeight < weight[edge.node]) {
                    weight[edge.node] = sumWeight; //replace weight
                    backtrace[edge.node] = currentNode; //  backtrace connection
                    console.log(`backtrace[${edge.node}] = ${currentNode} , ${  backtrace[edge.node] }`);

                    pq.enqueue([edge.node, sumWeight]);
                }
            });
        }


        let path = [endNode]; // for keep  when backtracking
        //console.log(`path=${path}`);

        let lastStep = endNode;
        while (lastStep !== startNode) {
            path.unshift(backtrace[lastStep]) // add value to front 
            //console.log(`backtrace=${backtrace[lastStep]}`);
            lastStep = backtrace[lastStep]
        }
        return `Path is ${path} and time is ${weight[endNode]}`
    }
}



while ((num = readline()) != 42) {
    let g = new Graph();
    g.addNode(0);
    g.addNode(1);
    g.addNode(2);
    g.addNode(3);
    g.addEdge(0, 1, 2)
    g.addEdge(1, 2, 3)
    g.addEdge(0, 2, 3)
    g.addEdge(0, 3, 4)
    g.addEdge(3, 2, 0)

    //console.log(g.adjacencyList);

    console.log(g.findPathWithDijkstra(0, 3));
}