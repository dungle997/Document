const initState = {
        search: '',
        status: 'All',
        priority: []
}

const filtersReducer = (state = initState, action) =>{
    // console.log(action)
    switch(action.type){
        case 'filter/searchFilterChange':
            return {
                ...state, 
                search: action.payload
            }

        case 'filter/statusFilterChange':
            // console.log(action.payload)
            return {
                ...state, 
                status: action.payload
            }
        default: 
            return state
    }
}


export default filtersReducer