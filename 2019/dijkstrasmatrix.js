class Graph {
    constructor(TotalOfVertex) {
        this.TotalOfVertex = TotalOfVertex;
        this.AdjMetrix = Array(TotalOfVertex).fill(null).map(() => Array(TotalOfVertex).fill(0));
    }

    addEdge(src, dest, w) {
        this.AdjMetrix[src][dest] = w
        this.AdjMetrix[dest][src] = w
    }

    getMinimumVertex(mst, key) {
        let minKey = Infinity,
            vertex = -1
        for (let i = 0; i < this.TotalOfVertex; i++) {
            if (mst[i] === false && minKey > key[i]) {
                minKey = key[i]
                vertex = i
            }
        }
        return vertex
    }

    dijkstra_GetMinDistances(sourceVertex) {
        let spt = new Array(this.TotalOfVertex)
        let distance = new Array(this.TotalOfVertex)

        for (let i = 0; i < this.TotalOfVertex; i++) {
            distance[i] = Infinity
        }

        distance[sourceVertex] = 0

        for (let i = 0; i < this.TotalOfVertex; i++) {
            let vertex_u = this.getMinimumVertex(spt, distance)

            spt[vertex_u] = true;

            for (let vertex_v = 0; vertex_v < this.TotalOfVertex; vertex_v++) {
                if (this.AdjMetrix[vertex_u][vertex_v] > 0) {
                    if (spt[vertex_v] == false && this.AdjMetrix[vertex_u][vertex_v] != Infinity) {
                        let newKey = this.AdjMetrix[vertex_u][vertex_v] + distance[vertex_u]
                        if (newKey < distance[vertex_v]) {
                            distance[vertex_v] = newKey
                        }
                    }
                }
            }
        }
        printDijkstra(sourceVertex, distance);
    }

    printDijkstra(sourceVertex, key) {
        for (let i = 0; i < this.TotalOfVertex; i++) {
            console.log(`${sourceVertex},${key[i]}`);
        }
    }
}

let graph = new Graph(6);

graph.addEdge(0, 1, 4);
graph.addEdge(0, 2, 3);
graph.addEdge(1, 2, 1);
graph.addEdge(1, 3, 2);
graph.addEdge(2, 3, 4);
graph.addEdge(3, 4, 2);
graph.addEdge(4, 5, 6);
graph.dijkstra_GetMinDistances(0);