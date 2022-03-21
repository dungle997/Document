// // C1:

// var languages = [
//     'Javascript',
//     'PHP',
//     'Ruby',
//     123,
//     null,
//     undefined,
//     function(){

//     }, 
//     myObject = {
//         name : 'DungLQ',
//         'age' : 18
//     } //object
// ];

// console.log(languages)

// // C2

// var lan = new Array(
//     'Javascript',
//     'PHP',
//     'Ruby',
//     123,
//     null,
//     undefined,
//     function(){

//     }, 
//     myObject = {
//         name : 'DungLQ',
//         'age' : 18
//     } //object
// );
// console.log(lan)

// console.log(typeof {})
// console.log(typeof [])
// console.log(Array.isArray(languages))
// console.log(Array.isArray({}))
// console.log(languages.length)

// -------------------------------------------------------------
// JS array method

// 1. To String
// 2. Join       Chuyển mảng thành string và có thể thay đổi dấu ngăn cách 
// 3. Pop        Xóa phần tử ở cuối mảng 
// 4. Push       Đẩy phần từ vào cuối mảng 
// 5. Shift      Xóa phần tử ở đầu mảng 
// 6. Unshift    Đẩy phần tử vào đầu mảng 
// 7. Splicing   // (position, length, element muốn truyền vào)  Xóa từ vị trí với số lượng length
// 8. Concat     Nối 2 array với nhau
// 9. Slicing    Cắt Element trong array

var languages = [
    'Javascript',
    'PHP',
    'Ruby'
];
var languages2 = [
    'Dart',
    'Rubu'
]

// console.log(typeof languages.toString())
// console.log(languages.join(', '))
// console.log(languages.pop()) // Xóa element cuối mảng và trả về phần từ đã xóa
// console.log(languages)
// console.log(languages.push('Dart', 'Java'))
// console.log(languages)
// languages.splice(1, 1) // (position, length, element muốn truyền vào)  Xóa từ vị trí với số lượng length
// languages.splice(1, 0, 'Dart', 'Java')
// console.log(languages)
console.log(languages.concat(languages))

console.log(languages.slice(1, 2))

console.log(languages.slice(0)) //copy mảng


