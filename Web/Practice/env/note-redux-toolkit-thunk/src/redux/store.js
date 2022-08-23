// import {createStore} from 'redux'
// import rootReducer from './reducer'
// import {composeWithDevTools} from 'redux-devtools-extension'

// const composedEnhancers = composeWithDevTools()
// const store = createStore(rootReducer, composedEnhancers)
// export default store

import {configureStore} from '@reduxjs/toolkit'
import  searchSlice from '../components/Search/SearchSlice'
import noteListSlice from '../components/Note/NoteListSlice'
const store = configureStore({
    reducer: {
        search: searchSlice.reducer,
        noteList: noteListSlice.reducer
    }    
})

export default store
