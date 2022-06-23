// Ví dụ về bất đồng bộ: 

// Browser API/Web API
// -setTimeout(), setInterval(),...
// - Click, scroll, ... events

// Promises
// Các đối tượng JS để thực hiện các tác vụ bất đồng bộ

// function test(){
//     setTimeout( () => console.log('1'), 0)
//     console.log('2')
//     console.log('3')
// }
// test()


// function httpGetAsync(theUrl, callback){
//     var xmlHttp = new XMLHttpRequest();
//     xmlHttp.onreadystatechange = function (){
//         if(xmlHttp.readyState == 4 && xmlHttp.status == 200) callback(xmlHttp)
//     }
//     xmlHttp.open("GET", theUrl, true) // true for asynchronous
//     xmlHttp.send(null)
//     // console.log('dir')
// }
// // callback hell
// httpGetAsync('https://picsum.photos/200/300', (data) =>{
//     console.log(data)
//     document.getElementById('img_1').setAttribute('src', data.responseURL)
//     httpGetAsync('https://picsum.photos/200/300', (data) =>{
//         console.log(data)
//         document.getElementById('img_2').setAttribute('src', data.responseURL)
//         httpGetAsync('https://picsum.photos/200/300', (data) =>{
//         console.log(data)
//         document.getElementById('img_3').setAttribute('src', data.responseURL)
//         })
//     })
// })

// sử dụng promise thay thế 
function httpGetAsync(theUrl, resolve,reject){
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.onreadystatechange = function (){
        if(xmlHttp.readyState == 4 && xmlHttp.status == 200) resolve(xmlHttp)
        // if(xmlHttp.readyState == 4 && xmlHttp.status == 200) reject(xmlHttp)

    }
    xmlHttp.open("GET", theUrl, true) // true for asynchronous
    xmlHttp.send(null)
    // console.log('dir')
}
// phần khai báo các promise
const promise1 = new Promise((resolve, reject) => {
    // httpGetAsync('https://picsum.photos/200/300',null, reject)
    httpGetAsync('https://picsum.photos/200/300',resolve, null)
    
})
const promise2 = new Promise((resolve, reject) => {
    httpGetAsync('https://picsum.photos/200/300', resolve)
})
const promise3 = new Promise((resolve, reject) => {
    httpGetAsync('https://picsum.photos/200/300', resolve)
})
// các promsise phải được bọc trong 1 hàm có ký tự async đứng trước tên, không thể chạy ở global
const executeAsync = async () => {
    try{    
        const reponse1 = await promise1
        // console.log(reponse1.response)
        document.getElementById('img_1').setAttribute('src', reponse1.responseURL)
    
        const reponse2 = await promise2
        document.getElementById('img_2').setAttribute('src', reponse2.responseURL)
    
        const reponse3 = await promise3
        document.getElementById('img_3').setAttribute('src', reponse3.responseURL)
    }
    catch(err) { 
        console.log({err})
    }

}   

executeAsync()






// // chaining
// // viết kiểu này thì promise chạy trong phạm vi global
// promise1
// .then( data => {
//     document.getElementById('img_1').setAttribute('src', data.responseURL)
//     return promise2
// })
// .then( data => {
//     document.getElementById('img_2').setAttribute('src', data.responseURL)
//     return promise3
// })
// .then( data => {
//     document.getElementById('img_3').setAttribute('src', data.responseURL)
// })

// // async và await sinh ra để nhóm phần khai báo promise vào cho dễ nhìn
