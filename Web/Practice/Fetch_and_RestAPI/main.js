// =========================== Fetch, Promise and RestAPI ===============================

var linkAPI = 'http://localhost:3000/courses'
var dataHTMLs; // dùng cho trường hợp không càn fetch get lại trang
var listElements // dùng cho trường hợp không càn fetch get lại trang
function start(){
    getData(renderData)
    
}

start()
handleCreateData()

function getData(callback){
    fetch(linkAPI)
        .catch(function(err){
            console.log(err)
        })
        .then(function(respond){
            return respond.json();
        })
        .then(callback)  
}

function renderData(datas){
    listElements = document.querySelector('#comment-block')
    // var listElements = document.getElementById('comment-block')
    // console.log(data)
    dataHTMLs = datas.map(function(data){
        return `
                <li id="item-delete-${data.id}">
                    <h4>${data.name}</h4>
                    <p>${data.author}</p>
                    <button onclick = handleDeleteDatas(${data.id})>Xóa</button>
                </li>
                `
    })
    // console.log(dataHTMLs)
    // console.log(htmls)
    listElements.innerHTML = dataHTMLs.join('');
    
}

function handleCreateData(){
    var clickBtn = document.querySelector('.create-btn');
    clickBtn.onclick = function(){
        var inputName = document.querySelector('input[name="name"]')
        var inputAuthor = document.querySelector('input[name="author"]')
        // console.log(inputName.value)
        // console.log(inputAuthor.value)
        var data = {
            name : inputName.value,
            author: inputAuthor.value
        }
        // creatDatas(data, getData(renderData)) // sẽ lỗi 
        creatDatas(data, function(respond){
        // C1: Load lại database rồi hiển thị lên 
            // console.log(respond) // không dùng đến respond trong TH này
            // getData(renderData)
        
        // C2: Thêm phần tử vừa được post vào thẳng phần html hiển thị
            // console.log(respond) // giá trị vừa mới đc post vào, trả về kiểu đối tượng, ko phải array
        // console.log(dataHTMLs)
        newData = `
                <li id="item-delete-${respond.id}">
                    <h4>${respond.name}</h4>
                    <p>${respond.author}</p>
                    <button onclick = handleDeleteDatas(${respond.id})>Xóa</button>
                </li>
                `   
        dataHTMLs.push(newData)
        // console.log(dataHTMLs.join(''))
        listElements.innerHTML = dataHTMLs.join('');
        })
    }
}

function creatDatas(data, callback){
    option = {
        method: 'POST',
        body: JSON.stringify(data),
        headers: {
            'Content-Type': 'application/json'
            // 'Content-Type': 'application/x-www-form-urlencoded',
        }
    }
    fetch(linkAPI, option)
        .then(function(respond){
            return respond.json()
        })
        .then(callback)

}

function handleDeleteDatas(id){
    option = {
        method: 'DELETE',
        headers: {
            'Content-Type': 'application/json'
            // 'Content-Type': 'application/x-www-form-urlencoded',
        }
    }
    
    fetch(linkAPI + '/' + id, option)
        .then(function(respond){
            return respond.json()
        })
        .then(function(){
            // getData(renderData) //C1 load lai api
            // C2 xu li ngay trong DOM
            var deleteElements = document.querySelector('#item-delete-' + id)
            deleteElements.remove()
        })
}



