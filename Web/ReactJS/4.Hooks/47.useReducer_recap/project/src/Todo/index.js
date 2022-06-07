import {useState, useReducer, useRef} from 'react'
import reducer, {initState} from './reducer'
import {setJob, addJob, deleteJob} from './actions'
// useReducer 
// 1. Init state: 0
// 2. Actions: Up (state +1) / Down (state -1)
// 3. Reducer
// 4. Dispatch

function TodoApp(){
    const [state, dispatch] = useReducer(reducer, initState)
    const {job, jobs} = state
    const inputRef = useRef()
    console.log(state)
    const handleSubmit = () => {
        dispatch(addJob(job))
        dispatch(setJob(''))
        inputRef.current.focus()
    }
    const handleDelete = index =>{
        dispatch(deleteJob(index))
    }
    return (
        <div style={{padding: '10px 32px'}}>
            <h1>Todo</h1>
            <input
                ref ={inputRef}
                value = {job}
                placeholder = "Enter todo ..."
                onChange={e =>{
                    dispatch(setJob(e.target.value)) // trả về cho action trong hàm reducer
                }}
            />
            <button
                onClick = {handleSubmit}
            >
                Add
            </button>           
            <ul>
                {jobs && jobs.map((job, index)=>(
                    <li key={index}>{job} 
                        <span onClick={() => handleDelete(index)}>&times;</span>                    
                    </li>)
                )}
            </ul>
        </div>
    )
}

// ====================================
export default TodoApp

// useReducer và useState dùng giống nhau
// - useState phù hợp với những component có state đơn giản: số, chuỗi, boolean, array object 1 cấp
// - useReducer phù hợp với những component có state phức tạp: array object có nhiều tầng nhiều cấp hoặc khi có nhiều state
