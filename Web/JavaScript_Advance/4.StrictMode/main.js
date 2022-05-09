// VD 1: Quên không khai báo var let
// Trước use strict phải ko có dòng code nào nếu ko sẽ ko chạy
// var i = 1
// "use strict";
// fullName = 'Nguyen Van A' // tạo ra biến fullName ở global

// function testFunc(){
//     age = 18 // Tạo ra biến age ở phạm vi global
// }

// testFunc()

// console.log(fullName)
// console.log(age)


// // Trường hợp có thể xảy ra
// // khi dùng 1 biến trùng tên với biến global vô tình đã tạo từ trước
// // Khi khai báo fullName thì nó sẽ lấy giá trị đã khai báo từ trước => Tiền ẩn lỗi 
// var fullName

// console.log(fullName)
// VD 2: Một hàm khi được khai báo trong 1 khối code thì chỉ sử dụng được trong khối đó thôi, bên ngoài ko gọi tới được
// "use strict"
// {

//   function subtract(a, b) {
//     return a - b;
//   }
//   var x = function (a, b) {
//     return a - b;
//   }

// }
// console.log(subtract(7, 3)) // Lỗi
// console.log(x(7, 5)) // 2


//VD3

// 'use strict'

// const student = Object.freeze({
//     fullName: 'Nguyen Van A'
// })

// student.fullName = 'Nguyen Van B'
// console.log(student)

// báo lỗi ko thể gán cho key fullName thành 'Nguyen Van B'
// Nếu ko sử dụng strict mode thì kết quả trả về 'Nguyen Van A' 
// ko cho sửa nhưng ko có lỗi nào được thông báo

// Một cách viết khác để thêm key vào một object 


// - Báo lỗi khi gán lại giá trị cho thuộc tính có writable: false
// 'use strict'

// const student = {}

// Object.defineProperty(student, 'fullName', {
//     value: 'Nguyen Van A',
//     writable: false, // mặc định là cho sửa nghĩa là true
// })

// student.fullName = 'Nguyen Van B'
// console.log(student)

// - Báo lỗi khi xóa đối tượng không thể xóa 
// "use strict"
// const student = {}

// delete student

// console.log(student)

// Báo lỗi khi hàm có tham số trùng tên
// 'use strict'
// function sum(a , a){
//     return a + a 
// }

// console.log(sum(6, 9))


// // VD về scope:
// function sum(){
//     // let b = 8
//     console.log(a)
//     function sum1(){
//         let a = 6
//         // console.log(b)
//     }
//     // sum1()
// }

// sum()
// // sum1() // lỗi 

// - Khai báo hàm trong code block thì hàm sẽ thuộc phạm vi code block
// {
//     function sum(){
//         console.log(8)
//     }
// }

// sum() // 8

// 'use strict' // Sử dụng strict thì hàm trong code block chỉ thực thi được trong code block
// {
//     function sum(){
//         console.log(8)
//     }
// }

// sum() // Lỗi hàm sum() ko đc khai báo

// - Không đặt tên biến, tên hàm bằng một số từ khóa "nhạy cảm" của ngôn ngữ


// 'use strict'
// const private = 123

// console.log(private)
