// var boxElement = document.querySelector('.box');

// console.log(boxElement)
// console.log(typeof boxElement)
// console.log(boxElement.innerText)
// console.log(boxElement.innerHTML)   
// console.log(boxElement.className)


// // Khi in ra màn hình thì boxElement chính là 1 element object. Do thằng công cụ google chorme tự hiểu 
// // chúng ta đang console.log ra một element node nên nó tự hiển thị ra dạng cấu trúc html của cái node
// // này (hiện kiểu thẻ div như trong ví dụ này)
// // để hiện thị theo kiểu object thì làm như sau: (hiển thị element node)
// console.log([boxElement]) 

// // trong element, attribute, text có những thuộc tính chung (innerText)
// // noteType = 1 element node; =2 là attribute node; = 3 là text node 
// ----------------------------------- DOM CSS --------------------------- dùng thẻ style

// var boxElement = document.querySelector('.box');
// console.log(boxElement.style);

// boxElement.style.width = '100px';
// boxElement.style.height = '200px';
// boxElement.style.backgroundColor = 'red';

// Object.assign(boxElement.style, {
//     width : '200px',
//     height : '100px',
//     backgroundColor: 'green',
// });

// console.log(boxElement.style.backgroundColor)

// ------------------------------ Classlist Property------------------------------- thuộc tính của element node

// add
// contains
// remove
// toggle : gọi đến nếu class đó có thì xóa đi, nếu chưa có thì thêm class đó vào

// var boxElement = document.querySelector('.box');
// console.log(boxElement.classList);
// console.log(boxElement.classList.length);
// console.log(boxElement.classList[1]);
// console.log(boxElement.classList.value);

// boxElement.classList.add('red', 'blue', 'green')

// console.log(boxElement.classList.contains('red'))

// boxElement.classList.remove('red', 'blue', 'green')

// setTimeout(() => {
//     // boxElement.classList.remove('red');
//     boxElement.classList.toggle('red');
// }, 3000);

// setInterval(() => {
//     // boxElement.classList.remove('red');
//     boxElement.classList.toggle('red');
// }, 1000);










