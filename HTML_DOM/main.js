// HTML DOM

// 1. Element: ID, class, tag name, CSS selector, HTML collection
// 2. Attribute
// 3. Text

// Document Object Model đc tạo ra lưu vào biến document => đại diện cho website của chúng ta


// console.log(document);

// document.write('Hello Guys')

// --------------------- id -----------------------
// var headingNode = document.getElementById('heading');
// console.log(headingNode);
// console.log({
    // element: headingNode
// });

// id là duy nhất. Nếu nhiều Id
// ------------------- class -----------------
// var headingNode1 = document.getElementsByClassName('heading');
// console.log(headingNode1)

// HTMLCollection giống mảng nhưng khác ở chỗ  không có các phương thức map, reduce, find, filter, ....
// ------------------------ tag --------------------
// var headingNode2 = document.getElementsByTagName('h1');
// console.log(headingNode2)
// --------------------- CSS selector -------------------
// var headingNode3 = document.querySelector('.heading');
// console.log(headingNode3)
// var headingNode3 = document.querySelector('.box .heading-2:first-child');
// console.log(headingNode3)
// var headingNode3 = document.querySelector('.box .heading-2:nth-child(2)');
// console.log(headingNode3)

// var headingNode3 = document.querySelectorAll('.box .heading-2');
// console.log(headingNode3)
// console.log(headingNode3[2])

// ----------------------------------------------
// console.log(document.forms) // trả về một HTML Collection chứa danh sách các form trong trang web
// console.log(document.forms['form-1']) // tên form-1 không hỗ trợ trong JS nên phải dùng dấu []
// console.log(document.forms.form3)
// console.log(document.anchors) // trả về tất cả các thẻ a có thụốc tính(attibute) name

// ----------------- Lấy li, ul trong div -------------get element phần 2----- phần 2 
// var listItemNodes = 
//     document.querySelectorAll('.box-1 li');

//     console.log(listItemNodes);
// // --------------------------------
// var boxNode = 
//     document.querySelector('.box-1');

//     console.log(boxNode);

//     // Công viêc 1: Sử dụng tới `boxNode`
//     // Công việc 2: Sử dụng tới các li elements là con của `.box-1`
//     // Có tất cả các cách với ID, class, tag, Css selector trừ HTML collection

//     console.log(boxNode.querySelectorAll('li'));
//     console.log(boxNode.getElementsByTagName('li'));
//     console.log(boxNode.getElementsByTagName('p'));

// ------------------- Get Element phần 3-----------------

// 1. getElementById
// 2. querySelector
// => Chỉ 2 cách này mới trả về trực tiếp Element

// 3. getElementsByClassName => trả về  HTML Collection
// 4. getElementsByTagName => trả về  HTML Collection
// 5. querySelectorAll => trả về Node list 

// 6. HTML Collection. // Dùng với form, tìm thẻ a 

// 7. document.write

// -------------6 --------------------
// var h1Element = document.getElementsByTagName('h2')[0];
// //var h1Element = document.getElementsByTagName('h2');
// console.log(h1Element)
// -------------------7-----------------
// document.write('Hello') // do vị trí thẻ script đc quy định được xuất hiện ở đâu. Có thể
// Cấu hình việc phần script được thực thi sớm hay muộn so với các phần khác 

// --------------------Attribute node & Text node ---------------------
// Element node: Chính là các thẻ h1,h2,..
// Attribute node : Thuộc tính của các thẻ. VD: h1, h2
// Text node: Nội dung text trong các thẻ 

// ------------------------------DOM attribute----------------------------------
var headingElement = 
    document.querySelector('h1');


// use seter
headingElement.title = "Heading";
headingElement.id = "Heading";
headingElement.className = "Heading"; // dùng className để tránh nhầm với khái niệm khác là class

// use method
headingElement.setAttribute('href', 'heading') // thêm thuộc tính (attribute) href cho thẻ h1
console.log(headingElement.getAttribute('class')); // lấy ra value

// alert(headingElement.title) // Hợp lệ 
// alert(headingElement.href) // Không Hợp lệ, do bản chất href không phải thụộc tính hợp lệ của thẻ h1 
// Thay vào đố có thể dùng cách sau để lấy ra value của các thuộc tính mới set cho các thẻ
// alert(headingElement.getAttribute('href')) // Hợp lệ  


// Tổng kết:
// - Thêm được thuộc tính thông qua hàm setAttribute. Thay đổi các attribute không có trong Element
// - 2 cách truy xuất: 
//   + qua thuộc tính (VD .title .id sử dụng dấu '.')
//   + qua phương thức (sử dụng hàm và phải truyền đối số vào)

