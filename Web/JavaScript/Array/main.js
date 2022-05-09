// // C1:

// var languages = [
//     'Javascript',
//     'PHP',
//     'Ruby',
//     123,
//     null,
//     undefined,
//     function(){

//     }, 
//     myObject = {
//         name : 'DungLQ',
//         'age' : 18
//     } //object
// ];

// console.log(languages)

// // C2

// var lan = new Array(
//     'Javascript',
//     'PHP',
//     'Ruby',
//     123,
//     null,
//     undefined,
//     function(){

//     }, 
//     myObject = {
//         name : 'DungLQ',
//         'age' : 18
//     } //object
// );
// console.log(lan)

// console.log(typeof {})
// console.log(typeof [])
// console.log(Array.isArray(languages))
// console.log(Array.isArray({}))
// console.log(languages.length)

// -------------------------------------------------------------
// JS array method

// 1. To String
// 2. Join       Chuyển mảng thành string và có thể thay đổi dấu ngăn cách 
// 3. Pop        Xóa phần tử ở cuối mảng 
// 4. Push       Đẩy phần từ vào cuối mảng 
// 5. Shift      Xóa phần tử ở đầu mảng 
// 6. Unshift    Đẩy phần tử vào đầu mảng 
// 7. Splicing   // (position, length, element muốn truyền vào)  Xóa từ vị trí với số lượng length
// 8. Concat     Nối 2 array với nhau
// 9. Slicing    Cắt Element trong array
// 10. Tách String thành mảng, tùy biến dấu ngăn cách

// var languages = [
//     'Javascript',
//     'PHP',
//     'Ruby'
// ];
// var languages2 = [
//     'Dart',
//     'Rubu'
// ]

// console.log(typeof languages.toString())
// console.log(languages.join(', '))
// console.log(languages.pop()) // Xóa element cuối mảng và trả về phần từ đã xóa
// console.log(languages)
// console.log(languages.push('Dart', 'Java'))
// console.log(languages)
// languages.splice(1, 1) // (position, length, element muốn truyền vào)  Xóa từ vị trí với số lượng length
// languages.splice(1, 0, 'Dart', 'Java')
// console.log(languages)
// console.log(languages.concat(languages))

// console.log(languages.slice(1, 2))

// console.log(languages.slice(0)) //copy mảng

// --------------------------------------------------------

/*
    Array methods:
        forEach() duyet qua tat ca cac phan tu cua mang. Trả về undefined
        every() taast ca phan tu trong mang phai thoa man 1 dieu kien gi do
        some() nguoc lai voi every. chi can co 1 phan tu thoa man la tra ve true
        find() trả lại phần tử  đạt yêu cầu. Luôn trả về 1 đối tượng, trả về đối tượng đâu tiên đúng
        filter() lọc các phần tử đạt yêu cầu 
        map()   tạo mảng mới dựa trên mảng cũ và có thêm các thuộc tính mới, giá trị mới 
        reduce() giúp tính toán với các đối tượng, mảng 
*/
// var courses = [
//     {
//         id: 1,
//         name : 'Javascript',
//         coin: 250
//     },
//     {
//         id: 2,
//         name : 'HTML, CSS',
//         coin: 0
//     },
//     {
//         id: 3,
//         name : 'Ruby',
//         coin: 0
//     },
//     {
//         id: 4,
//         name : 'PHP',
//         coin: 400
//     },{
//         id: 5,
//         name : 'ReactJS',
//         coin: 500
//     },
//     {
//         id: 6,
//         name : 'Ruby',
//         coin: 0
//     }
// ];

// hàm truyền dưới dạng tham số => callback
/*
courses.forEach(function(course, index){
    console.log(course, index)

})
*/
// var isFree = courses.every(function(course, index){
//     return course.coin === 0;
// })

// console.log(isFree);

// var isFree = courses.some(function(course, index){
//     console.log(index)
//     return course.coin === 0;
// })

// console.log(isFree);
// var isFree = courses.find(function(course, index){
//     console.log(index)
//     return course.name === 'Ruby';
// })

// console.log(isFree);

// var isFree = courses.filter(function(course, index){
//     // console.log(index)
//     return course.name === 'Ruby';
// })

// console.log(isFree);

/*
----------------MAP-------------
// var newCourses = courses.map(); như vậy thì sẽ coi như là đẩy vào map một hàm undefined()
function courseHandler(course, index, originArray){
    // console.log(course) // course là phần tử hiện tại. hàm này sẽ quyest qua từng phần tử và trả về gía trị cho course
    // return course;
    // return 123;
    return{
        id: course.id,
        name: `Khoa hoc: ${course.name}`,
        coin: course.coin,
        coinText: `Gia: ${course.coin}`,
        index: index, 
        // originArray: originArray
        originArray: courses
    }
};
var newCourses = courses.map(courseHandler); 
console.log(newCourses)
*/

