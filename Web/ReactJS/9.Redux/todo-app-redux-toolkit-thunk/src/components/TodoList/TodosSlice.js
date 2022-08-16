// const initState = [
//         {id: 1, name: 'Learn Yoga', completed: false, priority: 'Medium'},
//         {id: 2, name: 'Learn Redux', completed: true, priority: 'High'},
//         {id: 3, name: 'Learn JavaScript', completed: false, priority: 'Low'},
// ]


// const todoListReducer = (state = initState, action) =>{

//     switch(action.type){
//         case 'todoList/addTodo':
//             return [...state, action.payload]
//         case 'todoList/toggleTodoStatus': 
//             return state.map(todo => 
//                 todo.id === action.payload ? {...todo ,completed : !todo.completed} : todo)
//         default: 
//             return state
//     }
// }


// export default todoListReducer

import {createSlice, createAsyncThunk} from '@reduxjs/toolkit'

const todosSlice =  createSlice({
    name: 'todoList',
    initialState: {status: 'idle', todos: []},
    reducers: {
        addTodo: (state, action) => {
            state.push(action.payload)
        }, // tạo ra 1 action creator
        toggleTodoStatus: (state, action) => {
            const currentTodo = state.find(todo => todo.id === action.payload)
            if (currentTodo){
                currentTodo.completed = !currentTodo.completed
            }
        },
    },
    extraReducers: builder => {
        builder.addCase(fetchTodos.pending, (state, action)=> {
            state.status = 'loading'
        })
        .addCase(fetchTodos.fulfilled, (state, action) => {
            // console.log({action})
            state.todos = action.payload
            state.status = 'idle'
        })
        .addCase(addNewTodo.fulfilled, (state, action) => {
            state.todos.push(action.payload)
        })
    }
})
// thunk action to fetch to server
export const fetchTodos = createAsyncThunk('todos/fetchTodos', async () => {
    const res = await fetch('/api/todos')
    const data = await res.json()
    console.log(data)
    return data.todos
})
// thunk action to add new todo
export const addNewTodo = createAsyncThunk('todos/addNewTodo', async(newTodo) => {
    const res = await fetch('/api/todos', {
        method: 'POST',
        body: JSON.stringify(newTodo)
    })
    // console.log({res})
    const data = await res.json()
    // console.log(data)
    return data.todos
})

// thunk action to add new status todo

export const updateTodo = createAsyncThunk('todos/updateTodo', async (updatedTodo) => {

})

// createAsyncThunk tạo ra 3 cái action như sau: 
/* 
    => todos/fetchTodos/pending 
    => todos/fetchTodos/fullfilled
    => todos/fetchTodos/rejected
*/
export default todosSlice
// test redux thunk
// action va action creators () => {return action} (object)
// thunk action (function) va thunk action creators (function) => {return thunk action}

// export function addTodos(todo) { // thunk function - thunk action
//     return function addTodosThunk(dispatch, getState){
//         console.log('[addTodosThunk]', getState())
//         console.log({todo})
//         // custom payload
//         todo.name = 'Test Updated'
//         dispatch(todosSlice.actions.addTodo(todo))

//         console.log('[addTodosThunk after]', getState())
//     }
// }
