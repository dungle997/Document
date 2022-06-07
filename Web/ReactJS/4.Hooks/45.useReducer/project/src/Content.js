
import {useState, useReducer, useRef} from 'react'

// useState 
// 1. Init state: 0
// 2. Actions: Up (state +1) / Down (state -1)

// useReducer 
// 1. Init state: 0
// 2. Actions: Up (state +1) / Down (state -1)
// 3. Reducer
// 4. Dispatch

// Init state
const initState = 0

// kiểu dữ liệu của initState phải cùng với kiểu dữ liệu được return trong các action case (state + 1)

// Actions
const UP_ACTION = 'up'
const DOWN_ACTION = 'down'

// Reducer
const reducer = (state, action) => {
    console.log('reducer running....')
    switch(action){
        case UP_ACTION:
            return state + 1
        case DOWN_ACTION:
            return state - 1
        default:
            throw new Error('Invalid action') 
    }
}

function Content(){
    const [count, dispatch] = useReducer(reducer, initState)
      
    return (
        <div style={{padding: '10px 32px'}}>
            <h1>{count}</h1>
            <button
                onClick = {()=> dispatch(DOWN_ACTION)}
            >
                Down
            </button>

            <button
                onClick = {()=> dispatch(UP_ACTION)}
            >
                Up
            </button>
           
        </div>
    )
}

// ====================================
export default Content

// useReducer và useState dùng giống nhau
// - useState phù hợp với những component có state đơn giản: số, chuỗi, boolean, array object 1 cấp
// - useReducer phù hợp với những component có state phức tạp: array object có nhiều tầng nhiều cấp hoặc khi có nhiều state
