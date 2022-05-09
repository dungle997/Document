// Tham trị

// function sum(a, b){
//     // let a = c
//     // let b = d

//     a = 0 
//     b = 0
//     console.log(a, b)
// }

// const c = 1 
// const d = 2 
// sum(c, d)
// console.log(c, d)

// // Tham chiếu
// // VD 1 
// function show(obj){
//     // let obj = a / biến obj lúc này được gán bằng địa chỉ của đối tượng a 
//     obj.fullName = 'LE quang DUng'
//     console.log(obj)
// }

// const a = {
//     fullName : 'DungLQ'

// }

// show(a)
// console.log(a)

// VD 2 
// function createCar(obj){
//     // let obj = a / biến obj lúc này được gán bằng địa chỉ của đối tượng a 
//     obj.name = 'Mercedes'
//     return obj
// }

// const car  = {
//     name : 'BMW'

// }

// const newCar = createCar(car)

// console.log(car)
// console.log(newCar) // car newCar đều giống nhau
// VD 3s
// Muốn để tạo ra được một car nữa khác car cũ thì phải làm như sau
// function createCar(obj){
//     // let obj = a / biến obj lúc này được gán bằng địa chỉ của đối tượng a 
//     console.log(obj)
//     obj = JSON.parse(JSON.stringify(obj))
//     obj.name = 'Mercedes'
//     return obj
// }

// const car  = {
//     name : 'BMW'

// }

// const newCar = createCar(car)

// console.log(car)
// console.log(newCar) // car newCar đều giống nhau


// VD 4
// Với đối tượng có 1 cấp thì có thể dùng toán tử  spread. Nếu đối tượng car có nhiều object con ở trong thì nó sẽ giải cả toàn bộ object con vào trong obj đc 
// tạo ra lúc sau

// function createCar(obj){
//     // let obj = a / biến obj lúc này được gán bằng địa chỉ của đối tượng a 
    
//     obj = {...obj}
//     // console.log(obj) // BMW
//     obj.name = 'Mercedes'
//     // console.log(obj) // Mercedes

//     return obj
// }

// const car  = { // object 1 cấp
//     name : 'BMW'

// }

// const newCar = createCar(car)

// console.log(car)
// console.log(newCar) // car newCar đều giống nhau

// Chú ý: So sánh 2 object 
// Tham chiếu trả về địa chỉ vùng nhớ nên khi so sánh 2 object giống y nhau thì trả về false

// VD 5

// const a = {
//     name: 'BMW'
// }
// const b = {
//     name: 'BMW'
// }
// console.log(a === b)// false
// VD 6
// const a = {
//     name: 'BMW'
// }
// const b = a

// console.log(a === b)// true

// VD 7 : 

const a = {
    name: 'BMW'
}
a.name = 'Mercedes'
// a = 'Mercedes' // Lỗi 


console.log(a)// No error

// Giải thích: 
// - Bản thân const là không sửa lại được value của nó 
// - Trong trường hợp này ta không sửa value của nó (value của a là một địa chỉ)
// - Reference type trả về địa chỉ của vùng nhớ 