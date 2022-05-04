// 1. IIFE
// 2. Closures
// 3. Hoisting
// 4. Strict mode
// 5. This keyword
// 6. Bind Method
// 7. Call Method
// 8. Apply Method
// 9. Catching, throwing errors
// 10. Promise
// 11. Async function, await


// 1. IIFE - Immediately Invoked Function Expression

// Self-Invoking Function

// --------

// Nội dung
// 1. IIFE trông như nào?
// 2. Dùng dấu ; trước IIFE
// 3. IIFE là hàm "private"
// 4. Sử dụng IIFE khi nào
// 5. Các cách tạo ra một IIFE
// 6. Ví dụ sử dụng IIFE
// let fullName = 'DUng LE'
// ;(function show(message){
//     console.log('Message: ', message)
// })('Chao XIn')

// ;(function(){

// })()


// let i = 0
// ;(function showNumber(){
//     i++
//     console.log(i)
//     if (i < 10){
//         showNumber()
//     }
// })()
// show('safadsfdsf') // là hàm private nên không thể truy cập từ ngoai vào

// 4. Sử dụng khi viết thư viện; ngươi dùng có thể dùng mà không bị ảnh hưởng dự án của họ. VD: trùng tên biến, tên hàm
// 5. Các cách viết 
// C1: 
// ;(function(){

// })()

//C2: arrow function
// ;(() => {
//     console.log(1)
// })()
// C3: đưa () vào bên trong
// ;(function(){
    // console.log(100)
// }())

//C4: 

// +function(){
//     console.log(100)
// }()

// Khi có dấu tóan tử ở trước thì sẽ có thể thực thi hàm ở sau. Vì nó phải tính toán các leejenh trong function trước
// Search Đặc Tả Java Script
// Thường ko sài 

// 6. Ví dụ

const app = (function(){
    // Private
    const cars = []

    return {
        get(index){
            return cars[index]
        },
        add(car){
            cars.push(car)
        }, 
        edit(index, car){
            cars[index] = car 
        },
        delete(index){
            cars.splice(index, 1)
        }
    }
})()