// 1. Event listener / DOM Event (onclick)
// 2. JSON
// 3. Fetch
// 4. DOM location
// 5. Local Storage
// 6. Sesion storage
// 7. Coding convention
// 8. Best Practices
// 9. Mistakes
// 10. Performance

// -------------------JSON----------------

// 1. Là một định dạng dữ liệu (chuỗi) 
// 2. JavaScript Object Notation
// 3. JSON: Number, String, Boolean, Null, Array, Object

// Mã hóa và Giải mã 
// Encode / decode
// Chuẩn nhất là: 
// Stringify  => Từ JS types -> JSON
// Parse => JSON => JS 


// Ví dụ cho parse . JSON => Javascript
// var json = '1';
// var json = 'true';
// var json = 'null';
var array = '["Javascript", "PHP"]';
console.log(JSON.parse(array))
var object = '{"name": "Le Dung", "age": 18}';
console.log(JSON.parse(object))


var a = '1';
console.log('a =',JSON.parse(a));
console.log(typeof JSON.parse(a));

// var stirng = 'jjk' nếu parse ra sẽ lỗi 
var string = '"jjk"' // thêm dấu "" thì mới đúng  
console.log(JSON.parse(string));
// Ví dụ cho Stringify

var number = 6;
console.log(JSON.stringify(number))

var object1 = {
    name : 'Le Dung',
    age : 18,
    'name-real' : 'Xoan'
}
console.log(JSON.stringify(object1)) // kết quả trả ra chuỗi string







