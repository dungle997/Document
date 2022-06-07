// Lưu ý 
// 1. Array
// 2. Reference types

// Ví dụ 
// 1. Random gift
// 2. Two-way Binding: ràng buộc một chiều, ràng buộc 2 chiều
// 3. Todolist
import Content from './Content'
import {useState} from 'react'


function App(){
  const [state, setState] = useState(false)

  return (
    <div style = {{padding: 50}}>
        <button onClick={()=>setState(!state)}>Toggle</button>
        { state && <Content />}
    </div>
  )
}


// ========================= export App =========================
export default App;

