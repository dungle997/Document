// var fullName = 'Le qung dung';
// alert(fullName);
// alert('asdfasf');
// console.log(fullName);
// console.error(fullName);

// confirm('Xac nhan ban dung');
// prompt('Xac nhan ban du tuoi');
// setTimeout(function(){
//     alert('Thong Bao')
// }, 1000)
// setInterval(function(){
//     console.log('alo alo alo ' + Math.random())
// }, 2000)
// var a = 7, b =2.12563;
// var c = 1;
// c += a;
// console.log(c);

// --------------------------------------------------------
// var firstName = 'Le';
// var lastName = 'Dung';
// firstName += ' firstName';

// console.log(firstName);
// --------------------------------------------------------
// var a =5 ;
// var b =2 ;
// var isSuccess = a >b;
// console.log(isSuccess);
// -------------------------------------------------------
/* 
if else
- 0 
- false
- '' - ""
- undefined
- NaN
- null
=> convert sang boolean là false
còn lại là đều đúng 
*/

/*
    Kiểu dữ liệu trong JavaScript

    1. Dữ liệu nguyên thủy - Primitive Data
        - Number
        - String
        - Boolean
        - Undefined
        - Null
        - Symbol

    2. Dữ liệu phức tạp - Complex Data
        - Function
        - Object
*/

// var a =1;
// console.log('type =' ,typeof a)
// // undefined
// var undefined;
// console.log(undefined);
// // null
// var isNull = null; // nothing
// console.log(isNull);

// Symbol

// var id = Symbol('id'); //unique
// var id2 = Symbol('id');
// console.log(id === id2);
// Với đặc tính unique thì id chỉ có duy nhất, nên khi so sánh ra két quả false

// Toán tử so sánh === không thực hiện chuyển đổi loại 
// Toán tử so sánh == có thực hiện chuyển đổi loại. VD: 9 == "9" +> true | 9 === "9" => false 
// var myFuntion = function(){
//     alert('Hi xin chao cac ban');
// }
// myFuntion();



// ------------------------------------
// Object
// var myObject = {
//     name : "LE Dung",
//     'age' : 18,
//     'address': 'sfasdfkjdshfa',
//     myFuntion: function(){

//     }
// };
// // console.log('myObject', myObject);
// var myArray = ['le hoan', 18, 25];
// console.log('myArray', myArray);


// // Cách nhìn kiểu dữ liệu
// console.log(typeof undefined);
// console.log(typeof isNull); //object
// console.log(typeof myArray);

// ------------------------------------------------
// Toán tử so sánh 

// === không hỗ trợ chuyển kiểu cho kết quả chính xác hơn 
// == có hỗ trợ chuyển kiểu 
// != và !==

// value và datatype

// Câu lệnh điều kiện và phép so sánh 

// var a = 2;
// var b = 1;

// // var result = (a < b && a < 0);
// var result = a < b && a > 0;

// console.log('result =', result);
// if (result){
//     console.log('A < B');
// }
// else{
//     console.log('A > B');
// }
// -----------------------------------------------
// var result1 = 'A' || 'B' || 'C';
// var result1 = null || undefined;

// var result = 'A' && null && 'B' && NaN && 'C';
// console.log('result =',result); 
// console.log('result1 =',result1);

// Toán tử logic

// +) && là tìm kiếm phần tử sai - điều kiện sai (false) trong dãy 6 kiểu dữ liệu false
// xét hết giá trị từ trái qua phải:
// - nguyên dãy true thì lấy phần tử cuối cùng và gán cho biến (dừng lại ở phần tử cuối cùng)
// - Nếu có phần tử false trong dãy thì dừng lại và gán cho biến (nếu nguyên dãy là false thì lấy phần tử đầu)

// +) || là tìm kiếm phần tử đúng - điều kiện đúng (true)
// xét hết giá trị từ trái qua phải:
// - nguyên dãy false thì lấy phần tử cuối cùng và gán cho biến (dừng lại ở phần tử cuối cùng)
// - Nếu có phần tử true trong dãy thì dừng lại và gán cho biến (nếu nguyên dãy là true thì lấy phần tử đầu)

// Tóm tắt: tìm từ trái qua phải -> && tìm false, || tìm true -> && thấy false đâu lấy ở đó, không có thì lấy giá trị cuối - || thấy true đâu lấy ở đó, không có thì lấy giá trị cuối
// ------------------------------------------------
// Quy tắc đặt tên hàm 

// Chứa kí tự từ a-z A-Z 0-9 _ $
// Không đặt số ở kí tự đầu tiên

// function showDialo(){
//     alert('sdfsadfds');
// }

// // showDialo();

// // -------------------------------------
// // Đối số và Tham SỐ
// function writeLog(message){ // Tham Số 
//     console.log(message) // Tham Số 
// }

// writeLog('Tesst Message') // Đối số 
// writeLog(['Tesst Message', 'asdfsdafs']); // Đối số 
// ---------------------------------------------------------

// function writeLog(message, message2){
//     console.log(message2)

//     if(message2){
//         console.log(message2)
//     }
// }
// writeLog('log1 ', 'log 2');
// -------------------------------------------------
// // 3. Arguments? 
// //     - Đối tượng Arguments
// //     - Giới thiệu vòng for

// function writeLog(){
//     var myString = '';
//     for(var param of arguments){
//         // myString += `${param} -`
//         myString += param + '-';
//     }
//     console.log(myString);
// }

// writeLog('sfsdf', 'okbanoi', 'the co à');
// ----------------------------------------------
// Nếu hàm không để return gì thì mặc định sẽ trả về undefined

// function sum(a , b){
//     return a + b;
// }

// c = sum(2, 9);
// console.log('result', c)
// ------------------------------------------------------
// 1. Khi function đặt trùng tên  ---- Hàm sau cùng được định nghĩa
// 2. Khai báo biến trong hàm    ----ok
// 3. Định nghĩa hàm trong hàm   ----ok
// ---------------------------------------------
// 1. Declaration function
function show(){

}
// 2. Expresstion Function
var show2 = function(){

}
setTimeout(function(){ // Đặt tên cho ex funtion để dễ hình dung chức năng 

});

var myObject = {
    myFunction: function(){

    }
}
// 3. Arrow function

// Khác nhau giữa 1,2 là 1 có thể gọi trước khi định nghĩa và 2 thì không thể 