import {SET_JOB, ADD_JOB, DELETE_JOB } from './constant'
// initState
export const initState = {
    job: '',
    jobs: []
}
// reducer
const reducer = (state, action) =>{
    // console.log(action)
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

export default reducer