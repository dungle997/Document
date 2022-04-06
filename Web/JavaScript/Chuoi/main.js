/*
Chuỗi trong javascript

1. Tạo chuỗi 
    - Các cách tạo chuỗi
    - Nên dùng cách nào? Lý do?
    - Kiểm tra data type
2. Một số case sử dụng backslash (\)
3. Xem độ dài chuỗi 
4. Chú ý độ dài khi viết Code
5. Template string ES6
*/

// //C1 
// var fullName = 'Le Dung 1'

// //C2
// var fullName1 = new String('Le Dung');
// console.log(typeof fullName1);
// console.log(fullName.length);

// console.log('Xin chao moi \"nguoi\'');
// console.log('Day la dau \\');

// alert(fullName);

// C1 nhanh hơn do không phải khởi tạo đối tượng như C2. toán tử new để khởi tạo một đối tượng

// 80 kí tự

// 5 
// Cách cũ
// var firstName = 'Dung';
// var lastName = ' Le';

// console.log('Toi la: ' + firstName + lastName);
// // Cách mới 
// console.log(`Toi la: ${firstName}${lastName}`);
// ------------------------------------------------------------
// Làm việc với chuỗi 

var myString = '     Hoc JS tai JS JS F8!     ';

// Keyword: Javascript string methods

// 1. Length
// 2. Find index
// console.log(myString.indexOf('JS', 12));
// console.log(myString.lastIndexOf('JS', 10))
// string.lastIndexOf(search, start)
// search là một ký tự hoặc một chuỗi ký tự mà bạn muốn tìm vị trí xuất hiện lần cuối cùng của nó trong chuỗi gốc.
// start là tham số không bắt buộc, nó chỉ định vị trí bắt đầu tìm kiếm ngược.
// ---------------------------------------------------
// console.log(myString.search('JS'))
// 3. Cut string
// console.log(myString.slice(4, 6))
// console.log(myString.slice(4))
// console.log(myString.slice(-3, -1))

// 4. Replace
// console.log(myString.replace('JS', 'Javascript'))
// // Dùng biểu thức chính quy
// console.log(myString.replace(/JS/g, 'Javascript'))

// 5. Convert to upper case 
console.log(myString.toUpperCase())

// 6. Convert to lower case 
console.log(myString.toLowerCase())

// 7. Trim 
console.log(myString.trim())
// 8. Split
var languages = 'Javascript, PHP, Ruby';
console.log(languages.split(', '))
var languages = 'Javascript';
console.log(languages.split(''))

// 9. Get a character by index 
const myString2 = 'Son Dang';
console.log(myString2.charAt(1)) // Nếu vị trí ko có thì trả về chuỗi string rỗng
console.log(myString2[3])       // Nếu vị trí ko có thì trả về undefined
