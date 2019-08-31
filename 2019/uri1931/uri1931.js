const input = require('fs').readFileSync('uri1931/input.txt', 'utf8');
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
    }

    isEmpty() {
        return (this.collection.length === 0)
    }
}

class Graph {
    constructor(TotalOfVertex) {
        this.nodes = [];
        this.adj = {};
        this.weight = new Array(TotalOfVertex).fill(Infinity);
        this.path = new Array();
        this.total = TotalOfVertex;
        for (let i = 0; i < this.total; i++) {
            this.addNode(i);
        }
    }
    addEdge(src, dist, w) {
        this.adj[src].push({
            n: dist,
            w: w
        })
        this.adj[dist].push({
            n: src,
            w: w
        })
    }

    addNode(src) {
        this.adj[src] = []
    }

    dks(src, dist, adj2) {
        let pq = new PriorityQueue();
        this.weight[src] = 0;
        pq.enqueue([src, 0])
        while (!pq.isEmpty()) {
            let top = pq.dequeue();
            let currentNode = top[0];
            let currentWeight = top[1];         
            if (this.weight[currentNode] > currentWeight)
                continue;
            this.calculateWeight(currentNode, currentWeight, pq, adj2);
        }
        return this.weight[dist];
    }
    calculateWeight(currentNode, currentWeight, pq, adj2) {
        adj2[currentNode].forEach(element => {
            if (currentWeight + element.w < this.weight[element.n]) {
                this.weight[element.n] = currentWeight + element.w;
                this.path.push(element.n);
                pq.enqueue([element.n, this.weight[element.n]]);
            }
        });
    }
    restorePath(src, dist) {
        let path = [dist];
        let lastStep = dist;
        while (lastStep !== src) {
            path.unshift(this.path[lastStep]) // add value to front 
            lastStep = this.path[lastStep]
        }
        return `Path is ${path}`
    }


}
const dfs = (at,adj1, adj2, visited, src) => {
    console.log(`beginStart=${src}`);
    if (!visited[src]) {
        console.log(`First COME`);
        
        visited[src] = true;
        adj1[src].forEach(i => {
            console.log(`adj1[${src}]=${i.n} => `);
            adj1[i.n].forEach(j => {
                console.log(`at start= ${i.n}, to = ${j.n} wstart=${i.w} wto=${j.w}`);
                
                adj2[src].push({
                    n: j.n,
                    w: i.w + j.w
                })
                dfs(at,adj1, adj2, visited, j.n)
                console.log(`=====End point Start ${src}`);
                
            })
        })

    }
}
const addNode = (adj2, node) => {
    adj2[node] = []
}
try {
    let n = 0;
    const contaner = lines[n++].split(` `);
    let v = parseInt(contaner[0]);
    let e = parseInt(contaner[1]);
    let g = new Graph(v + 1);
    let adj2 = {}
    for (let i = 0; i < v + 1; i++) {
        addNode(adj2, i)
    }
    let visited = new Array(v + 1).fill(false);
    for (let i = n; i <= e; i++) {
        let value = lines[n++].split(` `);
        let src = parseInt(value[0]);
        let dist = parseInt(value[1]);
        let w = parseInt(value[2]);
        g.addEdge(src, dist, w)
    }

    dfs(g.adj, adj2, visited, 1)

    const result = g.dks(1, v, adj2);
    if (result !== Infinity) {
        console.log(result);
    } else {
        console.log(`-1`);
    }
    console.log(`Path =${g.path}`);
    
    console.log(g.adj);
    console.log(`============`);

    console.log(adj2);
} catch (e) {
    console.log('error' + e);
}


/*  เวลาเดินทางต้องเป็นเลยคู่เสมอข้อนี้เวลาเขียนเลยต้องเริ่มจาก 2 node โดยใช้ dfs  เพื่อหา weight รวม
เสร็จแล้วใช้ dks หาเส้นทางที่ weight น้อยุสุดไปยังปลายทาง */

