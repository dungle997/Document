// Lưu ý 
// 1. Array
// 2. Reference types

// Ví dụ 
// 1. Random gift
// 2. Two-way Binding: ràng buộc một chiều, ràng buộc 2 chiều
// 3. Todolist

import {useState} from 'react'
// 1. ====================================Random gift============================================
// const gifts = [
//   'CPU i9',
//   'RAM 32GB RGB',
//   'RBG KeyBoard',
// ]
// function App(){
//   const [index, setIndex] = useState('Chưa có phần thưởng') 
  
//   // console.log('vao ham App')
//   function handleClick(){
//     // console.log('index = ',index)
//     setIndex(Math.floor(Math.random()*gifts.length))
//   }
//   return (
//     <div style = {{padding: '100px'}}>
//     <h1>{gifts[index] || index}</h1>
//     <button onClick = {handleClick}>Lấy thưởng</button>
//     </div>
//   )
// }

// ===================================== 2. Two-way Binding: ràng buộc một chiều, ràng buộc 2 chiều ========================================
// VD về input
function App(){
  const [name, setName] = useState('') 
  // console.log('vao ham App')
  console.log(name)
  return (
    <div style = {{padding: '100px'}}>
      <input 
        value = {name}
        onChange = {e => setName(e.target.value)
      }/>
      
      <button onClick = { () => setName('Nguyen Van BBB')}>
        Change
      </button>
    </div>
  )
}





export default App;

// Ràng buộc 1 chiều : React JS
// Ràng buộc 2 chiều : Vue JS