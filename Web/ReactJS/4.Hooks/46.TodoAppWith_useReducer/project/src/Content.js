
import {useState, useReducer, useRef} from 'react'

// useReducer 
// 1. Init state: 0
// 2. Actions: Up (state +1) / Down (state -1)
// 3. Reducer
// 4. Dispatch

// Init state
const initState = {
    job: '',
    jobs: []
}


// Actions
const SET_JOB = 'set_job'
const ADD_JOB = 'add_job'
const DELETE_JOB = 'delete_job'
 
// Reducer
const reducer = (state, action) =>{
    console.log(action)
    switch(action.type){
        case SET_JOB:
            return {
                ...state,
                job: action.payload
            }
        case ADD_JOB: 
            return {
                ...state,
                jobs: [...state.jobs, action.payload]
            }

        case DELETE_JOB:
            // return {
            //     ...state,
            //     jobs: state.jobs.splice(action.payload, 1)
            // }

            // CHú ý: nên tránh xóa trực tiếp mảng như trên, nên tạo 1 mảng trung gian rồi mới gán lại

            const newJob = [...state.jobs]
            newJob.splice(action.payload, 1)
            return {
                ...state,
                jobs: newJob
            }
        default: 
            throw new Error('Invalid Method')
        
    }
}

const setJob = payload =>{
    return {
        type: SET_JOB,
        payload
    }
}

const addJob = payload =>{
    return {
        type: ADD_JOB,
        payload
    }
}

const deleteJob = payload =>{
    return {
        type: DELETE_JOB,
        payload
    }
}


function Content(){
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
export default Content

// useReducer và useState dùng giống nhau
// - useState phù hợp với những component có state đơn giản: số, chuỗi, boolean, array object 1 cấp
// - useReducer phù hợp với những component có state phức tạp: array object có nhiều tầng nhiều cấp hoặc khi có nhiều state
