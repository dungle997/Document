
import {useRef,useState, useEffect} from 'react'
// Lưu các giá trị qua một tham chiếu bên ngoài
// function component
//3. Callback useEffect (kể cả dependencies)luôn được gọi 1 lần sau khi component được mount 

function Content(){
    const [count, setCount] = useState(60)
    const timerId = useRef(99)
    const preCount = useRef()
    const h1Ref = useRef() // tương tự getElementById hay querySelector
    // console.log(timerId)
    // Lưu giá trị trước đó 
    useEffect(()=>{
        preCount.current = count
    }, [count])

    useEffect(()=>{
        console.log(h1Ref.current)
        console.log(h1Ref.current.getBoundingClientRect())
    })



    const handleStop = () =>{
        clearInterval(timerId.current)
        console.log('Stop ', timerId.current)

    }

    const handleStart = () =>{
        
        timerId.current = setInterval(() => {
            setCount(prev => prev - 1)
        }, 1000)
        console.log('Start ', timerId.current)
    }
    console.log(count, preCount)
    return (
        <div>
            <h1 ref={h1Ref}>{count}</h1>
            <button
                onClick={handleStart}
            >
                Start
            </button>
            <button
                onClick={handleStop}
            >
                Stop
            </button>
        </div>
    )
}





// ====================================
export default Content