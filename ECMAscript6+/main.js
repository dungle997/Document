// 1. Let, const
// 2. Template Literals
// 3. Multi-line String
// 4. Arrow function
// 5. Classes
// 6. Default parameter values
// 7. Destructuring
// 8. Rest parameters
// 9. Spread
// 10. Enhanced ogject Literals
// 11. Tagged template Literal 
// 12. Modules

//Babel

// ------------------------------------------------------------- 1. Let, const ----------------------------------------------------------

// 1. Var / Let, Const: Scope, Hosting
// 2. Const / Var, Let: Assignment

// Code block: if else, loop, {},....

// Scope: Phạm vi
// if (true){
//         var title = 'adljfljasdf'
// }
// console.log(title)

// var ngoài khối lệnh thì vẫn có thể truy cập được biến trong khối lệnh
// biến được khai báo bằng let, const thì không thể truy cập được vào biến này từ ngoài khối lệnh

// Hosting: lưu trữ

// a = 1 
// var a; // khi là var thì nó sẽ chuyển những định nghĩa được hỗ trợ hosting lên đầu
// console.log(a) // 1

// a = 1 
// let a; // hoặc const
// console.log(a) // SyntaxError

// asignment

// var và let có thể gán lại giá trị
// const thì không cho phép gán lại giá trị của biến, chứ không cấm gán lại giá trị của thuộc tính của biến
// const b = 1;
// b = 200;
// console.log(b) // error

// const a ={
//     name: 'Javascript'
// };
// a.name = 'PHP'
// a = 'PHP' // lỗi do a đã được gán 1 lần đầu rồi cho nên ko cho gán tiếp nữa
// console.log(a.name) // PHP

// var a ={
//         name: 'Javascript'
//     };
// console.log(a)
// var a = 5
// console.log(a)

// Code thuần: Var 
// Babel: Const, Let
// Khi định nghĩa biên và khong gán lại biến đó: Const
// Khi cần gán lại giá trị cho biến : Let

// ------------------------------------------------2. Template Literals ----------------------------------------------------------------
// const courseName = 'JavaScript';
// // const description = 'Course name: ' + courseName;
// const description = `Course name:${courseName}`;
// var description1 = `Template string noi suy voi: \${}`;
// var enter = `\n`
// var a = `\\`

// console.log(description1)
// console.log(enter)
// console.log(a)

// ----------------------------------------- 3 . Multi-line String ---------------------------------------------
// var multiLine = ` line1 
//                   line2\n
//                   line3
//                   line4
//                 `
// console.log(multiLine)
// --------------------------------------------4. Arrow function --------------------------------------------------
// normal function 
// declaration function
// function logger(log){
//     console.log(log)
// }
// expression function
// const logger1 = function(log){
//     console.log(log)

// }
// logger1('message...')
// arrow function
// VD 1
// const logger1 = (log) => {
//     console.log(log)

// }
// logger1('message...')
// VD 2
// const sum = (a,b) => {
//     return a + b;
// }
// console.log(sum(2,2));
// VD 2 -> VD 3
// const sum1 = (a,b) => a + b; 
// console.log(sum1(2,2));
// VD 4: trả về object 
// const sum2 = (a,b) => {
//     return {
//         a: a,
//         b: b
//     }
// }
// console.log(sum2(2,2));
// VD5: Cach viet tắt 
// const sum3 = (a,b) =>  ({a: a, b: b})
// console.log(sum3(2,2));

// VD6: ============nếu hàm có 1 tham sô tihf có thể viết như sau=============
// const logger2 = log => console.log(log); // được hiểu là không return về gía trị console.log(log) mà chỉ thực thi dòng lệnh này
// const logger2 = log => log; // được hiểu là return log

// logger2('Message ....')

// var a = logger2('Test')
// console.log(a)
// VD7: 
// 1 
// const course = {
//     name: 'JavaScript basic!',
//     getName: function(){
//         return this.name
//     }
// }
// console.log(course.getName());

//2
// const course1 = {
//     name: 'JavaScript basic!',
//     // getName: () => {
//     //     return this //context. Arrow function không thể trả về this (context)
//     // }
//     getName: () => this
// }
// console.log(course1.getName());

// VD8
// arrow function không thể dùng để khai báo function contructor

// ------------------------------------------- 5. Classes---------------------------------------------------
// Cách viết kiểu Constructor Object
// const Course = function(name, price){
//     this.name = name;
//     this.price = price;
    //    this.getName = function(){
    //        return this.name;
    //    }
        // const a = false
        // Các thuộc tính, phương thức, biến ngang cấp nhau => Nhìn khó chịu

// }

// const jsCourse = new Course('JavaScript' , 10000)
// console.log(jsCourse)

// Cách viết kiểu Classes
// class Course {
//     constructor(name, price){
//         this.name = name;
//         this.price = price;
//     }
//     getName(){
//         return this.name;
//     }
// }

// const jsCourse = new Course('JavaScript' , 10000)
// console.log(jsCourse)
// ---------------------------------------------- 6. Default parameter values -----------------------------------

// ES5 
// function logger(log){
//     if (typeof log === 'undefined'){
//         log = 'Gia tri mac dinh'
//     }
//     console.log(log)
// }

// logger(undefined)
// ES6 
// function logger(log = 'Gia tri mac dinh!'){
//     console.log(log)
// }

// logger(undefined)
// // Đối với các tham số không bắt buộc thì cần nhập giá trị mặc định cho nó
// // VD
// function logger1(log, type = 'log'){
//     console[type](log)
// }
// logger1('Message...', 'error')
// logger1('Message...', 'warn')
// ------------------------------------------------ 7. Enhanced object literals -------------------------------------- Đối tượng mẫu nâng cao
// 1. Định nghĩa key: value cho object
// 2. Định nghĩa method cho object
// 3. Định nghĩa key cho object dưới dạng biến
// 1 & 2
// var name = 'Javasript';
// var price = 1000;

