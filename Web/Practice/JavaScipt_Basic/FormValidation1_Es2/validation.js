// function abc(){
//     return 1;
// }
// abc.isRequire = function(){
//     return 2;
// }

// console.log(abc.isRequire())


// Đối tượng validator (Constructor function)
function Validator(options){
    var selectorRules = {}
// Hàm thực hiện validate
    function validate (inputElement, rule){
        var rules = selectorRules[rule.selector]
        var messageElement = inputElement.parentElement.querySelector(options.errorSelector)
        var errorMessage
        console.log(rules)
        for(var i =0 ; i<rules.length; i++){
            // console.log(rules[i])
            errorMessage = rules[i](inputElement.value)
            if (errorMessage) break;
        }

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
            // Lưu lại các rules cho mỗi input

            if (Array.isArray(selectorRules[rule.selector])){
                selectorRules[rule.selector].push(rule.test) 
            }else {
                selectorRules[rule.selector] = [rule.test]
            }

            // selectorRules[rule.selector] = rule.test

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
        // console.log(selectorRules)
    }

}


// Định nghĩa các rule
Validator.isRequired = function(selector, message){
    return {
        selector: selector,
        test: function(value){
            return value.trim() ? undefined : message || 'Vui lòng nhập tên vào ô trống'
        }
    }
}

Validator.isEmail = function(selector, message){
    return {
        selector: selector,
        test: function(value){
            var regex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/
            return regex.test(value) ? undefined : message || 'Vui lòng nhập đúng dịnh dạng email'
        }
    }
}

Validator.isMinLength = function (selector, lenght, message){
    return{
        selector: selector,
        test: function(value){
            return value.length > lenght ? undefined : message || `Mật khẩu phải lớn hơn ${lenght} ký tự`
        }
    }
}

Validator.isConfirm = function (selector, getConfirmation, message){
    return{
        selector: selector,
        test: function(value){
            return value === getConfirmation() ? undefined : message || 'Giá trị nhập vào không chính xác'
        }
    }
}