import { combineReducers } from 'redux'

import filtersReducer from '../../src/components/Filters/FiltersSlice'
import todoListReducer from '../../src/components/TodoList/TodosSlice'

// Nguyên bản 
// const rootReducer = (state = {}, action) =>{
    //    return {
//        filters: filtersReducer(state.filters, action),
//        todoList: todoListReducer(state.todoList, action),
//    }
// }

    // sử dụng combine
    const rootReducer = combineReducers({
        filters: filtersReducer,
        todoList: todoListReducer,
    })



export default rootReducer