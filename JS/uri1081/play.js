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
    [8]
];
/*console.log(a[0][0]);
console.log(a[a[0][0]][0]);
console.log(a[a[a[0][0]][0]][0]);*/

const R = (v) => {
    a[v].forEach((value,key) => {
        console.log(`${v}-${value} `);
        R(value)
    }) 
}
R(0);