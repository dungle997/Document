// action creator
export const addTodo = (data) => {
    return {
        type: 'todoList/addTodo',
        payload: data
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

export const priorityFilterChange = (priorities) => {
    // console.log(status)
    return {
        type: 'filter/priorityFilterChange',
        payload: priorities
    }
}


