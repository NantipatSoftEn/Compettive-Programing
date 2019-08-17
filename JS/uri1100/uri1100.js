const input = require('fs').readFileSync('uri1100/input.txt', 'utf8');
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
        return this.items.length === 0;
    }
    printQueue() {
        return this.items;
    }
}
class Node {
    constructor(x, y, count = 0) {
        this.x = x;
        this.y = y;
        this.count = count;
    }

}

const map = [7, 6, 5, 4, 3, 2, 1, 0];
const getIndexBy = char => (char.charCodeAt(0) - 97);
const revers = index => map[index - 1];


const row = [2, 2, -2, -2, 1, 1, -1, -1];
const col = [-1, 1, 1, -1, 2, -2, 2, -2];
let result = 0;
const bfs = (Node1, Node2) => {
    let q = new Queue();
    q.enqueue(Node1);
    while (!q.isEmpty()) {
        let node = q.front();
        q.dequeue();
        let x = node.x;
        let y = node.y;
        let count = node.count;
        //console.log(x, y, count);
        if (x == Node2.x && y == Node2.y) {
            result = count;
            break;
        }

        for (let i = 0; i < 8; i++) {
            let moveX = x + row[i];
            let moveY = y + col[i];
            if (x >= 0 && y >= 0 && x < 8 && y < 8) {
                const newNode = new Node(moveX, moveY, count + 1);
                q.enqueue(newNode);
            }
        }

    }
};
    let l = lines.length
    while(l--){
        let testcase = lines.shift().split(` `);
        let start = testcase[0];
        let end = testcase[1];
        let charStart = start[0].toString();
        let numberStart = parseInt(start[1]);
        let charEnd = end[0].toString();
        let numberEnd = parseInt(end[1]);
        
        //console.log(`${revers(numberStart)},${getIndexBy(charStart)}`);
        //console.log(`${revers(numberEnd)},${getIndexBy(charEnd)}`);
        
        let src = new Node(revers(numberStart), getIndexBy(charStart));
        let dest = new Node(revers(numberEnd), getIndexBy(charEnd));
        bfs(src, dest);
        console.log(`To get from ${start} to ${end} takes ${result} knight moves.`);
    
    }


