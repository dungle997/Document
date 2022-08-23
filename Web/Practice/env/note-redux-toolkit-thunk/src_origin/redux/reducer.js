import {combineReducers} from 'redux'
import noteListReducer from '../components/Note/NoteListSlice'
import searchReducer from '../components/Search/SearchSlice'

const rootReducer = combineReducers({
    search: searchReducer,
    noteList: noteListReducer,
})

export default rootReducer