class Queue {
    // Array is used to implement a Queue 
    constructor() {
        this.items = [];
    }
    enqueue(element) {

        this.items.push(element);
    }
    dequeue() {

        if (this.isEmpty())
            return "Underflow";
        return this.items.shift();
    }
    front() {

        if (this.isEmpty())
            return "No elements in Queue";
        return this.items[0];
    }
    isEmpty() {
        return this.items.length == 0;
    }
    printQueue() {
        var str = "";
        for (var i = 0; i < this.items.length; i++)
            str += this.items[i] + " ";
        return str;
    }
}





class Graph {

    constructor(noOfVertices) {
        this.noOfVertices = noOfVertices;
        this.AdjList = new Map();
    }
    addVertex(v) {
        this.AdjList.set(v, []);
    }
    addEdge(v, w) {
        this.AdjList.get(v).push(w);
        this.AdjList.get(w).push(v);
    }
    printGraph() {
        var get_keys = this.AdjList.keys();
        for (var i of get_keys) {
            var get_values = this.AdjList.get(i);
            var conc = "";
            // iterate over the adjacency list 
            // concatenate the values into a string 
            for (var j of get_values)
                conc += j + " ";
            // print the vertex and its adjacency list 
            console.log(i + " -> " + conc);
        }
    }

    bfs(startingNode) {

        // create a visited array 
        var visited = [];
        for (var i = 0; i < this.noOfVertices; i++)
            visited[i] = false;

        // Create an object for queue 
        var q = new Queue();

        // add the starting node to the queue 
        visited[startingNode] = true;
        q.enqueue(startingNode);

        // loop until queue is element 
        while (!q.isEmpty()) {
            // get the element from the queue 
            var getQueueElement = q.dequeue();

            // passing the current vertex to callback funtion 
            console.log(getQueueElement);

            // get the adjacent list for current vertex 
            var get_List = this.AdjList.get(getQueueElement);

            // loop through the list and add the element to the 
            // queue if it is not processed yet 
            for (var i in get_List) {
                var neigh = get_List[i];

                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.enqueue(neigh);
                }
            }
        }
    }

    dfs(startingNode) {

        var visited = [];
        for (var i = 0; i < this.noOfVertices; i++)
            visited[i] = false;

        this.DFSUtil(startingNode, visited);
    }

    // Recursive function which process and explore 
    // all the adjacent vertex of the vertex with which it is called 
    DFSUtil(vert, visited) {
        visited[vert] = true;
        console.log(vert);

        var get_neighbours = this.AdjList.get(vert);

        for (var i in get_neighbours) {
            var get_elem = get_neighbours[i];
            if (!visited[get_elem])
                this.DFSUtil(get_elem, visited);
        }
    }
}

var g = new Graph(6);
var vertices = ['A', 'B', 'C', 'D', 'E', 'F'];
for (var i = 0; i < vertices.length; i++) {
    g.addVertex(vertices[i]);
}

g.addEdge('A', 'B');
g.addEdge('A', 'D');
g.addEdge('A', 'E');
g.addEdge('B', 'C');
g.addEdge('D', 'E');
g.addEdge('E', 'F');
g.addEdge('E', 'C');
g.addEdge('C', 'F');
console.log("DFS"); 
g.bfs('B')

//https://www.geeksforgeeks.org/implementation-graph-javascript/