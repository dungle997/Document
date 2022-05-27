// Lưu ý 
// 1. Array
// 2. Reference types

// Ví dụ 
// 1. Random gift
// 2. Two-way Binding: ràng buộc một chiều, ràng buộc 2 chiều
// 3. Todolist

import {useState} from 'react'
// Ví dụ gốc
// function App(){
  
//   // console.log(storage)
//   const [input, setInput] = useState('')
//   const [values, setValue] = useState(()=>{
//     let storage = JSON.parse(localStorage.getItem('checkList'))
//     storage = storage ? storage : []
//     return storage
//   })
//   // console.log(input)
//   // console.log(values)


//   const handleChange = (inputValue) => {
//       setInput(inputValue)  

//   }

//   const handleClick = () => {
//       setValue(prev => {
//         let newValue = [...prev, input]
//         const json = JSON.stringify(newValue)
//         localStorage.setItem('checkList', json)
//         return newValue
//       })
//       setInput('')


//   }
//   return (
//     <div style = {{padding: 100}}>
//       <input
//         value = {input}
//         onChange={(e) => handleChange(e.target.value)} 
//       />
//       <button onClick = {handleClick}>Add</button>
//       <ul>
//             {values.map((value, index) => (
//               <li key={index}>{value}</li>
//             ))}
//       </ul>
//     </div>
//   )
// }



// ===================== Luyện tâp =============================

function App(){
  const [input, setInput] = useState('')
  const [values, setValue] = useState(() =>{
    let initValue = JSON.parse(localStorage.getItem('store'))
    initValue = initValue ? initValue : []
    return initValue
  })
  console.log(input)
  const handleChange = (inputValue) =>{
    setInput(inputValue)
  }

  const handleClick = () =>{
    setValue(prev => {
      const json = JSON.stringify([...prev, input])
      localStorage.setItem('store', json)
      return [...prev, input]
    })
    setInput('')
  }

  return (
    <div style = {{padding: 50}}>
      <input
        value = {input} 
        onChange={e => handleChange(e.target.value)}
      />
      <button onClick={handleClick}>Add</button>
      <ul>
        {values.map((value, index)=>(
          <li key={index}>{value}</li>
        ))}  
      </ul>
    </div>
  )
}


// ========================= export App =========================
export default App;

// ràng buộc 2 chiều với form

// Ràng buộc 1 chiều : React JS
// Ràng buộc 2 chiều : Vue JS