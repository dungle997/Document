// function abc(){
//     return 1;
// }
// abc.isRequire = function(){
//     return 2;
// }

// console.log(abc.isRequire())


// Đối tượng validator (Constructor function)
function Validator(options){
// Hàm thực hiện validate
    function validate (inputElement, rule){
        var errorMessage = rule.test(inputElement.value)
        var messageElement = inputElement.parentElement.querySelector(options.errorSelector)
        if (errorMessage){
            messageElement.innerHTML = errorMessage
            inputElement.parentElement.classList.add('invalid')
        }else{
            messageElement.innerHTML = ''
            inputElement.parentElement.classList.remove('invalid')
        }
    }
    
    // console.log(options)
    // console.log(options.form)
    // Lấy element của form cần validate
    var formElement = document.querySelector(options.form);
    // console.log(formElement)
    if (formElement){
        options.rules.forEach(function(rule){
            // console.log(rule)
            var inputElement = formElement.querySelector(rule.selector);
            if (inputElement){
                // Xử lý trường hợp blur khỏi input
                inputElement.onblur = function(){
                    validate(inputElement, rule)
                }
                // Xử lý mỗi khi người dùng nhập vào input 
                inputElement.oninput = function(){
                    var messageElement = inputElement.parentElement.querySelector(options.errorSelector)
                    messageElement.innerHTML = ''
                    inputElement.parentElement.classList.remove('invalid')
                }
            }
        
        })
    }

}


// Định nghĩa các rule
Validator.isRequired = function(selector){
    return {
        selector: selector,
        test: function(value){
            return value.trim() ? undefined : 'Vui lòng nhập tên vào ô trống'
        }
    }
}

Validator.isEmail = function(selector){
    return {
        selector: selector,
        test: function(value){
            var regex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/
            return regex.test(value) ? undefined : 'Vui lòng nhập đúng dịnh dạng email'
        }
    }
}

Validator.isMinLength = function (selector, lenght){
    return{
        selector: selector,
        test: function(value){
            return value.length > lenght ? undefined : `Mật khẩu phải lớn hơn ${lenght} ký tự`
        }
    }
}

Validator.isConfirm = function (selector, getConfirmation){
    return{
        selector: selector,
        test: function(value){
            return value === getConfirmation() ? undefined : 'Giá trị nhập vào không chính xác'
        }
    }
}