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

// function createLogger(namespace){
    
//     function logger(message){
//         console.log(`[${namespace}] ${message}`)
//     }
//     return logger
// }

// // ============== App =================

// // Register.js

// const infoLogger = createLogger('Info')

// infoLogger('Bắt đầu gửi mail thông báo')

// const infoLogger1 = createLogger('Warning')
// infoLogger1('Bắt đầu gửi mail thông báo')

// ========================= Local Storage ============================
// function createStorage(key){
//     const store = JSON.parse(localStorage.getItem(key)) ?? {} // nếu localStorage.getItem(key) trả về undefined thì sẽ gán store = {}   
//     console.log(store)

//     const save = () =>{
//         localStorage.setItem(key, JSON.stringify(store))
//     }
    
//     const storage = {
//         get(key){
//             return store[key]
//         },
//         set(key, value){
//             store[key] = value
//             save()
//         },
//         remove(key){
//             delete store[key]
//             save()
//         }
//     }

//     return storage
// }
// Profile.js

// const ProfileSetting = createStorage('profile')

// console.log(ProfileSetting)


// console.log(ProfileSetting.set('name', 'DungLQ'))
// console.log(ProfileSetting.get('name'))

// const Age = createStorage('age')

// console.log(Age.set('name', 'DungLQ'))
// console.log(Age.get('name'))

// console.log(store)

// ========================== VD 2 ==============================
function createApp(){
    const cars = []
    return {
        add(car){
            cars.push(car)
        },
        show(){
            console.log(cars)
        }
    }
}


const car = createApp()    
car.add('BWM')
car.show()
