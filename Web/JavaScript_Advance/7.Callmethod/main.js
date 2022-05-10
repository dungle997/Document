// Call Method : bind + call

// Là phương thức trong prototype của Function constructor, phương thức này 
// được dùng để gọi hàm và cũng có thể bind this cho hàm
// Ví dụ
// - Gọi hàm với call method
// - Gọi hàm và bind this, lưu ý trong strict mode vẫn có this nếu được bind
// - Thể hiện tính kế thừa (extends) trong OOP 
// - Mượn hàm (function borrowing), thêm ví dụ với arguments


// ========================== - Gọi hàm với call method ============================================
// VD 1:
// function random(){
//     console.log(Math.random())
// }

// // random()
// // Khi gọi hàm như vậy thì engine của JS sẽ gọi đến phương thức call để thực hiện gọi hàm

// random.call()

// VD2: Kĩ thuật mượn hàm
// const teacher = {
//     firstName: "Minh",
//     lastName: "Thu",
// }

// const me = {
//     firstName: "Lê",
//     lastName: "Dũng",
//     showFullName(){
//         console.log(`${this.firstName} ${this.lastName}`)
//     }
// }

// me.showFullName.call(teacher)

//=================================== - Gọi hàm và bind this, lưu ý trong strict mode vẫn có this nếu được bind ========================================
// this.firstName = "Sơn"
// this.lastName = "Đặng"

// function showFullName(){
//     console.log(`${this.firstName} ${this.lastName}`)
// }

// showFullName() // Sơn Đặng
// // do this lúc này trỏ đến window 


// -------
// this trong use strict trỏ về undefined. Nhưng vẫn có nếu được bind
// 'use strict'
// this.firstName = "Sơn"
// this.lastName = "Đặng"

// function showFullName(){
//     console.log(`${this.firstName} ${this.lastName}`)
// }

// // sử dụng bind 
// // const fullName = showFullName.bind(this)
// // fullName()
// // sử dụng call

// showFullName.call(this)

// ===============================================- Thể hiện tính kế thừa (extends) trong OOP ===========================================
// function Animal(name, weight){
//     this.name = name
//     this.weight = weight
// }

// function Chicken(name, weight, legs){
//     Animal.call(this, name, weight)
//     this.legs = legs
// }

// const dungLQ = new Chicken('Dũng Lê', 68, 2)
// console.log(dungLQ)

//================================================================= - Mượn hàm (function borrowing), thêm ví dụ với arguments=================================================================
// logger
// function logger(){
//     Array.prototype.forEach.call(arguments, item =>{
//         console.log(item)
//     })

//     // const cars = ['BMW', 'Honda']
//     // cars.forEach(car =>{
//         // console.log(car)
//     // })
// }

// logger(1,2,3,4,5)

// ====================================
function logger(){
//    const arr = Array.from(arguments)
//    console.log(arr)

   //ES6
   const arr = [...arguments]
   console.log(arr)
}

logger(1,2,3,4,5)
