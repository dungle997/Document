
import {useEffect, useState} from 'react'

// Side Effects: thuật ngữ lập trình 

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


// VD1: Lỗi setStatus khi setInterval luôn sử dụng biến countDown = 180, ở thờ điểm useEffect đc chạy nó luôn tham chiếu đến countDown ở ngoài, = 180
// function Content(){
//     const [countDown, setCountDown] = useState(180)

//     useEffect(()=>{
//         setInterval(()=>{
//             setCountDown(countDown - 1)  // hàm setStatus này phải nhận giá trị mới thì mới render lại dự liệu
//             console.log('Countdown: ', countDown)
//         }, 1000)
//     }, [])
    


//     return (
//         <div>
//             <h1>{countDown}</h1>
//             {console.log('render count down', countDown)}
//         </div>
//     )
// }

// VD2 : Giải pháp 

function Content(){
    const [countDown, setCountDown] = useState(180)

    // Sử dụng setInterval
    useEffect(()=>{
        const timerId = setInterval(()=>{
            setCountDown(prev => prev - 1)  // hàm setStatus này phải nhận giá trị mới thì mới render lại dự liệu
            // setCountDown(countDown -1) // luôn trả về 180, do hàm setInterval thực thi lúc đó tham chiếu đến countDown = 180  
            console.log('Countdown ....')
        }, 1000)
        return () => clearInterval(timerId)

    }, [])
    // Sử dụng setTimeout
    // useEffect(()=>{
    //     setTimeout(()=>{
    //         // setCountDown(prev => prev - 1)  // hàm setStatus này phải nhận giá trị mới thì mới render lại dự liệu
    //         setCountDown(countDown -1) // luôn trả về 180, do hàm setInterval thực thi lúc đó tham chiếu đến countDown = 180  
    //         // console.log('Countdown: ', prev)
    //     }, 1000)
    // }, [countDown])


    return (
        <div>
            <h1>{countDown}</h1>
            {/* {console.log('render count down', countDown)} */}
        </div>
    )
}




// ====================================
export default Content