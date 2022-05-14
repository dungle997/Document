// Cách hoạt động:
// - Tương tự phương thức call 
// - Khác cách nhận đối số cho hàm
// - Nhận đối số cho hàm dưới dạng 1 cái mảng

// Lý thuyết: 
// - Phương thức này cho phép gọi một hàm với 
// một this (bind) và truyền đối số cho hàm gốc
// dưới dạng mảng 
//---------------- VD1: Dùng hàm ngoài gọi đến một đối tượng khác
// const teacher = {
//     firstName: "Minh",
//     lastName: "Thu",
// }

// function greet(greeting, message){
//     return `${greeting} ${this.firstName} ${this.lastName}.${message}
//             `
// }
// let result = greet.apply(teacher, ['Em chào cô', 'Cô dạy môn gì thế ạ?'])

// console.log(result)

// // So sánh với call() method

// result = greet.call(teacher, 'Em chào cô', 'Cô dạy môn gì thế ạ?')

// console.log(result)

// VD 2: Mượn hàm từ đối tượng khác

// const teacher = {
//     firstName: "Minh",
//     lastName: "Thu",
//     isOnline: false,
//     goOnline(){
//         this.isOnline = true
//         console.log(`${this.firstName} ${this.lastName} is Online`)
//     },
//     goOffline(){
//         this.isOnline = false
//         console.log(`${this.firstName} ${this.lastName} is Offline`)
//     }, 
// }

// const me = {
//     firstName: "Dũng",
//     lastName: "Lê",
//     isOnline: false,
// }



// console.log('Teacher: ', teacher.isOnline)
// teacher.goOnline()
// console.log('Teacher: ', teacher.isOnline)

// console.log('----------------')

// console.log('Student: ', me.isOnline)
// teacher.goOnline.apply(me)
// teacher.goOnline.call(me)
// console.log('Student: ', me.isOnline)

// VD3: Kết thừa (Extend)
// Cách nhận đối số thông thường 
// ----------------------
// function Animal (name, weight){
//     this.name = name
//     this.weight = weight
// }
// function Parrot (name, weight){
//     // Animal.apply(this, arguments) // ko nhận đối số
//     Animal.apply(this, [name, weight]) // Nếu mà nhận đối số

//     this.speak = function(){
//         console.log('Nhà có khách!')
//     }
// }

// const conVet = new Parrot('Vẹt', 300)

// console.log(conVet)
// ---------------------------
// function Animal (name, weight){
//     this.name = name
//     this.weight = weight
// }
// // Sự khác biệt của apply : Khổi tạo parrot không cần đối số
// function Parrot (){
//     Animal.apply(this, arguments) // ko nhận đối số
//     this.speak = function(){
//         console.log('Nhà có khách!')
//     }
// }

// const conVet = new Parrot('Vẹt', 300)

// conVet.speak()


// So sánh bind, apply, call

// Giống nhau: 
// - Là các methods được thừa kế từ Function.prototype

// Khác nhau:
// - Cách hoạt động và đối số nhận

// function fn(){}

// /*
//     Bind
//     - Trả ra hàm mới với 'this' tham chiếu tới 'thisArg'
//     - Không thực hiện gọi hàm
//     - Nếu được bind kèm `arg1, arg2`  thì các đối số này sẽ được ưu tiên hơn
//  */
// const newFn = fn.bind(thisArg, arg1, arg2,...)
// newFn(arg1, arg2, ...)
// /*
//     Call Method
//     - Thực hiện bind `this` với `thisArg` và thực hiện gọi hàm
//     - Nhận các đối số cho hàm gốc từ `arg1, arg2, ...`
//     - Không trả ra hàm mới, nếu hứng hàm mới sẽ trả ra undefind
//  */
// fn.call(thisArg, arg1, arg2, ...)
// /*
//     Apply Method
//     - Thực hiện bind `this` với `thisArg` và thực hiện gọi hàm
//     - Nhận các đối số cho hàm gốc từ [arg1, arg2, ...]
//     - Không trả ra hàm mới, nếu hứng hàm mới sẽ trả ra undefind

//  */
// fn.apply(thisArg, [arg1, arg2, ...])
// Lưu ý
// 3 cái hàm này sẽ sử dụng khi bind this khi mượn hàm và extend
