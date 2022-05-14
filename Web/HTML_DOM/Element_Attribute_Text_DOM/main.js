// HTML DOM
//  có 3 loại node
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
//// --------------------------------
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
// var headingElement = 
//     document.querySelector('h1');


// // use seter
// headingElement.title = "Heading";
// headingElement.id = "Heading";
// headingElement.className = "Heading"; // dùng className để tránh nhầm với khái niệm khác là class

// // use method
// headingElement.setAttribute('href', 'heading') // thêm thuộc tính (attribute) href cho thẻ h1
// console.log(headingElement.getAttribute('class')); // lấy ra value

// alert(headingElement.title) // Hợp lệ 
// alert(headingElement.href) // Không Hợp lệ, do bản chất href không phải thụộc tính hợp lệ của thẻ h1 
// Thay vào đố có thể dùng cách sau để lấy ra value của các thuộc tính mới set cho các thẻ
// alert(headingElement.getAttribute('href')) // Hợp lệ  


// Tổng kết:
// - Thêm được thuộc tính thông qua hàm setAttribute. Thay đổi các attribute không có trong Element
// - 2 cách truy xuất: 
//   + qua thuộc tính (VD .title .id sử dụng dấu '.')
//   + qua phương thức (sử dụng hàm và phải truyền đối số vào)
// --------------------- Inner TExt , textContent Property--------------------------
// Lấy ra element chứa attribute node và text node
// var headingElement = document.querySelector('.heading'); 
// console.log(headingElement.innerText);
// console.log(headingElement.textContent);

// headingElement.innerText = 'new Heading'; // seter
// // trực tiếp thông qua thuộc tính innerText hoặc textContent
// console.log(headingElement.innerText);
// sử dụng seter để thay đổi, geter để show value

// ---------------------Khác nhau giữa innerText và TextContent-------------------------
// Khi sử dụng geter lấy ra innerText thì sẽ trả về giá trị giống những gì hiện tại trên màn hình
// Với textContent sẽ trả về nội dung thât của nó. Nội dung text thật của nó nằm trong DOM

// var headingElement = document.querySelector('.heading-h1'); 
// console.log(headingElement.innerText); // trả về giá trị giống như được hiên thị trên màn hình
// console.log(headingElement.textContent); // trả về nội dung text thật của nó, trong trường hợp này có cả khoảng trắng, hiên tất cả thậm chí cả mã HTML, CSS luôn

// innerText là thuộc tính của Element node => nên bắt buộc phải lây ra Element node thì mới dùng đc innerText
// textContent là thuộc tính tồn tại trên cả Element node và text node

// headingElement.innerText = `


// new Heading


// `; 
// console.log(headingElement.innerText); 


// headingElement.textContent = `


// new Heading


// `; 
// console.log(headingElement.textContent); 

// --------------------------------InnerHTML vs OuterHTML Property---------------------------

var boxElement = document.querySelector('.box1');
boxElement.innerHTML = '<h1 title="Heading1">Hello World</h1>'  // innerHTML có thể thêm 1 element, attribute và text node vào một element gốc
console.log(boxElement)

console.log(document.querySelector('.box1 h1').innerText)

console.log(boxElement.innerHTML) // geter

// ------------- OuterHTML -------------

boxElement.outerHTML = '<span>Test</span>';
console.log(boxElement)
console.log(boxElement.innerHTML) // lưu giá trị cũ từ trước đó lúc vẫn có thẻ h1. Thời điêm hiện tại ko còn trong DOM nữa mà đã đc thay bằng thẻ span

// THực tế: Khi đã sử dụng với outerHTML thì không nên sử dụng Element.innerHTML nữa, vì lúc đó nó trả gía trị không còn tồn tại nữa
// Cũng ko hay sử dụng outerHTML để ghi đè như VD trên. Thường chỉ sử dụng inerHTML để thêm nội dung vào element khác thôi. Để ghi đè nội dung thì có các cách khác