// var  course = {
//     name: name,
//     price: price,
//     getName: function(){
//         return this.name;
//     }
// }
// var  course1 = {
//     name,
//     price,
//     getName(){
//         return name
//     }
// }

// console.log(course.getName())
// console.log(course1.getName())

// // 3
// var fieldName = 'name';
// var fieldPrice = 'price';

// const course3 = {
//     [fieldName] : 'Javascript',
//     [fieldPrice] : 1000
// }
// console.log(course3)

// =========================================== 9.Destructuring , 8. Rest parameters ======================================== sử dụng với object và array. Phân rã

// var  array = ['Javascript', 'PHP', 'Ruby']
// ==================================================1. Destructuring=====================================
// =====================cách sử dụng thông thường 
// var a = array[0]
// var b = array[1]
// var c = array[2]

// console.log(a,b,c);

// ========================ES6 

// var [a , b, c ] = array;
// console.log(a,b,c);
// ================================================2. Rest: Lấy phần còn lại===============================
// var [a, ...b] = array;

// console.log(a);
// console.log(b) // array
// Khi nó là toán tử Rest khi sử dụng với destructuring

// VD1: sử dụng với object 

// var object = {
//     name: 'Java',
//     price: 1000,
//     image: 'image-address',
//     children: {
//         name: 'ReactJS'
//     }
// };

// var {name, price,...rest} = object; // cần phải đúng tên thuộc tính mới lấy ra đc, còn array thì không cần đúng tên 
// console.log(name);
// console.log(price);
// console.log(rest);

// ============================Sử dụng destructuring và rest để trả về một đối tượng mới mà không có 1 key nào đó  thì có thể quy định giá trị mặc định ở key đó luôn
// var {name: parentName, children: {name: childrenName}} = object // đổi tên các tham số được lấy ra

// // console.log(children);
// console.log(name);
// console.log(parentName);
// console.log(childrenName);

// var object = {
//     name: 'Java',
//     price: 1000,
//     image: 'image-address',
//     children: {
//         name: 'ReactJS'
//     }
// };

// var {name, description = 'default description'} = object
// console.log(name)
// console.log(description)
// ==================================================================KẾT LUÂN ==========================================================================
// Các trường hợp sử dụng của rest parameters
// 1. Sử dụng với destructuring: Phân rã với array và object . Toán tử ...là tóan tử rest parameters
// 2. Sử dụng với thuộc tính của function thì là toán tử rest. Làm tham số đầu vào của hàm

// console.log(1,2,3,4,5,6);   ================================================== CHÚ Ý TRƯỜNG HỢP NÀY ===========================================

// function logger(...params){ // Do đằng trước ko có tham số nào cả nên nó lấy toàn bộ mảng hiện có. Đây là toán tử rest
//     console.log(params); // gần giống argument. là 1 mảng
// }
// logger(1,2,3,4,5,6,7,8);
// ===========================khi truyền 1 đối tượng vào 1 hàm theo cách thông thường. Tương tự với array chỉ cần thay {} thành []. Tên biến tùy ý
// function logger(obj){
//     console.log(obj.name)
//     console.log(obj.price)
// }

// logger({
//     name: 'Javascript',
//     price: 1000,
//     description: 'Description content'
// })

// ============================khi truyền 1 đối tượng vào 1 hàm theo cách sử dụng rest parameter. Tương tự với array chỉ cần thay {} thành []. Tên biến tùy ý

// function logger1({name, ...rest}){
//     console.log(name)
//     console.log(rest)
// }

// logger1({
//     name: 'Javascript',
//     price: 1000,
//     description: 'Description content'
// })

// --------------------------------------------------------- 10. Spread(...) : Toán tử giải----------------------------------------------------------------

// ==================TH1: Nối 2 mảng với nhau mà không dùng concat()
// Giải []
// var array1 = ['Javascript', 'Ruby', 'PHP'];
// var array2 = ['ReactJS', 'Dart'];
// var array3 = [...array2, ...array1];

// console.log(array3)

// ==================TH2: Nối các đối tượng với nhau: Giải dấu {}

// var object1 = {
//     api: 'https://conganay.com',
//     version: 'v1',
//     other: 'other'
// }

// var object2 = {
//     ...object1,
//     api: 'https://congakia.vn'
// }

// console.log(object2)
// ==================TH3: Truyền tham số cho hàm
// var exempale = ['Javascript', 'Ruby', 'PHP'];

// function logger4(a,b,c){
//     console.log(a, b, c)
// }

// logger4(1,2,3) // cách làm thông thường 
// // thực tế 
// logger4(...exempale)
// ==================================== Sử dụng cả rest và spread =================================
var array = ["JavaScript","PHP", "Ruby", "RectJS"];

function logger(...array) { // Đây là dùng toán tử rest khi là tham số
    // console.log(array)
    // console.log(a)

    for(var i = 0; i < array.length; ++i) {
        console.log(array[i]);
    }
}
// console.log(...array)
logger(...array); // Đây là dùng toán tử Spread khi truyền vào đối số. Khi truyền như vậy tương ứng với truyền 
// "JavaScript","PHP", "Ruby", "RectJS" là 3 đối số vào hàm logger. Và ...array(tham số) lúc này là toán tử rest sẽ đóng 
// các đối số này vào 1 mảng.
// logger(array)
// Mình đã cố tình đặt trung tên đối số và tham số cho bạn thấy
