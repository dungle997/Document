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
// console.log(document.forms)
// console.log(document.forms['form-1']) // tên form-1 không hỗ trợ trong JS nên phải dùng dấu []
// console.log(document.forms.form3)
// console.log(document.anchors) // trả về tất cả các thẻ a có thụốc tính(attibute) name

// ----------------- Lấy li, ul trong div ------------------ phần 2 
var listItemNodes = 
    document.querySelectorAll('.box-1 li');

    console.log(listItemNodes);
// --------------------------------
var boxNode = 
    document.querySelectorAll('.box-1');

    console.log(boxNode);

    // Công viêc 1: Sử dụng tới `boxNode`
    // Công việc 2: Sử dụng tới các li elements là con của `.box-1`
    // Có tất cả các cách với ID, class, tag, Css selector trừ HTML collection

    console.log(boxNode.getElementsByTagName('li'));


