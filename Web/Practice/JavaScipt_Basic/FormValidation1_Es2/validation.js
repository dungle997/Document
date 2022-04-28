// function abc(){
//     return 1;
// }
// abc.isRequire = function(){
//     return 2;
// }

// console.log(abc.isRequire())


// Đối tượng validator (Constructor function)
function Validator(options){
    function getParent(element, selector){
        while (element.parentElement){
            if (element.parentElement.matches(selector)) {
                return element.parentElement
            }
            element = element.parentElement
        }
    }
    var selectorRules = {}
    // Hàm thực hiện validate
    function validate (inputElement, rule){
        var rules = selectorRules[rule.selector]
        // Tìm thẻ cha ở ngay cấp gần nhất của inputElement
        // var messageElement = getParent(inputElement, options.formGroupSelector).querySelector(options.errorSelector)
        // console.log(parentElement)
        var messageElement = getParent(inputElement, options.formGroupSelector).querySelector(options.errorSelector)

        var errorMessage
        // console.log(rules)
        for(var i =0 ; i<rules.length; i++){
            // console.log(rules[i])
            switch(inputElement.type){
                case 'checkbox':
                case 'radio': 
                    errorMessage = rules[i](
                        formElement.querySelector(rule.selector + ':checked')
                    )
                    break
                default: 
                    errorMessage = rules[i](inputElement.value)
            }
            if (errorMessage) break;
        }

        if (errorMessage){
            messageElement.innerHTML = errorMessage
            getParent(inputElement, options.formGroupSelector).classList.add('invalid')
        }else{
            messageElement.innerHTML = ''
            getParent(inputElement, options.formGroupSelector).classList.remove('invalid')
        }
        return !errorMessage
    }
    
    // console.log(options)
    // console.log(options.form)
    // Lấy element của form cần validate
    var formElement = document.querySelector(options.form);
    // console.log(formElement)
    if (formElement){
        formElement.onsubmit = function(e){
            e.preventDefault()

            var isFormValid = true

            options.rules.forEach(function(rule){
                var inputElement = formElement.querySelector(rule.selector);
                isValid = validate(inputElement, rule)
                if (!isValid){
                    isFormValid = false
                }
            })
            

            if (isFormValid){
                // Trường hợp submit với javascript
                if (typeof options.onSubmit === 'function'){
                    // Lấy ra tất cả input có attribute name, những thẻ input có điêfn thông tin của ngươi dùng 
                    var enableInputs = formElement.querySelectorAll('[name]:not([disabled])')

                    var formValues = Array.from(enableInputs).reduce(function (values, input){
                        
                        switch(input.type){
                            case 'checkbox':
                            case 'radio':
                                values[input.name] = formElement.querySelector('input[name="' + input.name + '"]:checked').value
                                break
                            default: 
                                values[input.name] = input.value
                        }

                        return values
                    }, {})
                    options.onSubmit(formValues)
                }
                // Trường hợp submit với hành vi mặc định
                else{
                    formElement.submit();
                }
            }
        }

        // Lặp qua mỗi rule và lắng nghe sự kiện
        options.rules.forEach(function(rule){
            // Lưu lại các rules cho mỗi input

            if (Array.isArray(selectorRules[rule.selector])){
                selectorRules[rule.selector].push(rule.test) 
            }else {
                selectorRules[rule.selector] = [rule.test]
            }

            // selectorRules[rule.selector] = rule.test

            // console.log(rule)
            var inputElements = formElement.querySelectorAll(rule.selector);
            Array.from(inputElements).forEach(function (inputElement){
                if (inputElement){  
                    // Xử lý trường hợp blur khỏi input
                    inputElement.onblur = function(){
                        validate(inputElement, rule)
                    }
                    // Xử lý mỗi khi người dùng nhập vào input 
                    inputElement.oninput = function(){
                        // Tìm thẻ cha ở ngay cấp gần nhất của inputElement
                        var messageElement = getParent(inputElement, options.formGroupSelector).querySelector(options.errorSelector)
                        messageElement.innerHTML = ''
                        getParent(inputElement, options.formGroupSelector).classList.remove('invalid')
                    }
                }
            })
        
        })
        // console.log(selectorRules)
    }

}


// Định nghĩa các rule
Validator.isRequired = function(selector, message){
    return {
        selector: selector,
        test: function(value){
            return value ? undefined : message || 'Vui lòng nhập tên vào ô trống'
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