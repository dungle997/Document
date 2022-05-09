// var emailKey = 'email-one';

// var myInfo = {
//     name: 'Le Dung',
//     'age-year': 18,
//     address: 'Hanoi, VN',
//     [emailKey]: 'quagdung145',
//     getName: function(){
//         return this.name;
//     },
//     array : [1,2,3,4]
// };
// // C1
// myInfo.email = 'fadsjflkja@gmail.com';
// // C2
// myInfo['address-two'] = 'sssss@gmail.com';
// console.log(myInfo);
// console.log(myInfo['email']);
// console.log(myInfo.name);
// console.log(myInfo[emailKey]);

// delete myInfo.email;
// delete myInfo[emailKey];
// console.log(myInfo);
// console.log(myInfo.getName());


// // Function ----> Phương Thức / method
// // Others ------> Thuộc tính / property

// -------------------------------------------
/*
// Object Constructor

function User(firstName, lastName, avatar){  // declaration function
    // expression funtion
// var User= function(firstName, lastName, avatar){  // declaration function

    this.firstName = firstName;
    this.lastName = lastName;
    this.avatar = avatar;

    this.getName = function(){
        return `${this.firstName} ${this.lastName}` // this ở đây chỉ đối tượng gọi đến 
    }
}
User.prototype.className = 'F8';
User.prototype.getClassName  = function(){
    return this.className; // this ở đây chỉ đối tượng gọi đến
}
var author = new User('Dung', 'Le', 'Avatar');
var user = new User('Thim', 'Nguyen', 'Butterfly');

console.log(author.getName());
console.log(user.getName());

author.title = 'chia se dao tai F8';
user.comment = 'ok khoa hoc hay qua di';

console.log(author);
console.log(user);

console.log(author.className);
console.log(author.getClassName());


// // Tạo đối tượng nhanh chóng hơn với Object Constructor. Nếu không thì phải tạo theo cách thông thường và nhập từng giá  trị vào.

// --------------------------------------------------
// Object Prototype có  chức năng thêm thuộc tính ở bên ngoài hàm tạo
*/

// ----------------------------------------------------------------
// Đối tượng  Date . Keyword Date Object mozila ---s

/*
var date = new Date();

console.log(typeof date);
console.log(date);

// var date1 = Date();
// console.log(typeof date1);
// console.log(date1);
var year = date.getFullYear();
var month = date.getMonth();
var day = date.getDate();

console.log(`${year} ${month} ${day}`)
*/
// -------------------------------------------------------

/*
    Math object 
    - Math.PI
    - Math.round()
    - Math.abs()
    - Math.ceil()
    - Math.floor()
    - Math.random()
    - Math.min()
    - Math.max()
    Không phải là object constructor
*/

// console.log(Math.PI); // số  PI
// console.log(Math.round(3.568)); // làm tròn 
// console.log(Math.abs(-3.568));  // trị tuyệt đối 
// console.log(Math.ceil(-4.000001)); // làm tròn trên
// console.log(Math.floor(-4.000001)); // làm tròn dưới
// console.log(Math.random()*10); // làm tròn trên
// console.log(Math.floor(Math.random()*5));

// // var  random = Math.floor(Math.random()*5);
// // var bonus = [
// //     '10 coin', 
// //     '20 coin',
// //     '30 coin',
// //     '40 coin',
// //     '50 coin'
// // ];
// // console.log(bonus[random]);

// var  random = Math.floor(Math.random()*100);

// if (random < 5){
//     console.log('Cuong hoa thanh cong!')
// }


// console.log(Math.max(5, 9 ,8  , 8));

// Làm bài tại đây
function Student(firstName, lastName){
    this.firstName = firstName
    this.lastName = lastName
    this.getFullName = function(){
        return this.firstName + ' ' +  this.lastName
    }
}



// Ví dụ khi sử dụng
var student = new Student('Long', 'Bui');

console.log(student.firstName);  // 'Long'
console.log(student.lastName);  // 'Bui'
console.log(student.getFullName());  // 'Long Bui'


function getRandomItem(array){
    var random = Math.floor(Math.random() *array.length)
    return array[random]
}

var array = [1,2,3,4,5,6]
console.log(getRandomItem(array))





