// --------------------------------------------------------- Scope ---------------------------------------------------------------
// function show(){
//     var a = 5 
//     if (a > 0) {
//         var b = 6
//         var b = 8
//     }
//     console.log(b)
// }

// show()

// var a= 18 // Biến global. Tương tự với let

// {   
//     var a= 16
//     {
//         var a= 14

//         {
//             var a= 12
            
//             {
//                 console.log(a) //12
//                 var a= 10
//             }
//         }
//     }
// }

// let a= 18 // Biến global. Tương tự với let

// {   
//     let a= 16
//     {
//         let a= 14

//         {
//             let a= 12
            
//             {
//                 console.log(a) //12
//                 let a= 10
//             }
//         }
//     }
// }

//   Biến trong hàm được tham chiếu bởi 1 hàm?

// function makeCounter(){
//     let counter = 0
//     function increase(){
//         return ++counter
//     }
//     return increase
// }

// const increase1 = makeCounter()

// console.log(increase1())
// console.log(increase1())
// console.log(increase1())
// console.log(increase1())
// console.log(increase1())

// ---------------------------------------------------------------------------- Closure ----------------------------------------------------------

// function makeCounter(){
//     let counter = 0
//     function increase(){
//         return ++counter
//     }
//     return increase
// }

// const increase1 = makeCounter()

// console.log(increase1())
// console.log(increase1())
// console.log(increase1())
// console.log(increase1())
// console.log(increase1())

// Ví dụ 

function createLogger(namespace){
    
    function logger(message){
        console.log(`[${namespace}] ${message}`)
    }
    return logger
}

