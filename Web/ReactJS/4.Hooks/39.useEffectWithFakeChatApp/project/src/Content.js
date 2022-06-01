
import {useEffect, useState} from 'react'

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

function Content(){
    const [id, setId] = useState()
    const courses = [
        {
            id: 1,
            title: "Toán Cao Cấp"
        },
        {
            id: 2,
            title: "Hình Học Họa Hình"
        },
        {
            id: 3,
            title: "Lâp trình CAD/CAM"
        }
    ]
    return (
        <div>
            <ul>
                {courses.map(course => (
                    <li 
                        key={course.id}
                        style = {id === course.id ? {color: 'red', backgroundColor: '#fff'} : {}}
                        onClick ={()=> {
                            // console.log(course.id)
                            setId(course.id)
                        }}
                    >
                        {course.title}
                    </li>
                ))}
            </ul>
        </div>
    )
}





// ====================================
export default Content