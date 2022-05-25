import {useState} from 'react'
// ===========================// - Set state với callback? ========================
// function App() {
//   const [counter, setCounter] = useState(1) 
//   destructuring trong ES6, counter và setCounter
//   const handleIncrease = () => {
//     // ra cùng result do counter vẫn là 1 giá trị
//     // setCounter(counter + 1)
//     // setCounter(counter + 1)
//     // setCounter(counter + 1)
//     // ra két quả khác nhau
//     setCounter(prev => prev + 1)
//     setCounter(prev => prev + 1)
//     // Lúc đầu thì counter  = 1. 
//     // Nếu truyền cho setCounter một callback với 1 đối số thì đối số đó sẽ là giá trị của counter trong lần đầu lúc đó counter = 1. 
//     // Khi sử dụng nhiều hàm setCounter cùng một lúc thì nó sẽ nhận giá trị đối số trước đó của hàm setCounter làm giá trị cho tham số của hàm setCounter

//     // -------------------------
//     // useState(initial state)
//     // initial state nhận bất kì giá trị hợp lệ nào trong JS
//     // Lưu ý trường hợp truyền hàm vào thì nó sẽ nhận cái giá trị mà hàm đó trả về làm initState
//   }
//   console.log("code ")
//   return (
//     <div className="App" style = {{padding: '20px'}}>
//         <h1>{counter}</h1>
//         <button onClick = {handleIncrease}>Increase</button>
//     </div>
//   )
// }


// =====================================   - Initial state với callback? ==================

// đề bài 
// const orders = [100, 200, 300]

// function App() {
//   const total = orders.reduce((total, cur)=> total + cur)
//   console.log(total) // total luôn được tính toán khi click => App được gọi lại => logic nặng nề, chỉ cần tính total trong lần đầu tiên 
//   // => truyền callback vào useState
//   const [counter, setCounter] = useState(total) // chỉ nhận giá trị initState 1 lần đầu tiên, các lần sau dùng gía trị của hàm setState 
//   const handleIncrease = () => {
//     setCounter(prev => prev + 1)
//     // console.log("counter ",counter)
//     // -------------------------
//     // useState(initial state)
//     // initial state nhận bất kì giá trị hợp lệ nào trong JS
//     // Lưu ý trường hợp truyền hàm vào thì nó sẽ nhận cái giá trị mà hàm đó trả về làm initState
//     // Mỗi lần click vào button thì lại render lại App component
//   }
//   console.log("code ")
//   console.log("counter ",counter) // ra khỏi hàm handleIncrease thì sẽ cho giá trị trả về của setCounter = counter
//   return (
//     <div className="App" style = {{padding: '100px'}}>
//         <h1>{counter}</h1>
//         <button onClick = {handleIncrease}>Increase</button>
//     </div>
//   )
// }
// cách xử lí 
// const orders = [100, 200, 300]

// function App() {
//   // => truyền callback vào useState
//   const [counter, setCounter] = useState(()=>{
//     const total = orders.reduce((total, cur)=> total + cur)
//     console.log(total) // total luôn được tính toán khi click => App được gọi lại => logic nặng nề, chỉ cần tính total trong lần đầu tiên 
//     return total
//   }) // chỉ nhận giá trị initState 1 lần đầu tiên, các lần sau dùng gía trị của hàm setState 
//   const handleIncrease = () => {
//     setCounter(prev => prev + 1)
//     // console.log("counter ",counter)
//     // -------------------------
//     // useState(initial state)
//     // initial state nhận bất kì giá trị hợp lệ nào trong JS
//     // Lưu ý trường hợp truyền hàm vào thì nó sẽ nhận cái giá trị mà hàm đó trả về làm initState
//     // Mỗi lần click vào button thì lại render lại App component
//   }
//   console.log("code ")
//   // console.log("counter ",counter) // ra khỏi hàm handleIncrease thì sẽ cho giá trị trả về của setCounter = counter
//   return (
//     <div className="App" style = {{padding: '100px'}}>
//         <h1>{counter}</h1>
//         <button onClick = {handleIncrease}>Increase</button>
//     </div>
//   )
// }

// ============================- Set state là thay thế state bằng giá trị mới =====================
// VD 1
// const orders = [100, 200, 300]

// function App() {
//   // => truyền callback vào useState
//   const [counter, setCounter] = useState(()=>{
//     const total = orders.reduce((total, cur)=> total + cur)
//     console.log(total) // total luôn được tính toán khi click => App được gọi lại => logic nặng nề, chỉ cần tính total trong lần đầu tiên 
//     return total
//   }) // chỉ nhận giá trị initState 1 lần đầu tiên, các lần sau dùng gía trị của hàm setState 
//   const handleIncrease = () => {
//     setCounter(prev => prev + 1)
//     // console.log("counter ",counter)
//     // -------------------------
//     // useState(initial state)
//     // initial state nhận bất kì giá trị hợp lệ nào trong JS
//     // Lưu ý trường hợp truyền hàm vào thì nó sẽ nhận cái giá trị mà hàm đó trả về làm initState
//     // Mỗi lần click vào button thì lại render lại App component
//   }
//   console.log("code ")
//   // console.log("counter ",counter) // ra khỏi hàm handleIncrease hay là sau khi gọi hàm setCounter thì nó sẽ 
//   // cho giá trị trả về của setCounter = counter
//   return (
//     <div className="App" style = {{padding: '100px'}}>
//         <h1>{counter}</h1>
//         <button onClick = {handleIncrease}>Increase</button>
//     </div>
//   )
// }

// VD 2
function App(){
  const [info, setInfo] = useState({
      name: "Nguyễn Quang Vương",
      age: 18,
      address: 'VN, Hanoi'
  })
  const handleUpdate = () => {
      setInfo({
        ...info,
        bio: 'Yêu em hàng xóm'
      }
      )
  }
  return (
    <div className="App" style = {{padding: '100px'}}>
    <h1>{JSON.stringify(info)}</h1>
    <button onClick = {handleUpdate}>Update</button>
</div>
  )
}
export default App;



// ### Lưu ý

// import {useState} from 'react'

// function Component(){
//     const [state, setState] = useState(initState)


// - Component được re-render sau khi `setState` => dòng log "code " được in ra 2 lần . Khi gọi setState thì nó gọi lại hàm App, từ lần thứ 2 trở đi là 
// không lấy giá trị khởi tạo nữa
// - Initial state chỉ dùng cho lần đầu 
// - Set state với callback?
// - Initial state với callback?
// - Set state là thay thế state bằng giá trị mới 