const a = [
    [1, 4],
    [5, 7],
    [3],
    [],
    [2],
    [6],
    [],
    [8],
    [],
    [],
    [11],
    []
];
/*console.log(a[0][0]);
console.log(a[a[0][0]][0]);
console.log(a[a[a[0][0]][0]][0]);*/ 
let visited = new Array(12).fill(false);
const R = (v, blank = 'bb') => {
    if (!visited[v]) {
        visited[v] = true;
        a[v].forEach((value, key) => {
            console.log(`${blank}${v}-${value} pathR(G,${value}) `);
            R(value, blank += 'bb')
        })
    }
}
R(0);
console.log();
visited.forEach((value, index) => !value ? R(index) : '' )
