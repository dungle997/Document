const tabItems = document.querySelectorAll('.tab-item')
// console.log(tabItems)

// tabItems.forEach(function(tabItem){
    
// })  
tabItems.forEach((tabItem) => {
    console.log(tabItem)
    tabItem.onclick = function(){
     console.log(this)
     tabItem.className = 'tab-item active'
    }
})