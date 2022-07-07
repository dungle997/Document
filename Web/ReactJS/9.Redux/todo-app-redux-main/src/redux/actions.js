// action creator
export const addTodo = (data) => {
    return {
        type: 'todoList/addTodo',
        payload: data
    }
}

export const toggleTodoStatus = (id) => {
    return {
        type: 'todoList/toggleTodoStatus',
        payload: id
    }
}

export const searchFilterChange = (text) => {
    return {
        type: 'filter/searchFilterChange',
        payload: text
    }
}

export const statusFilterChange = (status) => {
    // console.log(status)
    return {
        type: 'filter/statusFilterChange',
        payload: status
    }
}

export const prioritiesFilterChange = (priorities) => {
    // console.log(status)
    return {
        type: 'filter/prioritiesFilterChange',
        payload: priorities
    }
}


