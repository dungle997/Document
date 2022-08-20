
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

// VD 1:  Cleanup function luôn được gọi trước khi callback được gọi (trừ lần mounted)
// function Content(){
//     const [count, setCount] = useState(1)

//     // Sử dụng setInterval
//     useEffect(()=>{
//         console.log(`Mounted or Re-render lần ${count}`)
        
//         // Cleanup func 
//         return () => {
//             console.log(`Clean up lần ${count}`)
//         }

//     }, [count])

//     return (
//         <div>
//             <h1>{count}</h1>
//             <button onClick={() => setCount(count +1)}>
//                 Click me!
//             </button>
//         </div>
//     )
// }
//VD 2: 
// function Content(){
//     const [avatar, setAvatar] = useState()
//     console.log('avatar = ',avatar)
//     const handlePreviewAvatar = (e)=>{
//         const file = e.target.files[0]
//         file.preview = URL.createObjectURL(file)
//         // console.log(file)
//         setAvatar(file)
//     }

//     useEffect(()=>{
//         return () => {
//             avatar && URL.revokeObjectURL(avatar.preview)
//             console.log('clear object url')
//         }

//     }, [avatar])
//     return (
//         <div>
//             <input
//                 type='file'
//                 onChange = {handlePreviewAvatar}
//             />
//             <img 
//                 src={avatar && avatar.preview}
//                 alt=""
//                 width="50%"
//             />
//         </div>
//     )
// }
// Lấy ảnh để hiên thị
function Content(){
    const [avatar, setAvatar] = useState()

    const handlePreviewAvatar = (e) => {
        const file = e.target.files[0]
        // console.log(file)
        file.preview = URL.createObjectURL(file)
        setAvatar(file)
    }

    useEffect(()=>{
        return () => {
            URL.revokeObjectURL(avatar && avatar.preview)
        }
    }, [avatar])
    return (
        <div>
            <input 
                type = 'file'
                onChange={handlePreviewAvatar}
            />
            <img 
                alt=""
                width="50%"
                src = {avatar && avatar.preview}
            />
        </div>
    )
}




// ====================================
export default Content