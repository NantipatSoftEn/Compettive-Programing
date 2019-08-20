class Graph {
    constructor(TotalOfVertex) {
        this.TotalOfVertex = TotalOfVertex;
        //this.AdjMetrix = new Array(TotalOfVertex).fill(null).map(() => Array(TotalOfVertex).fill(0));
        this.AdjList = new Map()
        this.visited = new Array();
    }
    addNode(node) {
        this.AdjList.set(node, []);
    }

    addEdge(node1, node2, weight) {
        this.AdjList.get(node1).push({
            node: node2,
            weight: weight
        })
    }

    printAbjList() {
        console.log(this.AdjList);

    }
    Dijkstra(src, dist) {
        
    }
}

const g = new Graph(4);

g.addNode(0);
g.addNode(1);
g.addNode(2);
g.addNode(3);
g.addEdge(0, 1, 2)
g.addEdge(1 ,2, 3)
g.addEdge(0, 2, 3)
g.addEdge(0, 3, 4)
g.addEdge(3, 2, 0)

g.printAbjList();