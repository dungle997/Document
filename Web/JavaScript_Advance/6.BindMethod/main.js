// Hiểu rõ về context
// Context vs. Scope

// Điều đầu tiên là phải phân biệt: context và scope là 2 khái niệm khác nhau.
//  Tôi thấy rất nhiều developer nhầm lẫn 2 thuật ngữ này trong một thời gian dài (bao gồm cả tôi).

// Mỗi khi function được gọi thì có cả scope và context kết hợp với nó. 
// Về cơ bản, scope là dựa trên function, còn context dựa trên object. 
// Nói cách khác, scope liên quan đến việc function truy xuất biến khi nó được gọi. 
// Còn context luôn chỉ đến giá trị của từ khóa this tham chiếu đến object sở hữu đoạn code đang được thực thi.



// Trong các phương thức, trong các hàm của JS sẽ tồn tại khái niệm context chỉ duy nhất arrow function là không có 
// context thôi. Tùy vào cách gọi hàm hay gọi phương thức thì từ khóa this ở trong hàm,trong phương thức sẽ có thể 
// tham chiếu về đối tượng khác nhau (window hoặc đối tượng gọi đến phương thức)

// Khi gọi một phương thức , hàm thông qua một đối tượng thì từ khóa this tham chiếu về đối tượng mà chúng ta gọi phương thức đó
// (đối tượng trước dấu . )
// Khi gọi một function độc lập không thông qua một đối tượng thì :
// - Ở ngoài strict mode thì từ khóa this sẽ trỏ về đối tượng window (global)
// - Ở trong strict mode thì từ khóa this sẽ trả về là undefined 

// PHương thức bind:
// - Ràng buộc từ khóa this trong hàm, trong phương thức trở thành một đối tượng khác tùy ý dev

// VD về context 
// function foo() {
//     console.log(this);
// }

// foo() // window
// new foo() // foo

// -------------------------------
// VD 1:

// this.firstName = "Minh"
// this.lastName = "Thu"

// const teacher = {
//     firstName: "Minh",
//     lastName: "Thảo",
//     getFullName(){
//         return `${this.firstName} ${this.lastName}`
//     }
// }

// const student = {
//     firstName: "Dũng",
//     lastName: "Lê",
// }
// // kịch bản ban đầu
// console.log(teacher.getFullName()) // Minh Thảo

// // const getTeacherName = teacher.getFullName
// // console.log(getTeacherName) // trả về hàm getFullName
// // console.log(getTeacherName()) // Minh Thu vì hàm getFullName không được gọi thông qua object, nó đc gọi độc lập


// // Kết luận: 
// // 1. Cho dù một method trong đối tượng chúng ta gán method đó với một biến khác và gọi biến đó 
// // không thông qua đối tượng thì this vẫn trỏ về đối tượng window
// // 2. Bản thân từ khóa this nó không phải một biến mang giá trị, nó chỉ là 1 từ khóa tham chiếu tới một đối tượng khác
// // Và tại thời điểm định nghĩa ra phương thức hay hàm thì lúc đó từ khóa this chưa mang giá trị và cũng chưa biết nó trỏ về đâu cả

// // Khi thực thi. gọi method gọi function khi đó tùy vào trường hợp chúng ta thực thi, tùy vào ngữ cảnh lúc đó thì JS sẽ tính toán để tham chiếu
// // đến đúng đối tượng 

// // Vì  vậy nên dùng bind có thể giải quyết vấn đề này

// const getTeacherName = teacher.getFullName.bind(teacher)
// const getTeacherName1 = teacher.getFullName.bind(student)

// // ràng buộc obj teacher này với từ khóa this trong cái hàm này (getFullName)
// // ràng buộc getFullName với đối tượng this là obj teacher
// // console.log(getTeacherName)
// console.log(getTeacherName())
// console.log(getTeacherName1())






// VD 2

// this.firstName = "Minh"
// this.lastName = "Thu"

// const teacher = {
//     firstName: "Minh",
//     lastName: "Thảo",
//     getFullName(data1, data2){
//         console.log(data1, data2)
//         return `${this.firstName} ${this.lastName}`
//     }
// }

// const student = {
//     firstName: "Dũng",
//     lastName: "Lê",
// }
// // kịch bản ban đầu
// // console.log(teacher.getFullName()) // Minh Thảo

