// Callback

// Là hàm (function) được truyền qua đối số
// khi gọi hàm khác 

// 1. Là Hàm 
// 2. Được truyền qua đối số 

// function myFunction(param){
//     if (typeof param === 'function'){
//         console.log(typeof param);
//         param('Hoc lap trinh JavaScript');
//     }
// }

// function myCallback(param){ // lúc này myCallback là hàm call back
//     console.log('param =',param)
// }

// myFunction(myCallback);  // () toán tử call
// ----------------------------------------------------
// Call back phần 2
// 1. Là hàm
// 2. Truyền qua đối số
// 3. Được gọi lại (trong hàm nhận đối số )

// Array.prototype.map2 = function(callback){
//     // console.log(this);
//     var arrayLength = this.length;
//     var outputArray = [];
//     for (var i =0; i < arrayLength; i++){
//         var result = callback(this[i], i);
//         console.log('result:', result)
//         outputArray.push(result);
//     }

//     return outputArray;
// }

// var courses = [
//     'JavaScript',
//     'PHP',
//     'Ruby'
// ];

// courses.map(function(courses){ // function vô danh
//     console.log(courses);
// });
// var htmls = courses.map2(function(course, index){
//     console.log(index, course);
//     return `<h2>${course}</h2>`;
// });

// console.log(htmls.join(''))
// --------------------------------
// filter2 , reduce2, find2,  forEach.
// ----------------------------- ForEach ----------------------------------------
// ForEach 1. Object Prototype 2. For /in duyệt cả qua nhưng PT và thuộc tính trong prototype
// sample_origin
// courses.forEach(function(course, index){
//     console.log('course_forEach:',course,'index_forEach:', index);
// });

// B1:
// Array.prototype.forEach2 = function(callback){ // callback này là một hàm tương ứng với đối số function(courses)
//     console.log(this); // this chính là đối tượng gọi đến forEach2, ở đây là courses

// }

// courses.forEach2(function(){
    
// });

// B2:
// Array.prototype.forEach2 = function(callback){ // callback này là một hàm tương ứng với đối số function(courses) 
//     // console.log(Array.prototype);
//     // console.log(this); // this chính là đối tượng gọi đến forEach2, ở đây là courses
//     for(var index in this){ // for in sẽ duyệt qua tất cả element thường mà còn duyệt cả element trong prototype
//         // this.hasOwnProperty(index) kieerm tra xem co index  nao thuoc prototype khong
//         // console.log('index:', index);
//         // console.log('index:', this.hasOwnProperty(index));
        
//         if(this.hasOwnProperty(index)){
//             // console.log('index:', index);
//             callback(this[index], index);
//         }

//         // DO sử dụng prototype để thêm phương thức forEach2 nên khi duyệt qua index thì có thêm cả thằng forEach2
//         // output.push(result);
//     }
//     return undefined;
// }

// courses.forEach2(function(course, index){
//     console.log(course, index)

//     // return course;
// });
// ------------------------------------------------Filter------------------------------------------------
// var courses = [
//     'JavaScript',
//     'PHP',
//     'Ruby',
//     'Ruby',
// ];
// // ----------origin method----------------
// var isFree = courses.filter(function(course, index){
//     return course === 'Ruby'
// })
// // console.log(typeof isFree)
// console.log(isFree)

// ------------- new method --------------------

// Array.prototype.filter1 = function(callback){
//     // console.log(this)
//     var output = [];

//     for (var index in this){
//         if(this.hasOwnProperty(index)){
//             var result = callback(this[index], index);
//             // console.log(result)
//             if (result !== false){
//                 output.push(this[index])
//             }
//         }
//     } 
//     // console.log(output)

//     // return output === undefined ? undefined : output
//     return output

// }

// var listFilter = courses.filter1(function(course, index){
//     return course === 'Ruby' ;
    
// });
// console.log(listFilter) 
// // console.log(typeof listFilter) 

// --------------------------- find ------------------------------
// var courses = [
//     'JavaScript',
//     'PHP',
//     'Ruby',
//     'Ruby',
// ];

// ----------------------------origin method---------------------------a--
// var test = courses.find(function(course, index){
//     return course === 'Ruby'
// })
// console.log(test)

// // -------------------------------new method---------------------------a------
// Array.prototype.filter1 = function(callback){
//     // console.log(this)
//     var output;

//     for (var index in this){
//         if(this.hasOwnProperty(index)){
//             var result = callback(this[index], index);
//             // console.log(result)
//             if (result !== false){
//                 output = this[index]
//                 // console.log(index)
//                 break;
//             }
//         }
//     } 
//     // console.log(output)

//     // return output === undefined ? undefined : output
//     return output
// }

