// hoisting với từ khóa var
// VD 1 
// console.log(age) // undefined
// console.log(fullName) // ReferenceError: fullName is not defined
// var age = 16
// VD 2 

// console.log(sum(6, 9)) //15

// function sum(a, b){
//     let c = 5 
//     return a + b + c
// }

// Kết luận: Phần khai báo được đưa lên trên, phần gán không được đưa lên trên đối với 1 biến 
// Với hàm số thì nội dung bên trong {} sẽ vẫn được chạy trước
// hoisting với từ khóa let, const
// vD1
// {
// console.log(fullName) // ReferenceError : Cannot access 'fullName' before initialization
// let fullName = "Nguyen Van A"
// }

// Lưu ý: Khai báo biến với let, const khi được hoisted không được tạo
// giá trị và được đưa vào "Temporal Dead Zone"

// Lý do phải hoist
// vd 
// let fullName = 'Nguyen Van A'
// {
//     {
//         let fullName = 'Nguyen Van B'
//         {
//             console.log(fullName)

//             let fullName = 'Nguyen Van C'
//         }
//     }
// }

// Trong trường hợp này nếu không hoising thì console.log sẽ in ra fullName ở phạm vi ngoài
// Như vậy là sai, vì trong phạm vi của console.log cũng có biến fullName rồi 

// VD 2:

// const counter1 = makeCounter()

// console.log(counter1())

// function makeCounter(){
//     let counter = 0 
//     return increase

//     function increase(){
//         return ++counter
//     }
// }