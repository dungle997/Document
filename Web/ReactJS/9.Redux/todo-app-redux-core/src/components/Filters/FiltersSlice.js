const initState = {
        search: '',
        status: 'All',
        priorities: []
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

        case 'filter/prioritiesFilterChange':
            // console.log('action.payload')
            return {
                ...state, 
                priorities: action.payload
            }
        default: 
            return state
    }
}


export default filtersReducer