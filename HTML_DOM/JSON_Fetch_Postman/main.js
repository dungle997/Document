// 1. Event listener / DOM Event (onclick)
// 2. JSON
// 3. Promise
// 4. Fetch
// 5. DOM location
// 6. Local Storage
// 7. Sesion storage
// 8. Coding convention
// 9. Best Practices
// 10. Mistakes
// 11. Performance

// -------------------JSON----------------

// 1. Là một định dạng dữ liệu (chuỗi) 
// 2. JavaScript Object Notation
// 3. JSON: Number, String, Boolean, Null, Array, Object

// Mã hóa và Giải mã 
// Encode / decode
// Chuẩn nhất là: 
// Stringify  => Từ JS types -> JSON
// Parse => JSON => JS 


// Ví dụ cho parse . JSON => Javascript
// var json = '1';
// var json = 'true';
// var json = 'null';
// var array = '["Javascript", "PHP"]';
// console.log(JSON.parse(array))
// var object = '{"name": "Le Dung", "age": 18}';
// console.log(JSON.parse(object))


// var a = '1';
// console.log('a =',JSON.parse(a));
// console.log(typeof JSON.parse(a));

// // var stirng = 'jjk' nếu parse ra sẽ lỗi 
// var string = '"jjk"' // thêm dấu "" thì mới đúng  
// console.log(JSON.parse(string));
// // Ví dụ cho Stringify

// var number = 6;
// console.log(JSON.stringify(number))

// var object1 = {
//     name : 'Le Dung',
//     age : 18,
//     'name-real' : 'Xoan'
// }
// console.log(JSON.stringify(object1)) // kết quả trả ra chuỗi string


//---------------------Promise(sync, async)-----------------------
// Promise: 
    // - Sync : Chạy theo luồng đồng bộ, thằng nào có trước chạy trước
    // - Async : Bất đồng bộ, lênh được viết trước mà lại được thực hiện sau 
    // - Nỗi đau => sử dụng promisse tối ưu hơn
    // - Lý thuyết Promise, Cách hoạt động
    // - Thực hành, ví dụ

// ===================Sync / Async=================
// Về logic thì số 1 phải được in ra rồi mới đến 2. nghĩa là chờ 1 s rồi in ra 1 rồi mới in ra 2
// setTimeout(function(){
//     console.log(1)
// }, 1000)
// console.log(2);
// bất đồng bộ

// Một số thằng chạy theo kiểu async (nhiều luồng)

// setTimeout, setInterval, fetch, XMLHttpRequest, đọc file
// request animation frame
// Không biết được khi nào các hàm trên xong, để biết được thì dùng 
// Callback 
// ================== Nỗi đau Promise (pain)==================

// Callback hell. Các tác vụ phụ thuộc vào nhau, tuần tự
// setTimeout(function(){
//     console.log(1);
//     setTimeout(function(){
//         console.log(2);
//         setTimeout(function(){
//             console.log(3);
//             setTimeout(function(){
//                 console.log(4);
//             }, 1000)
//         }, 1000)
//     }, 1000)
// }, 1000)

// Pyramid of doom
// ===================== Lý thuyết cách Hoạt động promise(concept) ==============
// var promise = new Promise(
//     // Executor. Được thực thi trước cả khi nhận đươc đối tượng promise
//     function(resolve, reject){
//         // Logic xử lí 
//         // Thành công thì gọi resolve()
//         // Thất bại: reject()

//         // resolve();

//         // Fake call API
//         resolve([
//             {
//                 id: 1,
//                 name: 'Javascript'
//             }
//         ]);
//         // reject([
//         //     {
//         //         id: 1,
//         //         name: 'Javascript'
//         //     }
//         // ]);
//     }
// );

// 2 bước để tạo ra promise:
// 1. new Promise
// 2. Executor
// Lưu ý: Trong executor bắt buộc phải gọi 1 trong 2 thằng resolve, reject
// Nếu không sẽ sinh ra treo và memory leak


// promise
//     .then(function(courses){
//         // khi resolve được gọi thì callback của then được gọi
//         console.log('Sucessfully!')
//         console.log(courses);

//     })
//     .catch(function(){
//         // khi reject được gọi thì callback của catch được gọi
//         console.log('Failure!')

//     })
//     .finally(function(){
//         // khi 1 trong 2 resolve, reject được gọi thì callback của finally được gọi
//         console.log('Done!')
//     })

// Promise có 3 trạng thái: 
// 1. Pendding: khi executor không trả về resolve hoặc reject
// 2. Fulfilled: executor trả về resolve thì promise ở trạng thái này
// 3. Rejected: 

// Uncaught (in promise) [{…}] => Lỗi này là do trong promise không có sử dụng thuộc tính .catch

