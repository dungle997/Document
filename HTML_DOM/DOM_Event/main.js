// ---------------------DOM EVENT ----------------------
// 1. Attribute Event. Dùng this để lấy ra element node của chính element node của mình vừa click vào
// 2. Assign event using the Element node


// 2. 

// Chọn 1 element
// var h1Element = document.querySelector('.heading');
// var h1Element = document.querySelector('h1');

// console.log(h1Element)

// h1Element.onclick = function(){
//     h1Element.innerHTML = `
//     <span>DOM EVENT</span>
//     <h1>YOU CLICKED ME!</h1>
//     `

// }
// console.log(h1Element)
// Lấy ra element node vừa được click vào 
// h1Element.onclick = function(e){ // e chính là đối tượng vừa mới đc click
//     console.log(e);
//     console.log(e.target);

// }

// Chọn tất cả các element

var h1Elements = document.querySelectorAll('.heading');

for (var i =0; i < h1Elements.length; i++){
    h1Elements[i].onclick = function(e){
        console.log(e.target) // nên dùng e.target
        // console.log(h1Elements[i-1]) // cách sai

    }
}
