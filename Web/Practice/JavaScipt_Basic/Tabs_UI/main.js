var $ = document.querySelector.bind(document)
var $$ = document.querySelectorAll.bind(document)

const tabItem = $('.tab-item')
const tabItems = $$('.tab-item')
const tabPane = $('.tab-pane')
const tabPanes = $$('.tab-pane')

const tabActive = $('.tab-item.active')
const line = $('.tabs .line') // thêm dấu cách vì không cùng cấp

// console.log([tabActive])
// console.log([line])

line.style.left = tabActive.offsetLeft + 'px'
line.style.width = tabActive.offsetWidth + 'px'




tabItems.forEach((tabItem, index) => {
    tabItem.onclick = function(){
    $('.tab-item.active').classList.remove('active')
    console.log([this])
    this.classList.add('active')
    $('.tab-pane.active').classList.remove('active')
    tabPanes[index].classList.add('active') 

    line.style.left = this.offsetLeft + 'px'
    line.style.width = this.offsetWidth + 'px'

    }
})

    // $('.tab-pane.active').classList.remove('active')

    
