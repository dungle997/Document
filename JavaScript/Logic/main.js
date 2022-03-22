// if else; Lệnh rẽ nhánh Switch case

// var date = 60;

// switch(date){  // ===

//     case 2:
//         console.log('Hom nay la thu hai');
//         break;
//     case 3: 
//         console.log('Hom nay la thu ba');
//         break;
//     case 4: 
//         console.log('Hom nay la thu tu');
//         break;

//     case 5:
//     case 6:
//         console.log('Hom nay la chu nhat');
//         break;
//     default:
//         console.log('Khong ro');

// }
// ít hơn 3 case nên dùng if else

// --------------------------------------------------------------
// Toán tử 3 ngôi (Ternary operator)
// var course = {
//     name: 'Javascript',
//     coin: 250
// }

// var result = course.coin > 0 ? `${course.coin} Coins` : 'Mien phi'

// console.log(result)
// --------------------------------------------------------------
/* Vòng lặp
    1. for - Lặp với điều kiện đúng
    2. for/in - Lặp qua key của đối tượng
    3. for/of - Lặp qua value của đối tượng 
    4. while - Lặp khi điều kiện đúng 
    5. do/white - Lặp ít nhất 1 lần, sau đó lặp khi điều kiên đúng 
*/

// 1. for
    // for(var i = 1; i <= 1000; i++){

    // }
// ---------------------------
    // var i =1 
    // for(;i <= 10; i++){
        // console.log('Van chay binh thuong')
        // console.log(i)
// 
    // }
    // var myArray = [
    //     'Javascript',
    //     'PHP',
    //     'Java',
    //     'Dart'
    // ]

    // // for (var i= 0; i< myArray.length ; i++){
    // //     console.log(myArray[i])
    // // }

    // // Tối ưu hơn 

    // var arrayLength = myArray.length;   
    // for (var i= 0; i< arrayLength  ; i++){
    //     console.log(myArray[i])
    // }
// ------------------------------------------------------------
// 2. Vòng lặp for/in
// object 
// var myInfo = {
//     name: 'Dung Le',
//     age: 18,
//     address: 'Hanoi, vn'
// };

// for(var key in myInfo){
//     // chạy 3 lần do có 3 key
//     console.log(key); //string 'name' 'age' 'address'
//     console.log(myInfo[key]);
// }

// array
// var myArray1 = [
//     'Javascript',
//     'Javasssssscript',
//     'Javdsascript',
//     'avc',
// ]
// for (var key in myArray1){
//     console.log(key)
//     console.log(myArray1[key]);
// }

// var myString = 'Hello World';
// for (var key in myString){
//     console.log(key)
//     console.log(myString[key])
// }
// -----------------------------------------------------------------
// 3. Vòng for/of 
/* array
var myArray2 = [
        'Javascript',
        'Javasssssscript',
        'Javdsascript',
        'avc',
    ];

    for (var value of myArray2){
        console.log(value)
        // console.log(myArray2[value]);
    }

var myString = 'Hello World';
for (var value of myString){
    console.log(value);
}
*/

/* object 
    
var myInfo = {
        name: 'Dung Le',
        age: 18,
        address: 'Hanoi, vn'
    };
 // Cách này không dùng được    
for (var value of myInfo){
    console.log(value);
}

//Cách Đúng  1
for (var value of Object.keys(myInfo)) {
    console.log(value);
    console.log(myInfo[value]);

}
//Cách Đúng 2
for (var value of Object.values(myInfo)){
    console.log(value)
}
*/

// ----------------------------------------------------------
// 4. Vòng lặp while
/*
var i = 1;
while (i < 1000){
    console.log(i);
    i++;
}
 */
// --------------------------------------------------------------

/*
5. Vòng lặp Do - while 
var i = 0;
do{
    i++;
    console.log(i);
}
while (i < 10);
6. Break và Continue
7. Vòng lặp lồng nhau Nested loop 
*/
/*
var myArray7 = [
    [1, 2],
    [3, 4],
    [5, 6]
];
for (var i = 0; i < myArray7.length; i++){
    for (var j=0 ; j < myArray7[i].length; j++){
        console.log(myArray7[i][j]);
    }
}

for(var i=100; i > 0; i--){
    console.log(i);
} 
*/


