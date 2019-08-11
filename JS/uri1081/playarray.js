var arr = Array(4).fill(null).map(() => Array(4).fill(false));

arr[0][0] = true;
console.info(arr);