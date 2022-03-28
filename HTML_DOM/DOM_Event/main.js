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
// h1Element.onclick = function(e){ // e chính là đối tượng vừa mới đc click. e.target để lấy ra element node đó
//     console.log(e);
//     console.log(e.target);

// }

// Chọn tất cả các element

// var h1Elements = document.querySelectorAll('.heading');

// for (var i =0; i < h1Elements.length; i++){
//     // console.log(i)
//     h1Elements[i].onclick = function(e){
//         console.log(e.target) // nên dùng e.target
//         // console.log(h1Elements[i-1]) // cách sai
        
//     }
// }

// ------------------ DOM Events EXample------------------
// 1. Input / Select
// 2. Key up / down
// ----------------1----------------- 
// VD1
var inputValue;
var inputElement =
    document.querySelector('input[type="text"]');

    // console.log(inputElement);

inputElement.onchange = function(e){ // oninput
    console.log(e)
    console.log(e.target);
    console.log(e.target.value);
    inputValue = e.target.value;

}

//VD2
// var inputElement =
    // document.querySelector('input[type="checkbox"]');
// inputElement.onchange = function(e){
    // console.log(e.target);
    // console.log(e.target.checked);
// 
// }
// VD 3
// var inputElement =
//     document.querySelector('select');
// inputElement.onchange = function(e){
//     console.log(e.target);
//     console.log(e.target.value);

// }
// ----------------2----------------- 
// var inputElement =
//     document.querySelector('input[type="text"]');
// inputElement.onkeyup = function(e){
//     console.log(e);
//     console.log(e.target.value);
//     console.log(e.which);
//     switch(e.which){
//         case 27: 
//             console.log('Exit');
//             break;
//     }

// }

// key down bấm phím xuống là thực thi
// key up nhấc phím lên là thực thi
// Ứng dụng sử dụng esc để thoát khỏi hộp thoại pop up

// VD với cả đối tượng document
// onkeypress giữ phím 
document.onkeydown = function(e){
    console.log(e);
    console.log(e.which);
    switch(e.which){
        case 27: 
            console.log('Exit');
            break;
        case 13:
            console.log("lam sao");
            break;
    }
}