
import {useRef,useState} from 'react'
// Lưu các giá trị qua một tham chiếu bên ngoài
// function component

function Content(){
    const [count, setCount] = useState(60)
    let timerId = useRef(99)
    console.log(timerId)

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
    return (
        <div>
            <h1>{count}</h1>
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