// Từ khóa this trả về một đối tượng mà nó đang thuộc về 
// Đặc tính
//     1. Trong một phương thức, this tham chiếu tới đối tượng truy cập phương thức (đối tượng trước dấu . )
//     2. Đứng ngoài phương thức, this tham chiếu tới đối tượng global
// Lưu ý 
// - this trong hàm tạo là đại diện cho đối tượng sẽ được tạo
// - this trong một hàm là undefined khi ở strict mode
// - Các phương thức bind(), call(), apply() có thể tham chiếu this tới đối tượng khác



// 1. Trong một phương thức, this tham chiếu tới đối tượng truy cập phương thức (đối tượng trước dấu . )
//VD 1
// const iPhone7 = {
//     // - thuộc tính property
//     name: 'iPhone 7',
//     color: 'Pink',
//     weight: 300,

//     // Phương thức - Method
//     takePhoto(){
//         console.log(this)
//     }
// }

// console.log(iPhone7.takePhoto())

// VD 2

// const iPhone7 = {
//     // - thuộc tính property
//     name: 'iPhone 7',
//     color: 'Pink',
//     weight: 300,

//     // Phương thức - Method
//     takePhoto(){
//         console.log(this)
//     },
//     objChild: {
//         name: 'child',
//         methodChild(){
//             console.log(this)
//         }
//     }
// }

// console.log(iPhone7.objChild.methodChild())

// VD 3: Hàm tạo

// function Car(name, color, weight){
//     this.name = name
//     this.color = color
//     this.weight = weight
//     this.run = function(){
//         console.log('Running .....', this) // trả về mercesdesS450
//     }
// }
// const mercedesS450 = new Car('mercedes S450', 'black' , 1200)
// console.log(mercedesS450.run())


// // VD 4: Nút button
// const button = document.querySelector('button')
// // console.log(button)

// button.onclick = function(){
//     // console.log(this)
//     console.dir(this)

// }

//     2. Đứng ngoài phương thức, this tham chiếu tới đối tượng global
// console.log(this) // window
// function show(){
//     console.log(this)
// }

// show() // window
// --------------------------------
// - this trong một hàm là undefined khi ở strict mode
// 'use strict'
// function show(){
//     console.log(this)
// }

// show() // undefined

// ----------------------------------------
// 'use strict'
// function show(){
//     console.log(this)
// }

// window.show() // window
// ---------------------------------
// - this trong hàm tạo là đại diện cho đối tượng sẽ được tạo

// function Car(name, color, weight){
//     this.name = name
//     this.color = color
//     this.weight = weight
//     this.run = function(){
//         console.log('Running .....', this) // trả về porsche
//     }
// }

// Car.prototype.run1 =function(){
//     // Context : Ngữ cảnh để chạy chính là đối tượng porsche
//     console.log(this) // trả về porsche

//     // function test(){
//     //     console.log('trong hàm test', this) // Window do test là 1 function. this nằm ngoài phương thức thì trả về window
//     //     // Nếu trong strict mode thì trả về undefined. Do this trong một hàm là undefined khi ở strict mode
//     // }
//     // test()

//     // arrow function
//     // arrow function không có context => không có this
//     const test = () => {
//         console.log('arrow function', this)
//         // Vì không có this nên nó sẽ lấy this ở phạm vi bên ngoài của nó(hàm gần nhất chứa nó) => lấy context của hàm ngoài, trả về thís ở bên ngoài => lấy this chính là đối tượng porsche
//         // Theo lẽ thông thường vì là hàm nên this => trả về window (this Đứng ngoài phương thức )
//     }
//     test()

// }

// // this đại diện cho porsche 
// const porsche = new Car('Porsche', 'yellow', 1200)

// console.log(porsche.name)
// console.log(porsche.run())
// console.log(porsche.run1())

// - Các phương thức bind(), call(), apply() có thể tham chiếu this tới đối tượng khác


 