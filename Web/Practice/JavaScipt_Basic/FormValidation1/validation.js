// function abc(){
//     return 1;
// }
// abc.isRequire = function(){
//     return 2;
// }

// console.log(abc.isRequire())


// Đối tượng validator (Constructor function)
function Validator(option){
    // console.log(option)
    console.log(option.form)
    const formElement = document.querySelector('#form-1');
    console.log(formElement)

}


// Định nghĩa các rule
Validator.isRequired = function(a){
    // console.log(typeof this.isRequired)
}

Validator.isEmail = function(a){
    // console.log(a)
}