// Promise: sinh ra để xử lí các thao tác mất đồng bộ 
// Trước khi có promise khi ta sử dụng callback sẽ xảy ra vấn đề là
// callback hell. Nó sẽ bị sâu vào, rất khó nhìn, khó hiểu
// Thế nên thằng promise được sinh ra từ phiên bản JS mới hơn trong 
// phiên bản ES6. Chúng ta có thể dùng promise khắc phục tình trạng
// callback hell

// ====================== Lý thuyết, Promise (chain)===================

// var promise = new Promise(
//     // Executor. Được thực thi trước cả khi nhận đươc đối tượng promise
//     function(resolve, reject){
//         resolve()
//     }
// );
// return ra một giá trị không phải promise thì chạy ngay .then ở sau
// promise
//     .then(function(){ // nếu không return gì thì sẽ trả về undefined
//         // nếu không return ra một promise thì nó chạy ngay .then ở dưới
//         return 1;
//     })
//     .then(function(data){
//         console.log(data);
//         return 2
//     })
//     .then(function(data){
//         console.log(data);
//         return 4
//     })
//     .then(function(data){
//         console.log(data);
//     })
//     .catch(function(){
//         // khi reject được gọi thì callback của catch được gọi
//         console.log('Failure!')

//     })
//     .finally(function(){
//         // khi 1 trong 2 resolve, reject được gọi thì callback của finally được gọi
//         console.log('Done!')
//     })
// .then return về một promise khác
// promise
//     .then(function(){ // nếu không return gì thì sẽ trả về undefined
//         return new Promise(function(resolve){
//             setTimeout(function(){
//                 resolve([1,2,3])
//             }, 3000);
//         });
//     })
//     .then(function(data){ // then này chờ return từ promise trên . chờ 3s
//         console.log(data);
//     })
//     .then(function(){
//         setTimeout(function(){
//             console.log('Time out 3s');
//         }, 3000)
//         console.log('okok')

//     // Nếu như vậy thì okok chạy trước và Time out 3s được in ra sau => Sai logic do bất đồng bộ
//     // Nêu muốn giải quyết thì phải return về 1 promise. Xem ví dụ dưới
//     })
//     .catch(function(error){
//         // khi reject được gọi thì callback của catch được gọi
//         console.log(error)

//     })
//     .finally(function(){
//         // khi 1 trong 2 resolve, reject được gọi thì callback của finally được gọi
//         console.log('Done!')
//     })


// Ví dụ sleep

// function sleep(ms){
//     return new Promise(function(resolve){
//         setTimeout(resolve, ms)
//     });
// }

// sleep(1000)
//     .then(function(){
//         console.log(1);
//         return sleep(1000);
//     })
//     .then(function(){
//         console.log(2);
//         return sleep(1000);
//     })
//     .then(function(){
//         console.log(3);
//         return sleep(1000);
//     })

// ================== Promise Methods (resolve, reject, all)===================
// function sleep(ms){
//     return new Promise(function(resolve){
//         setTimeout(resolve, ms)
//     });
// }

// sleep(1000)
//     .then(function(){
//         console.log(1);
//         return sleep(1000);
//     })
//     .then(function(){
//         console.log(2);
//         return new Promise(function(resolve, reject){
//             reject('Error');
//         });
//     })
//     .then(function(){
//         console.log(3);
//         return sleep(1000);
//     })

//     .catch(function(err){
//         console.log(err)
//     })

// 1. Promise.resolve
// 2. Promise.reject
// 3. Promise.all

// var promise = new Promise(function(resolve, reject){ // C1
//     // resolve('Success!')
//     reject('Error')
// });

// var promise = Promise.resolve('Success!'); // C2 không bao giờ chạy vào catch
// var promise = Promise.reject('Error!'); // C2 không bao giờ chạy vào then

// // Muốn trong then có reject thì phải dùng new 
// promise 
//     .then(function(result){
//         console.log('result =', result)
//     })
//     .catch(function(result){
//         console.log('error =', result)
//     })


// Promise.all Example. Để cho 2 thằng độc lập với nhau nhưng vẫn 
// muốn lấy đầu ra của 2 thằng đó để làm việc với nhau

// var promise1 = new Promise(
//     function(resolve){
//         setTimeout(function(){
//             resolve([1]);
//         }, 2000);
//     }
// )

// var promise2 = new Promise(
//     function(resolve){
//         setTimeout(function(){
//             resolve([2, 3]);
//         }, 5000);
//     }
// )

// var promise2 = Promise.reject('Co loi !')

// Promise.all([promise1, promise2]) 
//     // .then(function(result){ // result là 1 array mang kết quả của 2 promise trên
//     .then(function([result1, result2]){ // result là 1 array mang kết quả của 2 promise trên
//         console.log(result1.concat(result2))
//     })
//     .catch(function(error){
//         console.log(error)
//     })
// ====================== Promise Example ======================

