const input = require('fs').readFileSync('uri1082/input.txt', 'utf8');
let lines = input.split('\n');
class Queue {
    // Array is used to implement a Queue 
    constructor() {
        this.items = [];
    }
    enqueue(element) {
        this.items.push(element);
    }
    dequeue() {
        return this.isEmpty() ? "Underflow" : this.items.shift();
    }
    front() {
        return this.isEmpty() ? "No elements in Queue" : this.items[0];
    }
    isEmpty() {
        return this.items.length == 0;
    }
    printQueue() {
        return this.items.forEach((item, str = "") => str += item + " ");
    }
}


class Graph {
    constructor(noOfVertices) {
        this.noOfVertices = noOfVertices;
        this.AdjMetrix = Array(TotalOfVertex).fill(null).map(() => Array(TotalOfVertex).fill(0));
        this.path = new Map();
        this.visited = new Array(TotalOfVertex).fill(false);
        this.map = ['a', 'b', 'c', 'd', 'e', 'f',
            'g', 'h', 'i', 'j', 'k', 'l',
            'm', 'n', 'o', 'p', 'q', 'r',
            's', 't', 'u', 'v', 'w',
            'x', 'y', 'z'
        ]
    }
    getIndexBy(char) {
        return char.charCodeAt(0) - 97;
    }

    getCharBy(int) {
        return String.fromCharCode(int + 97);
    }

    printVisited() {
        console.table(this.visited);
    }

    addEdge(v1, v2) {
        this.AdjMetrix[v1][v2] = 1
        //this.AdjMetrix[v2][v1] = 1
    }
    printAbjMetrix() {
        console.table(this.AdjMetrix);
    }

    printPath() {
        this.path.forEach((value, key) => console.log(`${key} => ${this.getCharBy(value)}`));
    }

    dfs(vertex1) {
        console.log(`vertex1= ${this.getCharBy(vertex1)}`);
        let path = new Array();
        for (let i = 0; i < this.noOfVertices; i++) {
            if (!this.visited[i]) {
                this.visited[vertex1] = true
                if (this.AdjMetrix[vertex1][i] === 1) {
                    
                    //path.push(this.getCharBy(i));
                    //this.visited[i] = false
                    console.log(`AdjMetrix=${this.AdjMetrix[vertex1][i]} vertex1=${this.getCharBy(vertex1)} i=${this.getCharBy(i)}`);
                    console.log(`${this.getCharBy(vertex1)}=>${this.getCharBy(i)}`);

                    this.dfs(i)
                }
            }
        }
        return path;
    }

    dfs_runner(TotalOfVertex) {
        /*let countConnect = 0;
        for (let v = 0; v < TotalOfVertex; v++) {
            if(!this.visited[v]){
                let result = this.dfs(v)
                console.log(`${this.getCharBy(v)},${result }`);
                countConnect++
            }
        }
        console.log(`${countConnect} connected components`);*/
        let start = 0
        while (true) {
            let result = this.dfs(start)
            console.log(`${this.getCharBy(start)},${result }`);
            start = -1
            for (let i = 0; i < TotalOfVertex; i++) {
                if (!this.visited[i]) {
                    start = i;
                    break;
                }
            }
            if (start === -1) break;
        }

    }
}



let Number = 0
let Testcaee = lines[Number++];
let contaners = lines[Number].split(` `);
let TotalOfVertex = parseInt(contaners[0])
let TotalOfEdge = parseInt(contaners[1])
var g = new Graph(TotalOfVertex);

const start = ++Number
for (let i = start; i < TotalOfEdge + start; i++) {
    const vertex = lines[i].split(' ');
    let v1 = vertex[0].toString().replace(/\n|\r/g, "")
    let v2 = vertex[1].toString().replace(/\n|\r/g, "")


    g.addEdge(g.getIndexBy(v1), g.getIndexBy(v2))
    Number++;
}
g.dfs_runner(TotalOfVertex)
g.printAbjMetrix();