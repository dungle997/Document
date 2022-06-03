
import {useState, memo, useCallback} from 'react'
import Content1 from './Content1'
// 1. memo() -> Higher Order Component (HOC)
// 2. useCallback()
    // - Reference types
    // - React memo()

function Content(){
    const [count, setCount] = useState(0)
   
    // const handleIncrease = () =>{
    //     setCount(prev => prev + 1)
    // }
    // Vấn đề: mỗi lần setCount thì gọi lại component content 1 lần, tạo ra 1 tham chiếu mới của handleIncrease, tham chiếu này đc truyền vào onIncrease
    // memo đón đầu so sánh tham chiếu cũ của handleIncrease và tham chiếu mới, thấy khác nhau nên cho cập nhật lại component con Content1.
    // Mặc dù nội dung code không thay đổi nhưng giá trị tham chiếu của hàm handleIncrease đã thay đổi sau mỗi lần re render
    // Giải pháp sử dụng useCallback
    const handleIncrease = useCallback(()=>{
        setCount(prev => prev + 1)
    }, []) 
    return (
        <div style={{padding: '10px 32px'}}>
            <h1>{count}</h1>
            {/* <Content1 count={count}/> */}
            <Content1 onIncrease={handleIncrease}/>
        </div>
    )
}

// Content1 không sử dụng biên count nên không cần re-render lại
// Nếu Content1 sử dụng count thì nó sẽ được re-render
// Sử dụng toán tử === để check sự thay đổi các biến phụ thuộc trong component Content1





// ====================================
export default Content