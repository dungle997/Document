const initState = {
    search: ''
}
const searchReducer = (state = initState, action) => {
    switch(action.type){
        case'search/searchFilterData' :
            return {
                ...initState,
                search: action.payload
            } 
    }
}

export default searchReducer