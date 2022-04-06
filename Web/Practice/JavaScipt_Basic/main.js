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
        user_id: 2,
        content: 'Content 2'
    },
    {
        id: 4,
        user_id: 2,
        content: 'Content 2'
    },
    {
        id: 5,
        user_id: 1,
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
// Cách làm thông thường 
    // var userIds = comments.map(function(userId){
    //     return userId.user_id
    // })

    // console.log(userIds)

    // function getUserById(userIds){
    //     var result = users.filter(function(user){
    //         return userIds.includes(user.id)
    //     })

    //     return result;
    // }

    // var result = getUserById(userIds)
    // console.log(result)
    // var data = {
    //     users: result,
    //     comments : comments
    // }

    // console.log(data)

    // var commentElement = document.getElementById('comment-block')
    // var html = ``;
    // data.comments.forEach(function(comment){
    //     var filter = data.users.find(function(user){
    //         return user.id === comment.user_id
    //     })
    //     console.log(filter)

    //     if (filter !== undefined){
    //         html += `<li>${filter.name} : ${comment.content}</li>`
    //     }
    // })
    // if(!html.Empty){
    // commentElement.innerHTML = html
    // }


    // Cách làm sử dụng promise (Tự làm ) 

    function getUserById(userIds){
        var result = users.filter(function(user){
            return userIds.includes(user.id)
        })

        // return new Promise (function(resolve){
            // setTimeout(function(){
            return result;
            // }, 1000)  
        // })
    }

    function getComments(){
        return new Promise (function(resolve){
            setTimeout(function(){
                var userIds = comments.map(function(userId){
                    return userId.user_id
                })
                resolve(userIds)
            }, 1000)
        })
    }

    getComments()
        .then(function(userIds){
            // console.log(userIds);
            return getUserById(userIds)

        })
        .then(function(users){
            return {
                users: users,
                comments: comments,
            }
        })
        .then(function(data){
            // console.log(data)
            var showElement = document.getElementById('comment-block') 
            var html = ``
            data.comments.forEach(function(comment){
                var user = data.users.find(function(user){
                    return comment.user_id === user.id
                })
                html += `<li>${user.name} : ${comment.content}</li>`
            })
            // console.log(html)
            showElement.innerHTML = html;
        })

// Thầy chữa 

// function getUsersByIds(userIds){
//     return new Promise(function(resolve){
//         var result = users.filter(function(user){
//             return userIds.includes(user.id)
//         });
//         setTimeout(function(){
//             resolve(result);
//         }, 1000)
//     })
// }

// function getComments(){
//     return new Promise(function(resolve){
//         setTimeout(function(){
//             resolve(comments);
//         },1000);
//     });
// }

// getComments()
//     .then(function(comments){
//         // console.log(comments)
//         var userIds = comments.map(function(comment){
//             return comment.user_id;
//         });
//         // console.log(userIds);
//         return getUsersByIds(userIds)
//             .then(function(users){
//                 // console.log(users)
//                 return {
//                 users : users,
//                 comments : comments,
//                 };
//             })
//     })
//     .then(function(data){
//         console.log(data);
//         var commentBlock = document.getElementById('comment-block');
//         var html ='';
//         data.comments.forEach(function(comment){
//             var user = data.users.find(function(user){
//                 return user.id === comment.user_id;
//             })
//             html += `<li>${user.name}: ${comment.content}</li>`
//         })
//         commentBlock.innerHTML = html;
//     })


