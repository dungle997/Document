import { createSelector } from 'reselect'

export const searchTextSelector = (state) => state.filters.search
export const todoListSelector = (state) => state.todoList.todos
export const filterStatusSelector = (state) => state.filters.status
export const filterPrioritiesSelector = (state) => state.filters.priorities


// export const todoListSelector = (state) => {
//     const searchText = searchTextSelector(state)
//     const todosRemaining = state.todoList.filter((todo) => {
//         return todo.name.includes(searchText)
//     })
//     return todosRemaining
// }


// reselect 
// {id: 3, name: 'Learn JavaScript', completed: false, priority: 'Low'},
// export const todosRemainingSelector = createSelector(todoListSelector, filterStatusSelector, searchTextSelector, (todoList, status, searchText) => {
//     console.log(todoList)
//     const abc = todoList.filter(todo => {
//         console.log(todo)
//         console.log('status', status)
//         // return (todo.name.includes(searchText) && (status !== 'All' && status === 'Completed' ?  todo.completed : !todo.completed))
//         const a = (status !== 'All' && status === 'Completed' ?  todo.completed === true : todo.completed === false)  
//         console.log(a)
//         return a 
//     })
//     // console.log(abc)
//     return abc
// })

export const todosRemainingSelector = createSelector(todoListSelector, filterStatusSelector, searchTextSelector, filterPrioritiesSelector, (todoList, status, searchText, priorities) => {
    return todoList.filter(todo => {
        if (status === 'All'){
            return priorities.length ?  todo.name.includes(searchText) && priorities.includes(todo.priority) : todo.name.includes(searchText)
        }
        return (todo.name.includes(searchText) && (status === 'Completed' ?  todo.completed : !todo.completed)) && 
        (priorities.length ? priorities.includes(todo.priority) : true)
    })
})