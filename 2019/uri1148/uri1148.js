const input = require('fs').readFileSync('uri1148/input.txt', 'utf8');
let lines = input.split('\n');
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
    constructor(TotalOfVertex) {
        this.nodes = [];
        this.adj = Array(TotalOfVertex).fill(TotalOfVertex).map(() =>
            Array(TotalOfVertex).fill(Infinity)
        );
        this.weight = new Array(TotalOfVertex).fill(Infinity);
        this.path = {};
        this.visited = new Array(TotalOfVertex).fill(false);
        this.total = TotalOfVertex;
    }
    addEdge(src, dist, w) {
        this.adj[src][dist] = w;
        if (this.adj[dist][src] != Infinity)
            this.adj[src][dist] = this.adj[dist][src] = 0;
    }

    dks(src, dist) {
        let w = new Array(this.total).fill(Infinity);
        let visited = new Array(this.total).fill(false);
        w[src] = 0;
        let nextv;
        for (let i = 1; i < this.total; i++) {
            let short_dis = Infinity
            if (visited[dist]) {
                break;
            }

            for (let j = 1; j < this.total; j++) {
                if (w[j] < short_dis && !visited[j]) {
                    short_dis = w[j];
                    nextv = j
                }
            }
            if (short_dis == Infinity)
                break;
            visited[nextv] = true;
            for (let j = 1; j < this.total; j++)
                if (short_dis + this.adj[nextv][j] < w[j])
                    w[j] = short_dis + this.adj[nextv][j];
        }
        return w[dist];
    }
}

let n = 0;
let contaner = lines[n++].split(` `);
//console.log(contaner);

let v = parseInt(contaner[0]);
let e = parseInt(contaner[1]);
let g = new Graph(v + 1);
let start = n
console.log(`n=${start}`);

for (let i = start; i < e +start; i++) {
    //console.log(`i=${i}`);
    let value = lines[i].split(` `);
    let src = parseInt(value[0]);
    let dist = parseInt(value[1]);
    let w = parseInt(value[2]);
    console.log(src, dist, w);

    g.addEdge(src, dist, w);
    n++;
}
let k = lines[n++];
while (k--) {
    let tc = lines[n++].split(` `);
    let src = parseInt(tc[0]);
    let dist = parseInt(tc[1]);
    //console.log(src, dist);
    let result = g.dks(src, dist)
    if (result == Infinity) {
        console.log(`Nao e possivel entregar a carta`);
    }else{
        console.log(`${ result}`);
    }
   
}



/*

Input Sample	Output Sample
4 5
1 2 5
2 1 10
3 4 8
4 3 7
2 3 6
5
1 2
1 3
1 4
4 3
4 1
*/