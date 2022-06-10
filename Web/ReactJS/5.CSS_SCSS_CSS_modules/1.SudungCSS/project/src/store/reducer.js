import {SET_JOB, ADD_JOB, DELETE_JOB} from './constants'

const initState = {
    todos: [],
    todoInput: '',
}

function reducer(state, action){
    // console.log(action)
    switch(action.type){
        case SET_JOB: 
            return {
                ...state,
                todoInput: action.payload
            }
        default: 
            throw new Error('Invalid Method')
    }
}

export {initState}
export default reducer