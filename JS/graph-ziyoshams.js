class Graph {
    constructor() {
        this.AdjList = new Map();
    }

    addVertex(vertex) {
        !this.AdjList.has(vertex) ? this.AdjList.set(vertex, []) : console.log('Already Exist!!!');
    }

    getAdjList() {
        return this.AdjList;
    }

    addEdge(vertex, node) {
        this.AdjList.get(vertex);
    }

    print() {
        for (let [key, value] of this.AdjList) {
            console.log(key, value);
        }
    }

    createVisitedObject() {
        let arr = {};
        for (let key of this.AdjList.keys()) {
            arr[key] = false;
        }
        return arr;
    }

    bfs(startingNode) {
        let visited = this.createVisitedObject();
        let q = [];

        visited[startingNode] = true;
        q.push(startingNode);

        while (q.length) {
            let current = q.pop()
            console.log(`${current}`);

            let arr = this.AdjList.get(current);

            for (let elem of arr) {
                if (!visited[elem]) {
                    visited[elem] = true;
                    q.unshift(elem)
                }
            }
        }
    }

    dfs(startingNode) {
        console.log('\nDFS')
        let visited = this.createVisitedObject();
        this.dfsHelper(startingNode, visited);
    }

    dfsHelper(startingNode, visited) {
        visited[startingNode] = true;
        console.log(startingNode);

        let arr = this.AdjList.get(startingNode);

        for (let elem of arr) {
            if (!visited[elem]) {
                this.dfsHelper(elem, visited);
            }
        }
    }

    doesPathExist(firstNode, secondNode) {
        // we will approach this BFS way
        let path = [];
        let visited = this.createVisitedObject();
        let q = [];
        visited[firstNode] = true;
        q.push(firstNode);
        while (q.length) {
            let node = q.pop();
            path.push(node);
            let elements = this.AdjList.get(node);
            if (elements.includes(secondNode)) {
                console.log(path.join('->'))
                return true;
            } else {
                for (let elem of elements) {
                    if (!visited[elem]) {
                        visited[elem] = true;
                        q.unshift(elem);
                    }
                }
            }
        }
        return false;
    }

}

function test(arg1, arg2) {
    if (arg1 === arg2) {
        console.log(`${arg1} = ${arg2} \t-> passing`)
    } else {
         'Not passing';
    }
}
let g = new Graph();
let arr = ['A', 'B', 'C', 'D', 'E', 'F'];

arr.forEach(arr => g.addVertex(arr))

g.addEdge('A', 'B');
g.addEdge('A', 'D');
g.addEdge('A', 'E');
g.addEdge('B', 'C');
g.addEdge('D', 'E');
g.addEdge('E', 'F');
g.addEdge('E', 'C');
g.addEdge('C', 'F');
g.print();

g.bfs('A');
g.dfs('A');

console.log('\nTESTS')
// TESTS FOR 'A'
test(g.doesPathExist('A', 'A'), false);
test(g.doesPathExist('A', 'B'), true);
test(g.doesPathExist('A', 'C'), true);
test(g.doesPathExist('A', 'D'), true);
test(g.doesPathExist('A', 'E'), true);
test(g.doesPathExist('A', 'F'), true);

// // TESTS FOR 'B'
// test(g.doesPathExist('B', 'A'), false)
// test(g.doesPathExist('B', 'B'), false)
// test(g.doesPathExist('B', 'C'), true)
// test(g.doesPathExist('B', 'D'), false)
// test(g.doesPathExist('B', 'E'), false)
// test(g.doesPathExist('B', 'F'), true)

// // TESTS FOR 'C'
// test(g.doesPathExist('C', 'A'), false)
// test(g.doesPathExist('C', 'B'), false)
// test(g.doesPathExist('C', 'C'), false)
// test(g.doesPathExist('C', 'D'), false)
// test(g.doesPathExist('C', 'E'), false)
// test(g.doesPathExist('C', 'F'), true)

// // TESTS FOR 'D'
// test(g.doesPathExist('D', 'A'), false)
// test(g.doesPathExist('D', 'B'), false)
// test(g.doesPathExist('D', 'C'), true)
// test(g.doesPathExist('D', 'D'), false)
// test(g.doesPathExist('D', 'E'), true)
// test(g.doesPathExist('D', 'F'), true)

// // TESTS FOR 'E'
// test(g.doesPathExist('E', 'A'), false)
// test(g.doesPathExist('E', 'B'), false)
// test(g.doesPathExist('E', 'C'), true)
// test(g.doesPathExist('E', 'D'), false)
// test(g.doesPathExist('E', 'E'), false)
// test(g.doesPathExist('E', 'F'), true)

// // TESTS FOR 'F'
// test(g.doesPathExist('F', 'A'), false);
// test(g.doesPathExist('F', 'B'), false);
// test(g.doesPathExist('F', 'C'), false);
// test(g.doesPathExist('F', 'D'), false);
// test(g.doesPathExist('F', 'E'), false);
// test(g.doesPathExist('F', 'F'), false);

//https://medium.com/@ziyoshams/graphs-in-javascript-cc0ed170b156