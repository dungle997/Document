function Validator(selector, options){
    var _this = this
    if (!options){
        options = {}
    }
    var formRules = {}
    var validatorRules = {
        required: function(value){
            return value ? undefined : 'Vui lòng nhập trường thông tin này'
        },
        email: function(value){
            var regex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/
            return regex.test(value) ? undefined : 'Vui lòng nhập đúng dịnh dạng email'
        },
        min: function(min){
            return function(value){
                return value.length > min ? undefined : `Mật khẩu phải lớn hơn ${min} ký tự`
            }
        }, 
    }
    // console.log(validatorRules)
    var formElement = document.querySelector(selector)
    var inputElements = formElement.querySelectorAll('input[name][rules]:not([disabled])')
    var data = {}
    
    if (formElement){
        // console.log(formElement)
        // console.log(inputElements)
        // Lắng nghe sự kiện blur và change của các ô input
        for (var inputElement of inputElements){
            // formRules[inputElements[i].name]
            var rulesName = inputElement.getAttribute('rules').split('|')
            // console.log(rulesName)
            // if(rulesName.include(':')){

            // }
            for(var ruleName of rulesName){
                var ruleInfo

                isRuleHasValue = ruleName.includes(':') 
                if(isRuleHasValue){
                    ruleInfo = ruleName.split(':')
                    ruleName = ruleInfo[0]
                    // console.log(validatorRules[ruleName](ruleInfo[1]))
                }
                var validatorFunc = validatorRules[ruleName]
                if(isRuleHasValue){
                    // console.log(ruleInfo[1])
                    validatorFunc = validatorFunc(ruleInfo[1])
                    // console.log(validatorFunc)
                }
                // console.log(ruleName)
                if (!Array.isArray(formRules[inputElement.name])){
                    formRules[inputElement.name] = [validatorFunc]
                }else{
                    formRules[inputElement.name].push(validatorFunc)
                }

            }
    
            inputElement.onblur = handleValidate
            inputElement.onchange = handleRemoveMessage
        }
        console.log(formRules)

        // Lắng nghe sự kiện submit
        formElement.onsubmit = function(event){
            event.preventDefault()
            var isFormValid = true
            for (var inputElement of inputElements){
                var isValid = handleValidate({
                    target: inputElement
                })
                if (!isValid){
                    isFormValid = false
                }
            }
            if (isFormValid){
                if (typeof _this.onSubmit === 'function'){
                
                // if (typeof options.onSubmit === 'function'){
                    // Hành vi trả về các giá trị của các ô input | Cách trả về onSubmit
                
                for (var input of inputElements){
                    data[input.name] = input.value
                }
                // options.onSubmit(data)
                _this.onSubmit(data)
                }else{
                    // Hành vi submit mặc định của trình duyệt 
                    formElement.submit();
                }
            }
             
        }

    }
 
    function findFormGroup(inputElement,selector){
        // console.log(inputElement.parentElement)
        while(inputElement.parentElement){
            if(inputElement.parentElement.matches(selector)){
                return inputElement.parentElement
            }
            inputElement = inputElement.parentElement
        }
    }
    function handleValidate(event){
        // console.log(event.target.value)
        // console.log(event.target.name)
        // console.log(options.formGroupSelector)
        var formGroupElement = findFormGroup(event.target, options.formGroupSelector)
        // console.log(formGroupElement)
        var messageElement = formGroupElement.querySelector(options.messageSelector)
        // console.log(messageElement)
        // Lấy ra các danh sách các rule ứng với id các ô input. Dạng mảng 
        var rules = formRules[event.target.name]
        var errorMessage

        // C1
        for (var rule of rules) {
            errorMessage = rule(event.target.value)
            // console.log(errorMessage)
            if (errorMessage){
                break
            }
        }
        // C2 
        // rules.find(function (rule){
        //     errorMessage = rule(event.target.value)
        //     return errorMessage
        // })

        //
        if (errorMessage){
            formGroupElement.classList.add('invalid')
            messageElement.innerHTML = errorMessage
        }
        // console.log(typeof rules)
        // console.log(rules)
        return !errorMessage
    }
    function handleRemoveMessage(event){
        if(findFormGroup(event.target, options.formGroupSelector).querySelector(options.messageSelector)){
            findFormGroup(event.target, options.formGroupSelector).querySelector(options.messageSelector).innerHTML = ''
        }
        if (findFormGroup(event.target, options.formGroupSelector).classList.contains('invalid')){
            findFormGroup(event.target, options.formGroupSelector).classList.remove('invalid')
        }
        
    }

}