// var users = [
//     {
//         id: 1,
//         name: 'Kien Dam',
//     }, 
//     {
//         id: 2,
//         name: 'Son Dang'
//     },
//     {
//         id: 3,
//         name: 'Hung Dam',
//     }
// ];
// var comments = [
//     {
//         id: 1,
//         user_id: 1,
//         content: 'Content 1'
//     },
//     {
//         id: 2,
//         user_id: 2,
//         content: 'Content 2'
//     },
//     {
//         id: 3,
//         user_id: 1,
//         content: 'A the ma a'
//     }
// ];

// 1. Lấy comments
// 2. Từ comments lấy ra user_id,
// từ user_id lấy ra user tương ứng 

// fake API
// 1. Array
// 2. Function, callback
// 3. Promise
// 4. DOM
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

// ------------------------- 4. Fetch ----------------------------
// Lấy dữ liệu từ phía BE trả về 
// 1. Front-end: Xây dựng giao diện
// 2. Back-end: Xây dựng logic xử lí + Cơ sở dữ liệu
// API (URL) -> Application programing interface
// Cổng giao tiếp giữa các PM

// Backend -> API (URL) -> Fetch -> JSON/XML
// -> JSON.parse -> Javascript types
// -> Render ra giao diện với HTML

// var postAPI = 'https://jsonplaceholder.typicode.com/posts'

// // stream
// fetch(postAPI)
//     .then(function(response){
//         return response.json()
//         // JSON.parse -> JSON -> Javascipt types
//     })
//     .then(function(posts){
//         console.log(posts) //Javascipt types
//         var html = posts.map(function(post){
//             return `<li>
//                 <h2>${post.title}</h2>
//             </li>`
//         })
//         var htmls = html.join('');
//         document.getElementById('comment-block').innerHTML = htmls;
//     })
//     .catch(function(err){
//         console.log(err)
//     })
// ==================== 4.1 JSON server: Fake API Server / Mock API ========================

//- Cài nodejs
// tạo thư mục json_server
// npm-v
// npm-init
// npm i json-server
// thêm key start vào scripts trong file package.json
// npm start
// var postsApi = 'http://localhost:3000/posts'

// fetch(postsApi)
//     .then(function(response){
//         return response.json();
//     })
//     .then(function(post){
//         console.log(post)
//     })
// ============ Dùng Postman làm viêc với Rest API ==========
// - 4 hành động thao tác với dữ liệu
// - CRUD
    // - Create: Tạo mới dữ liệu -> POST
    // - Read: Lấy dữ liệu -> GET
    // - Update: Chỉnh sửa -> PUT/PATCH
    // - Delete: Xóa dữ liệu -> DELETE
    // Giao thức http, phương thức get, post, patch, delete

// ================= Example Thêm sửa xóa khóa học với Fetch và REST API =============


var listCoursesBlock = document.querySelector('#comment-block');

var courseAPI = 'http://localhost:3000/courses'

// function start(){
//     getCourses1(function(courses){
//         renderCourses(courses)
//     })
// }

// start();

// function getCourses(){
//     fetch(courseAPI)
//         .then(function(response){
//             return response.json()
//         })
//         .then(function(course){
//             console.log(course)
//         })
// }

function start(){
    getCourses1(renderCourses);
}

start();
handleCreateForm();
function getCourses1(callback){
    fetch(courseAPI)
        .then(function(response){
            return response.json()
        })
        .then(callback)
}
function renderCourses(courses){
    // c1
    // var html = ``
    // courses.forEach(function(course){
    //     html += `<li>${course.name} : ${course.author}</li>`
    // })
    // listCoursesBlock.innerHTML = html;
    // c2 
    var htmls = courses.map(function(course){
        return `
                <li>
                    <h4>${course.name}</h4>
                    <p>${course.author}</p> 
                </li>
                `
    })
    listCoursesBlock.innerHTML = htmls.join('');

}

function handleCreateForm(){
    var createBtn = document.querySelector('#creat')
    createBtn.onclick = function(){
        // alert('alo')
        var name = document.querySelector('input[name="name"]').value;
        console.log(name)
        var author = document.querySelector('input[name="author"]').value;
        console.log(author)
        var formData = {
            name: name,
            author: author,
        };
        console.log(formData)
        // createCourse(formData, renderCourses);
        createCourse(formData, function(){
            getCourses1(renderCourses);
        });


    }
}
function createCourse(data, callback){
    var options = {
        method: 'POST',
        body: JSON.stringify(data),
        headers: {
            'Content-Type': 'application/json'
            // 'Content-Type': 'application/x-www-form-urlencoded',
        },
    }
    fetch(courseAPI, options)
        .then(function(response){
            return response.json();
        })
        .then(callback)
}

