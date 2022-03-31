// ====================== Promise Example ======================

var users = [
    {
        id: 1,
        name: 'Kien Dam',
    }, 
    {
        id: 2,
        name: 'Son Dang'
    },
    {
        id: 3,
        name: 'Hung Dam',
    }
];
var comments = [
    {
        id: 1,
        user_id: 1,
        content: 'Content 1'
    },
    {
        id: 2,
        user_id: 2,
        content: 'Content 2'
    },
    {
        id: 3,
        user_id: 3,
        content: 'Content 2'
    },
    {
        id: 4,
        user_id: 5,
        content: 'Content 2'
    },
    {
        id: 5,
        user_id: 6,
        content: 'Content 2'
    },
    {
        id: 5,
        user_id: 1,
        content: 'Content 2'
    },
];

// 1. Lấy comments
// 2. Từ comments lấy ra user_id,
// từ user_id lấy ra user tương ứng 

// fake API
// 1. Array
// 2. Function, callback
// 3. Promise
// 4. DOM
function showMessage(){
    var userIds = comments.map(function(userId){
        return userId.user_id
    })

    console.log(userIds)

    function getUserById(userIds){
        var result = users.filter(function(user){
            return userIds.includes(user.id)
        })

        return result;
    }

    var result = getUserById(userIds)
    console.log(result)
    var data = {
        users: result,
        comments : comments
    }

    console.log(data)

    var commentElement = document.getElementById('comment-block')
    var html = ``;
    data.comments.forEach(function(comment){
        var filter = data.users.find(function(user){
            return user.id === comment.user_id
        })
        console.log(filter)

        if (filter !== undefined){
            html += `<li>${filter.name} : ${comment.content}</li>`
        }
    })
    if(!html.Empty){
    commentElement.innerHTML = html
    }

}

showMessage()