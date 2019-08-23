
class Graph {
    constructor(maxRow,maxCol){
        this.maxRow= maxRow
        this.maxCol= maxCol
    }
    floodFillUtil(board,  x,  y,  prevValue,  newValue){
        if (x < 0 || x >=  this.maxCol || y < 0 || y >= this.maxRow) {
            return 0
        }
    
        if(screen[x][y] != prevValue){
            return 0
        }
    
        board[x][y] = newValue; 
        this.floodFillUtil(board, x+1, y, prevValue, newValue); 
        this.floodFillUtil(board, x-1, y, prevValue, newValue); 
        this.floodFillUtil(board, x, y+1, prevValue, newValue); 
        this.floodFillUtil(board, x, y-1, prevValue, newValue); 
    }
    floodFill(board, x, y, newC) {
        let  prevValue = screen[x][y]; 
        this.floodFillUtil(board, x, y, prevValue, newC); 
        console.log(board);
    }
}


let screen = [
    [1, 1, 1, 1, 1, 1, 1, 1],
    [1, 1, 1, 1, 1, 1, 0, 0],
    [1, 0, 0, 1, 1, 0, 1, 1],
    [1, 2, 2, 2, 2, 0, 1, 0],
    [1, 1, 1, 2, 2, 0, 1, 0],
    [1, 1, 1, 2, 2, 2, 2, 0],
    [1, 1, 1, 1, 1, 2, 1, 1],
    [1, 1, 1, 1, 1, 2, 2, 1]
]
console.log(screen);
console.log('');

let  x = 4, y = 4, newValue = 4; 
let k= new Graph(8,8);
k.floodFill(screen,x,y,newValue)