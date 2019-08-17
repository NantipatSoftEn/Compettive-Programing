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
        return this.items
    }
}
class Node {
    constructor(x,y,count=0){
        this.x = x
        this.y = y
        this.count = count
    }
    dfs(NodeX,NodeY){
        
    }
}

const q= new Queue()
const n = new Node(2,4,0)


const m = new Node(2,4,0)
q.enqueue(n)
q.enqueue(m)
console.log(q.printQueue());

