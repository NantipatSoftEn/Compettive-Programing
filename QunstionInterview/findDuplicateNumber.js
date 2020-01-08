const arr1 = [1,2,3,4,4,5,6,7]
const arr2 = [1,2,3,4,4,5,5,6,7,8,9]
let count = 0;
for (let i = 0;  i < arr1.length; i++) {
    for (let j = 0;  j < arr2.length; j++) {
        if(arr1[i] == arr2[j]){
            count++;
        }
    }
}
console.log(count);