// var listFilter = courses.filter1(function(course, index){
//     return course === 'Ruby' ;
    
// });
// console.log(listFilter) 
// // console.log(typeof listFilter) 
// ---------------------------------------------- Reduce -----------------------------------------
//  var courses = [ // (*)
//         {
//             id: 1,
//             name : 'Javascript',
//             coin: 250
//         },
//         {
//             id: 2,
//             name : 'HTML, CSS',
//             coin: 0
//         },
//         {
//             id: 3,
//             name : 'Ruby',
//             coin: 0
//         },
//         {
//             id: 4,
//             name : 'PHP',
//             coin: 400
//         },{
//             id: 5,
//             name : 'ReactJS',
//             coin: 500
//         },
//         {
//             id: 6,
//             name : 'Ruby',
//             coin: 0
//         }
//     ];
 
var courses = [ 1,2 ,3,4,5,6]; // (**)
// ========================== origin method ========================

// var result = courses.reduce(function(accumulator, currentValue){
//     return accumulator + currentValue.coin;
// }, 0) 
// console.log(result)
// =========================== new method ==========================   Dùng argument để check xem hàm có được truyền đủ đối số không

Array.prototype.reduce2 = function(callback, acumulator){
    // console.log(this.length)
    var index = 0
    if(arguments.length < 2){    // để check xem hàm có bao nhiêu đối số truyền vào
        index =1;
        acumulator = this[0];
    }
    var result = acumulator;
    // for (var index in this){
    for (; index < this.length; index++){
        if(this.hasOwnProperty(index)){
            result = callback(result, this[index], index, this)
            // console.log(result)
            // console.log(acumulator)
        }
    }
    return result;
}

var result1 = courses.reduce2(function(acumulator, course, index){
    // return acumulator + course.coin  // cho trường hợp phần tử của courses là đối tượng (*) 
    return acumulator + course // (**)
})
console.log(result1)
// -------------------------------- some() method ----------------------------------
//  var courses = [
//         {
//             id: 1,
//             name : 'Javascript',
//             isFinish: false,
//             coin: 250
//         },
//         {
//             id: 2,
//             name : 'HTML, CSS',
//             isFinish: false,
//             coin: 0
//         },
//         {
//             id: 3,
//             name : 'Ruby',
//             isFinish: false,
//             coin: 0
//         },
//         {
//             id: 4,
//             name : 'PHP',
//             isFinish: false,
//             coin: 400
//         },{
//             id: 5,
//             name : 'ReactJS',
//             isFinish: false,
//             coin: 500
//         },
//         {
//             id: 6,
//             name : 'Ruby',
//             isFinish: false,
//             coin: 0
//         }
//     ];
// ============= origin ===============
// var result = courses.some(function(course, index){
//     console.log(index)
//     return course.isFinish
// })
// console.log(result)
// ================ new method =============
// Array.prototype.some2 = function(callback){
//     var result
//     for(var index in this){
//         if(this.hasOwnProperty(index)){
//             result = callback(this[index], index);
//             if (result){
//                 break;
//             }
//         }    
//     }
//     return result
// }

// var result = courses.some2(function(course, index){
//     console.log(index)

//     return course.isFinish
// });

// console.log(result);

// -------------------------every -------------------------------
// Array.prototype.every2 = function(callback){
//     var result
//     for(var index in this){
//         if(this.hasOwnProperty(index)){
//             result = callback(this[index], index);
//             if (result){
//                 break;
//             }
//         }    
//     }
//     return !result
// }

// var result = courses.every2(function(course, index){
//     console.log(index)

//     return course.isFinish === false
// });

// console.log(result);

// -------------------------------------------------------------------------------------------------------------------------------------------
//!!!! -------------------------Nen dung cach nao de dung voi array--------for/in -----for/of   ------------------!!!!

// console.log(courses);
// courses.length = 10;
// for (var i=0; i<courses.length; i++){
//     console.log(courses[i]);
// }

// for(var index in courses){
//     console.log(index) // chỉ chạy qua các phần tử thật => nên dùng cách này để duyệt mảng 
// }

// // Dùng như vậy sẽ gặp trường hợp 7 undefined => ko nên dùng 

// // ----------------------------------------------------
// var courses1 = new Array(10);  // khai báo mảng có độ dài 10 phần tử  và chưa có giá trị cho các phần tử trên
// // var courses1 = new Array(10,12); // Như này là khai bao mảng vói 2 phần tử


// console.log(courses1);

// for(var index in courses1){
//     console.log(courses1[index]); // chỉ chạy qua các phần tử thật => nên dùng cách này để duyệt mảng 
// }
// ---------------------------------------------------------------------------------------------------------------------------------------------