// ----------------------Array Reduce-------------------
// 1. Dễ hiểu
// 2. Ngắn gọn hơn cách thông thường 
// 3. Hiệu năng thì chậm hơn
/* Cách thông thuowngg 
var totalCoin = 0;

for(var course of courses){
    totalCoin += course.coin;
}

console.log(totalCoin);
*/

// Biến lưu trũ 
// Thực hiện viêc lưu trữ

// var totalCoin = courses.reduce(function(){

// });

/* Giải thích dài 
var i = 0;
function coinHandler(accumulator, currentValue, currentIndex, originArray){
    i++;
    console.table({
        'Luot chay: ' : i,
        'Bien tich tru' : accumulator
    });
    console.log(currentValue); // tra ve gia tri cua phan tu hien tai
    console.log(currentIndex);
    return accumulator + currentValue.coin;  // return trả về cho accumulator = Biến lưu trữ
}

var totalCoin = courses.reduce(coinHandler, 0); // 0 initial value accumulator. Giá trị ban đầu 
console.log(totalCoin)


// Cách nhanh 
var totalCoin = courses.reduce(function(accumulator, currentValue){
    return accumulator + currentValue.coin;
}, 0) //  0 initial value tham số không bắt buộc. Nếu không có tham số 0 nay thì sẽ lấy phần tử đầu làm accumulator và bắt đâù chạy từ phần tử thứ 2
console.log(totalCoin);

// ES6 
var totalCoin = courses.reduce((a, b) => 
    a + b.coin, 0
);
console.log(totalCoin);
*/
// var i = 0;
// var totalCoin = courses.reduce(function(total, course){ 
    // i++; 
    // console.log(i, total, course)
    // return total + course.coin;
// }); //0 initial value tham số không bắt buộc. Nếu không có tham số 0 nay thì sẽ lấy phần tử đầu làm accumulator và bắt đâù chạy từ phần tử thứ 2
//// 0 biến ban đầu accumulator là cần đúng kiểu dữ liệu ta muốn trả về.
// console.log(totalCoin)
 


// Các trường hợp không dùng tham số  ban đầu accumulator

// var numbers = [100, 200, 220, 200, 480];

// var totalCoin = numbers.reduce(function(total, course){
//     return total + course;
// });
// console.log(totalCoin);

// Ví dụ
// 1. Làm phẳng mảng từ depth array - 
// var depthArray = [1, 2, [3, 4], 5, 6, [7, 8, 9]];

// var flatArray = depthArray.reduce(function(flatOutput, depthItem){
//     return flatOutput.concat(depthItem);
// }, []);
// console.log(flatArray);
// -------------------------
// var testArray = [1,2,3];
// var b = 356;
// console.log(testArray.concat(b))

// => Có thể nối só với array miễn array là mảng gốc

// 2.Lấy ra các khóa học đưa vào 1 mảng mới

// var topics = [
//     {
//         topic: "Front-end",
//         courses: [
//             {
//                 id:1,
//                 title: "HTML, CSS"
//             },
//             {
//                 id: 2,
//                 title: "Javascript"
//             }
//         ]
//     },
//     {
//         topic: "Back-end",
//         courses:[
//             {
//                 id : 1,
//                 title: "PHP"
//             },
//             {
//                 id: 2,
//                 title: "NodeJS"
//             }
//         ]
//     }
// ];

// var newCourses = topics.reduce(function(courses, topic){
    
//     return courses.concat(topic.courses);
// }, []);

// console.log(newCourses);

// var nameCourses = newCourses.reduce(function(nameCourses, id){
    // return nameCourses.concat(id.title);
// },[]);
// 
// console.log(nameCourses);

// Ngoài lề: Ứng dụng vào để render HTML 

// var htmls = newCourses.map(function(course){  
//     // console.log(course)
//     return `
//         <div>
//             <h2>${course.title}</h2>
//             <p>ID: ${course.id}</p>
//         </div>
//     `
// });
// console.log(htmls);
// console.log(htmls.join(''));

// ------------------------------------------ // chưa xong 
// Array reduce part 2: Tự xây dựng reduce cho riêng mình 
// Array.prototype.reduce2 = function(callback, initialValue){

// }
// const numbers = [1,2,3,4,5]
// const result = numbers.reduce2((total, number) => {
//     return total + number;
// }, 10)

// console.log(result)


// Bài 79 chưa xong ;


// -----------------------------------------------
// includes method. Có sẵn trong array và string 

// var title = 'Responsive web design';

// console.log(title.includes('Res'));
// console.log(title.includes('Res', 5));

// var courses = ['JavaScript', 'PHP', 'Dart', 'Youtube'];
// console.log(courses.includes('PHP'))
// console.log(courses.includes('PHP', -3))

// Nếu truyền số âm thì -1 + độ dài mảng, tìm từ vị trí đó

