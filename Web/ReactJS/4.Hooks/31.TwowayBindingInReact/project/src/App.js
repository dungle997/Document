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
// ========================================VD về input====================================
// function App(){
//   const [name, setName] = useState('') 
//   // console.log('vao ham App')
//   console.log(name)
//   return (
//     <div style = {{padding: '100px'}}>
//       <input 
//         value = {name}
//         onChange = {e => setName(e.target.value)
//       }/>
      
//       <button onClick = { () => setName('Nguyen Van BBB')}>
//         Change
//       </button>
//     </div>
//   )
// }
// ========================================== Radio ============================================
// const courses = [
//   {
//     id: 1,
//     name: 'HTML, CSS'
//   }, 
//   {
//     id: 2,
//     name: 'JavaScript'
//   },
//   {
//     id: 3,
//     name: 'ReactJS'
//   }
// ]

// function App(){
//   const [checked, setChecked] = useState()
//     console.log(checked)

//   const handleSubmit = ()=>{
//     console.log({id : checked})
//   }
//   return (
//     <div style = {{padding: '100px'}}>
//       {
//         courses.map(course =>(
//             <div key={course.id}>
//               <input 
//               checked = {checked === course.id}
//               type='radio'
//               onChange = {()=> setChecked(course.id)}
//               />
//               {course.name}
//             </div>
//           )
//         )
//       }
//       <button onClick = {handleSubmit}>Register</button>
//     </div>
//   )
// }
// ========================================== Check Box ============================================
// const courses = [
//   {
//     id: 1,
//     name: 'HTML, CSS'
//   }, 
//   {
//     id: 2,
//     name: 'JavaScript'
//   },
//   {
//     id: 3,
//     name: 'ReactJS'
//   }
// ]

// function App(){
//   const [checked, setChecked] = useState([])
//     console.log(checked)

//   const handleSubmit = ()=>{
//     console.log({id : checked})
//   }
//   const handleCheck = (id) =>{
//     setChecked(prev => {
//       const isChecked = checked.includes(id)
//       if (isChecked){
//         return checked.filter(item => item !== id)
//       }else{
//         return [...prev, id]
//       }
//     })
//   }
//   return (
//     <div style = {{padding: '100px'}}>
//       {
//         courses.map(course =>(
//             <div key={course.id}>
//               <input 
//               checked = {checked.includes(course.id)}
//               type='checkbox'
//               onChange = {() => handleCheck(course.id)}
//               />
//               {course.name}
//             </div>
//           )
//         )
//       }
//       <button onClick = {handleSubmit}>Register</button>
//     </div>
//   )
// }
// =================================== Practise ======================================

// ==================== VD1: về quay thưởng random===================
// const listGift = [
//   'Mazda CX5',
//   'Mercedes S200',
//   'MayBach',
// ]
// function App(){
//   const [gift, setGift] = useState()

//   function handleClick(){
//     const random = Math.floor(Math.random()*listGift.length)
//     setGift(random)
//   }
//   return (
//     <div style={{padding: 100}}>
//         <h1>{listGift[gift] || 'Chưa có phần thưởng'}</h1>
//         <button onClick={handleClick}>Lấy thưởng</button>
//     </div>
//   )
// }

// ==================== VD2: Lấy thông tin từ các thẻ input và hiển thị lại theo kịch bản( ràng búộc 2 chiều )===================
// function App(){
//   const [name, setName] = useState('')
//   console.log(name)
//   const handleChange = (value) =>{
//     setName(value)
//   }
//   return (
//     <div style={{padding: 100, color: 'red'}}>
//       <h1>{name}</h1>
//       <input 
//         onChange={(e) => handleChange(e.target.value)}
//         value = {name}
//       />
//       <button onClick={()=> setName('Việt Nam Vô Địch!!!!!')}>Change</button>
//     </div>
//   )
// }
// ==================== VD3: Lấy thông tin từ các thẻ radio ( ràng búộc 2 chiều )===================
// const courses = [
//   {
//     id: 1,
//     name: 'HTML, CSS'
//   },
//   {
//     id: 2,
//     name: 'JavaScript cơ bản'
//   },
//   {
//     id: 3,
//     name: 'JavaScript nâng cao'
//   },
//   {
//     id: 4,
//     name: 'React JS'
//   }
// ]

// function App(){
//   const [checked, setChecked] = useState()
//   console.log(checked)

//   const handleChange = (id) => {
//     setChecked(id)
//   }

//   return (
//     <div style={{padding: 50, color: 'blue'}}>
//         {
//           courses.map(course => (
//             <div key={course.id}>
//                 <input 
//                   checked = {checked === course.id} 
//                   type = 'radio'
//                   onChange = {() => handleChange(course.id)}
//                 />{course.name}
                
//             </div>
//           ))
//         }
//         <button>asdfd</button>
//     </div>
   
//   )
// }
// ==================== VD4: Lấy thông tin từ các thẻ chekbox ( ràng búộc 2 chiều )===================
const courses = [
  {
    id: 1,
    name: 'HTML, CSS'
  },
  {
    id: 2,
    name: 'JavaScript cơ bản'
  },
  {
    id: 3,
    name: 'JavaScript nâng cao'
  },
  {
    id: 4,
    name: 'React JS'
  }
]

function App(){
  const [checked, setChecked] = useState([])
  console.log(checked)

  const handleChange = (id) => {
    setChecked(prev => {
      if (prev.includes(id)){
        return checked.filter(value => value !== id)
      }else{
        return [...prev, id]
      }
    })
  }
  const handleOnclick = ()=>{
    console.log({result: checked})
  }

  return (
    <div style={{padding: 50, color: 'blue'}}>
        {
          courses.map(course => (
            <div key={course.id}>
                <input 
                  checked = {checked.includes(course.id)} 
                  type = 'checkbox'
                  onChange = {() => handleChange(course.id)}
                />{course.name}
                
            </div>
          ))
        }
        <button  onClick={handleOnclick} >asdfd</button>
    </div>
   
  )
}



// ========================= export App =========================
export default App;

// ràng buộc 2 chiều với form

// Ràng buộc 1 chiều : React JS
// Ràng buộc 2 chiều : Vue JS