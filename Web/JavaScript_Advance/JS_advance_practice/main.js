import html from './core.js'

// // -------------------------------------------- Đề bài ban đầu
// const cars = ['BMW', 'Porche', 'Honda']

// // const isSuccess = true
// const isSuccess = false // Khi bằng false thì h1 in ra false luôn => ko mong muốn => tạo file core.js để xử lí

// //  <h1>${false}</h1> thì kết quả là  <h1>false</h1> không mong muốn như vậy, cần <h1></h1>


// const output = html`
//     <h1>${isSuccess && 'Thành Công'}</h1>
//     <h1>${0}</h1>

//     <ul>
//         ${cars.map(car => `<li>${car}</li>`)} 
//     </ul>
// `
// // Không nên viết như này vì join bị lặp lại rất nhiều vì mình phải dùng rất nhiều mảng 

// console.log(output)
// --------------------------------------------------
import App from './component/App.js'
import { attach } from './store.js'

attach(App, document.getElementById('root'))