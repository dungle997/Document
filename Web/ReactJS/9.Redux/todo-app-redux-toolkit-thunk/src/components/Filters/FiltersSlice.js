// const initState = {
//         search: '',
//         status: 'All',
//         priorities: []
// }

// const filtersReducer = (state = initState, action) =>{
//     // console.log(action)
//     switch(action.type){
//         case 'filter/searchFilterChange':
//             return {
//                 ...state, 
//                 search: action.payload
//             }

//         case 'filter/statusFilterChange':
//             // console.log(action.payload)
//             return {
//                 ...state, 
//                 status: action.payload
//             }

//         case 'filter/prioritiesFilterChange':
//             // console.log('action.payload')
//             return {
//                 ...state, 
//                 priorities: action.payload
//             }
//         default: 
//             return state
//     }
// }


// export default filtersReducer

import { createSlice } from '@reduxjs/toolkit'

export default createSlice({
    name: 'filters', 
    initialState: {
        search: '',
        status: 'All',
        priorities: [],
    },
    reducers: {
        searchFilterChange: (state, action) =>{
            // mutation || Viết kiểu mutation nhưng thật chất là immutation thông qua thư viện IMMER
            state.search = action.payload
        }, // => {type: 'filters/searchFilterChange'}
        statusFilterChange: (state, action) =>{
            state.status = action.payload
        }, 
        prioritiesFilterChange: (state, action) =>{
            state.priorities = action.payload
        }, 
        
    }
})



// createSlice tạo các action function luôn, không cần file action nữa => quản lý phi tập trung 