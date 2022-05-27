
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
function Content(){
    const [title, setTitle] = useState('')

    useEffect(()=>{
        // console.log('mounted')
        document.title = title

        // Sử dụng callAPI
        fetch('https://jsonplaceholder.typicode.com/posts')
            .then(res => res.json())
            .then(posts => {
            
            })
    })

    return (
        <div>
            <input
                value = {title} 
                onChange={e=> setTitle(e.target.value)}
            />
            {console.log('rendered')}
        </div>
    )
}

export default Content