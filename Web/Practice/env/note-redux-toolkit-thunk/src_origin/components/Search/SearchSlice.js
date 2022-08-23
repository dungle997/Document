const initState = {
    search: ''
}
const searchReducer = (state = initState, action) => {
    switch(action.type){
        case'search/searchFilterData':
            return {
                ...state,
                search: action.payload
            }
        default: 
            return state
    }

}

export default searchReducer