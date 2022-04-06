/*
Kiểu số number trong JavaScript
1. Tạo gía trị Number
    - Các cách tạo
    - Dùng cách nào? Tại sao
    - Kiểm tra data type
2. Làm việc với Number
    - To String
    - To Fixed

Keyword: Javascript number methods
*/
// var age =18;
// var otherNumber = new Number(9);

// // Tránh cách sử dụng new 
// var result = 20 / 'ABC';
// console.log(result);
// console.log(typeof result);
// console.log(isNaN(result));
//2 
// var PI = 3.1416145893;
// console.log(PI.toFixed(8))

// Viết code tại đây
// function isNumber(value){
//     console.log(typeof value);
//     if (typeof value == 'number'){
//         return true;
//     }else{
//         return false;
//     }
// }



// // Kì vọng đạt được
// console.log(isNumber(999)); // true
// console.log(isNumber('abc')); // false
// console.log(isNumber('100')); // false

// Viết code tại đây
function isNumber(value){
        console.log('type', typeof value);
        console.log('sfsf', isNaN(value))
        return typeof value ==='number' && !isNaN(value);
}



// Kì vọng đạt được
console.log(isNumber(999)); // true
console.log(isNumber('abc')); // false
console.log(isNumber('100')); // false

console.log(isNumber(NaN)); // false type của NaN cũng là number
console.log(isNumber(100 / '10')); // false
console.log(100 / '10'); // false

