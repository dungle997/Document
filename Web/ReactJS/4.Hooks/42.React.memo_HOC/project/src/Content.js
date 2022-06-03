
import {useState, memo} from 'react'
import Content1 from './Content1'
// 1. memo() -> Higher Order Component (HOC)
// 2. useCallback()

// Trong React có 3 khái niệm rất hay sử dụng:
// Hook
// HOC - Higher Order Component
// Render props

// Chức năng của memo: 
// - Ghi nhớ lại các props của component để quyết định có re-render lại component đó hay không => Tối ưu hiệu năng
// - Xử lý component để tránh re-render lại trong các tình huống không cần thiết

function Content(){
    const [count, setCount] = useState(0)
   
    const increase = () =>{
        setCount(count +1)
    }
    return (
        <div style={{padding: '10px 32px'}}>
            <h1>{count}</h1>
            {/* <Content1 count={count}/> */}
            <Content1/>
            <button onClick={increase}>Click me!</button>
        </div>
    )
}

// Content1 không sử dụng biên count nên không cần re-render lại
// Nếu Content1 sử dụng count thì nó sẽ được re-render
// Sử dụng toán tử === để check sự thay đổi các biến phụ thuộc trong component Content1





// ====================================
export default Content