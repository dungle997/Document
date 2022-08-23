import {createSlice} from '@reduxjs/toolkit'
export default createSlice({
    // switch(action.type){
    //     case 'search/addSearch':
    //         return {...state, search: action.payload}
    //     default: 
    //         return state
    // }

    name: 'search',
    initialState: {
        search: '',
    },
    reducers: {
        addSearch: (state, action) => {
            state.search = action.payload
        }
    }
})
