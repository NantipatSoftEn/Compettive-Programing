
class Graph {
    constructor(maxRow,maxCol, screen){
        this.maxRow= maxRow
        this.maxCol= maxCol
        this.screen = screen
    }
    floodFill(screen, x, y, newValue){
        
    }
    floodFillUtil(screen,  x,  y,  prevValue,  newValue){
        if (x < 0 || x >= M || y < 0 || y >= N) {
            return 
        }
    
        if(screen[x][y] != prevC){
            return 
        }
    
        screen[x][y] = newValue; 
        floodFillUtil(screen, x+1, y, prevValue, newValue); 
        floodFillUtil(screen, x-1, y, prevValue, newValue); 
        floodFillUtil(screen, x, y+1, prevValue, newValue); 
        floodFillUtil(screen, x, y-1, prevValue, newValue); 
    }
}


const N=8,M=8
const  floodFillUtil = (screen,  x,  y,  prevC,  newC) => {
    if (x < 0 || x >= M || y < 0 || y >= N) {
        return 
    }

    if(screen[x][y] != prevC){
        return 
    }

    screen[x][y] = newC; 
    floodFillUtil(screen, x+1, y, prevC, newC); 
    floodFillUtil(screen, x-1, y, prevC, newC); 
    floodFillUtil(screen, x, y+1, prevC, newC); 
    floodFillUtil(screen, x, y-1, prevC, newC); 
};

const floodFill= (screen, x, y, newC) => {
    let  prevC = screen[x][y]; 
    floodFillUtil(screen, x, y, prevC, newC); 
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

let  x = 4, y = 4, newC = 4; 
floodFill(screen, x, y, newC); 
console.log(screen);
