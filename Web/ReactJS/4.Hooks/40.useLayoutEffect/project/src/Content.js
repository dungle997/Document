
import {useEffect, useLayoutEffect,useState} from 'react'

// sử dụng useEffect để thực hiện Side Effects: thuật ngữ lập trình 

// Events: Add/ remove event listener
// Observer pattern: Subcribe / unsubscribe
// Closure
// Timer: setInterval, setTimeout, clearInterval, clearTimeout
// useState
// Mounted/Unmounted
// toán tử ===
// Call API
/** 
 1. UPdate DOM
     - F8 blog title
    2. Call API
    3. Listen DOM events
        - Scroll
        - Resize
    4. Cleanup
        - Remove Listener / Unsubcribe
        - Clear timer
*/

// 1. useEffect(callback)
// 2. useEffect(callback, [])
// 3. useEffect(callback, [deps])

// -------------------
// 1.Callback luôn được gọi sau khi component mounted 
// - gọi callback mỗi khi component re-render
// - gọi callback sau khi component thêm element vào DOM
// 2. useEffect(callback, []). chỉ gọi callback một lần khi component được mounted
// 3. useEffect(callback, [deps])
// - Callback sẽ được gọi lại mỗi khi deps thay đổi
// -------------------------------------
// 1. Callback luôn được gọi sau khi component mounted. 
// 2. Cleanup function luôn được gọi trước khi component unmounted
// 3. Cleanup function luôn được gọi trước khi callback được gọi (trừ lần mounted)
// -------------------------------------------------------


// ========================= useLayoutEffect ======================
// useEffect
// 1. Cập nhật lại state
// 2. Cập nhật DOM (mutated): đột biến, ví dụ một object sửa 1 property thay đổi => Đây là mutated (Thay đổi 1 property trong 1 Dom node)
// 3. Render lại UI
// 4. Gọi cleanup nếu deps thay đổi
// 5. Gọi useEffect callback

// useLayoutEffect
// 1. Cập nhật lại state
// 2. Cập nhật DOM (mutated)
// 3. Gọi cleanup nếu deps thay đổi (sync)
// 4. Gọi useLayoutEffect callback (sync)
// 5. Render lại UI
function Content(){
    const [count, setCount] = useState(0)

    useLayoutEffect(()=>{
        if (count > 3){
            setCount(0)
        }
    }, [count])

    const handleClick = () => {
        setCount(count + 1)
    }
    return (
        <div>
            <h1>{count}</h1>
            <button
                onClick = {handleClick}
            >
                Click!
            </button>
        </div>
    )
}





// ====================================
export default Content