// // const getTeacherName = teacher.getFullName.bind(student)
// const getTeacherName = teacher.getFullName.bind(student, 'Test3', 'Test4') // các đối số test3, test 4 sẽ được ưu tiên, lúc này test 1 , test 2 không được thực thi
// // khi cần truyền đối số cố định thì truyền thẳng vào bind (bind đối số)

// console.log(getTeacherName('Test1', 'Test2')) // cần truyền đối số động thì truyền như này và bỏ phần truyền ở bind đi

//VD3: Ví dụ về DOM

// const teacher = {
//     firstName: "Minh",
//     lastName: "Thảo",
//     getFullName(){
//         console.log(`${this.firstName} ${this.lastName}`)
//     }
// }

// const button = document.querySelector('button')
// // Case 1
// // button.onclick = function(){
//     // teacher.getFullName() //gọi qua đối tượng thì luôn chạy đúng
// // }   
// // Case 2

// button.onclick = teacher.getFullName.bind(teacher)

// VD4: 
// const $ = document.querySelector
// const $$ = document.querySelectorAll
// console.log($('#heading')) // Lỗi 
// // Do trong querySelector có sử dụng từ khoá this. Khi sử dụng $ thì gọi phương thức querySelector không thông qua đối tượng nên
// // con trỏ this trỏ về global (window)


// const $ = document.querySelector.bind(document) // ràng buộc từ khóa this trong hàm querySelector với đối tượng document
// const $$ = document.querySelectorAll.bind(document)
// // console.log($)
// console.log($('#heading').innerText)
// console.log($('#heading'))

// VD 5

const $ = document.querySelector.bind(document) // ràng buộc từ khóa this trong hàm querySelector với đối tượng document
const $$ = document.querySelectorAll.bind(document)
// IIFE
const app = (() => {
    const cars = ['BMW']
    const input = $('#input')
    const add = $('#add')
    // console.log(add)
    const root = $('#root')
    // console.log('log1',this)

    return{
        add(car){
            cars.push(car)
        },
        delete(index){
            cars.splice(index, 1)
        },
        render(){
            // sử dụng data-set js để xóa 
            const html = cars.map(function(car, index){
                return `
                        <li>
                            ${car}
                            <span class="delete" data-index="${index}">&times</span>
                        </li>
                        `
            }).join('')
            root.innerHTML = html
        },
        // Các element được thêm vào sau khi add, vì vậy nếu để lắng nghe sự kiện trước khi element đc thêm vào dom thì sẽ ko đc
        // Thông thường viết phần lắng nghe sau phần render. Nếu lắng nghe kiểu cứng là load hết element lên để lắng nghe thì sẽ gặp tình trạng trên
        // nên viết theo kiểu delegate pattern có thể bắt được click thêm vào dom sau khi chương trinhf chạy
        // Lắng nghe ở thẻ cha, thẻ root. Từ thẻ cha đó có thẻ xác định được đối tượng nào được tác động vào, vì luôn nghe ở thẻ cha nên sẽ đầy đủ nhất
        init(){
            // console.log('log2',this)
            add.onclick = () => {
                console.log(this)
                console.log(input.value)
                if (input.value){
                    this.add(input.value)
                    this.render()
                    input.value = null
                    input.focus()
                }
            }
            input.addEventListener("keypress", function(event) {
                // If the user presses the "Enter" key on the keyboard
                if (event.key === "Enter") {
                  // Cancel the default action, if needed
                  event.preventDefault();
                  // Trigger the button element with a click
                  document.getElementById("add").click();
                }
            })
            this.render()
            root.onclick = this.handleDelete.bind(this)

        }, 
        handleDelete(e){
            // console.log(e.target)
            if (e.target.closest('.delete')){
                const index = e.target.dataset.index
                this.delete(index)
                this.render()
            }
        }
    }

})()
// console.log(app)
app.init()





// // Lưu ý: 
// // - Phương thức bind() sẽ trả về một hàm mới với 1 cái this mới . Là vùng nhớ mới đc tạo ra
// // - Có thể nhân các đối số như hàm ban đầu

// Nội dung ví dụ:
// 1. Ví dụ bind document object
// 2. Ví dụ DOM listen events
// 3. Ví dụ kết hợp giữa object methods + DOM listen events

// Tóm tắt: 
// - Phương thức bind() cho phép ràng buộc this cho phương thức (function)
// - Phương thức bind() sẽ trả về một hàm mới với context được bind
// - Hàm được trả về từ bind() vẫn có thể nhận các đối số của hàm gốc